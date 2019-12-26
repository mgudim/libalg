#include "GraphTraversal/DFS.h"
#include "GraphTraversal/GraphTraversal.h"
#include "Graph/DGRAL.h"
#include "Stack/SDLL.h"
#include "Hashing/CHT.h"
#include "LinkedList/DLL.h"
#include "LinkedList/LL.h"


typedef struct VertexIterPair {
    DGRALNode* vertex;
    DGRALNeighboursIterator* iter;
} VertexIterPair;


void dfsC(
    DFS* self,
    SDLL* stack,
    CHT* nodeToStatusMap,
    char* memBuffer
) {
    self->stack = stack;
    self->nodeToStatusMap = nodeToStatusMap;
    self->freeMemStart = memBuffer;
    return;
}


static void dfsPushNewVertex(DFS* self, DGRALNode* vertex) {
    DGRALNeighboursIterator* iter = (DGRALNeighboursIterator*) self->freeMemStart;
    self->freeMemStart += sizeof(DGRALNeighboursIterator);
    dgralGetSuccessorsIterator(vertex, iter);

    VertexIterPair* vertexIterPair = (VertexIterPair*) self->freeMemStart;
    self->freeMemStart += sizeof(VertexIterPair);
    vertexIterPair->vertex = vertex;
    vertexIterPair->iter = iter;

    DLLNode* dllNode = (DLLNode*) self->freeMemStart;
    self->freeMemStart += sizeof(DLLNode);
    dllNode->data = (void*) vertexIterPair;
    sdllPush(self->stack, dllNode);

    KVPair* kv = (KVPair*) self->freeMemStart;
    self->freeMemStart += sizeof(KVPair);
    kv->key = (int) vertex;
    kv->value = (void*) DISCOVERED;
    LLNode* kvPairNode = (LLNode*) self->freeMemStart;
    self->freeMemStart += sizeof(LLNode);
    kvPairNode->data = (void*) kv;
    chtInsert(self->nodeToStatusMap, kvPairNode);
    return;
}


void dfsInit(DFS* self, DGRALNode* startVertex) {
    self->done = 0;
    dfsPushNewVertex(self, startVertex);
    return;
}


void dfsMakeStep(DFS* self, StepResult* stepResult) {
    if (self->done == 1) {
        return;
    }
    VertexIterPair* vertexIterPair = (VertexIterPair*) (
        sdllPeek(self->stack)->data
    );
    DGRALNeighboursIterator* iter = vertexIterPair->iter;
    DGRALNode* vertex = vertexIterPair->vertex;
    DGRALNode* next = dgralGetNextNeighbour(iter);
    stepResult->from = vertex;
    stepResult->fromStatus = DISCOVERED;
    stepResult->to = next;
    if (next == NULL) {
        sdllPop(self->stack);
        (
            ((KVPair*)(chtFind(self->nodeToStatusMap, (int) vertex)->data))
            ->value
        ) = (void*) FINISHED;
        stepResult->fromStatus = FINISHED;
        stepResult->to = NULL;
        stepResult->toStatus = INVALID;
        if (sdllIsEmpty(self->stack)) {
            self->done = 1;
        }
        return;
    }
    LLNode* found = chtFind(self->nodeToStatusMap, (int) next);
    if (found == NULL) {
        stepResult->toStatus = UNDISCOVERED;
        dfsPushNewVertex(self, next);
        return;
    }
    stepResult->toStatus = (VertexStatus) (((KVPair*)(found->data))->value);
    return;
}
