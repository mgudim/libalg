#include "Sorting/InsertionSort.h"
#include "Utils/Comparisons.h"


inline static void swap(void** arr, unsigned i, unsigned j) {
    void* tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
    return;
}


void insertionSort(void** arr, unsigned size, ComparisonFunction compFn) {
    if (size < 2) {
        return;
    }
    for (unsigned i = 0; i < size; ++i) {
        for (unsigned j = i; j > 0; --j) {
            if (!isLessEqInts(arr[j - 1], arr[j])) {
                swap(arr, j, j - 1);
            }
            else {
                break;
            }
        }
    }
    return;
}
