extern "C" {
    #include "Sorting/InsertionSort.h"
    #include "Utils/Comparisons.h"
}
#include "SortingTest.h"


static const std::vector<SortingTestData> sortingTestsData = {
    #include "sortingTestsData.inc"
};
static const std::vector<SortingFunction> sortFns = {
    &insertionSort
};


bool SortingTest::isSorted(
    void** arr,
    unsigned size,
    ComparisonFunction compFn
) const {
    if (size < 2) {
        return true;
    }
    for (unsigned i = 1; i < size; ++i) {
        if (!compFn(arr[i - 1], arr[i])) {
            return false;
        }
    }
    return true;
}


TEST_P(SortingTest, t0) {
    std::tuple<SortingTestData, SortingFunction> testParam = GetParam();
    SortingTestData testData = std::get<0>(testParam);
    unsigned size = testData.vec.size();
    void* arr[size];
    for (unsigned i = 0; i < size; ++i) {
        arr[i] = testData.vec[i];
    }
    ComparisonFunction compFn = testData.compFn;
    SortingFunction sortFn = std::get<1>(testParam);
    sortFn(arr, size, compFn);
    ASSERT_TRUE(isSorted(arr, size, compFn));
}


INSTANTIATE_TEST_CASE_P(
    SortingTests,
    SortingTest,
    ::testing::Combine(
        ::testing::ValuesIn(sortingTestsData),
        ::testing::ValuesIn(sortFns)
    )
);
