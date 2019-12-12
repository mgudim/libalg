#ifndef SORTING_TEST_H
#define SORTING_TEST_H


extern "C" {
    #include "Sorting/Sorting.h"
    #include "Utils/Comparisons.h"
}
#include "gtest/gtest.h"
#include <vector>
#include <tuple>


struct SortingTestData {
    std::vector<void*> vec;
    ComparisonFunction compFn;
};

class SortingTest :
public ::testing::TestWithParam<std::tuple<SortingTestData, SortingFunction>> {
protected:
    bool isSorted(
        void** arr,
        unsigned size,
        ComparisonFunction compFn
    ) const;
};


#endif
