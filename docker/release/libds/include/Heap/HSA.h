#ifndef HSA_INC
#define HSA_INC
#include "Utils/Utils.h"


typedef struct HSA {
    void** _arr;
    unsigned _size;
    ComparisonFunction _compareFn;
} HSA;


void hsaC(
    HSA* self,
    void** arr,
    unsigned size,
    ComparisonFunction compareFn
);
void* hsaPeek(const HSA* self);
void hsaLower(HSA* self, unsigned index, void* newVal);
void hsaRaise(HSA* self, unsigned index, void* newVal);


#endif
