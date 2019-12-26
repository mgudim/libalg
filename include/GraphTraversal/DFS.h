#ifndef DFS_H
#define DFS_H
#include "Stack/SDLL.h"
#include "Hashing/CHT.h"
#include "LinkedList/DLL.h"
#include "GraphTraversal/GraphTraversal.h"


typedef struct DFS {
    SDLL* stack;
    CHT* nodeToStatusMap;
    int done;
    char* freeMemStart;
} DFS;


void dfsC(
    DFS* self,
    SDLL* stack,
    CHT* nodeToStatusMap,
    char* memBuffer
);
void dfsInit(DFS* self, DGRALNode* startVertex);
void dfsMakeStep(DFS* self, StepResult* stepResult);


#endif
