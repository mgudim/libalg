#ifndef UTILS_INC
#define UTILS_INC


typedef int (*ComparisonFunction)(void*, void*);
int compareInts(void* a, void* b);
typedef void (*PrintFunction)(void*);
void printInt(void* a);


#endif
