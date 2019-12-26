#ifndef GRAPH_TRAVERSAL_H
#define GRAPH_TRAVERSAL_H
#include "Graph/DGRAL.h"


typedef enum VertexStatus {
    INVALID = 0,
    UNDISCOVERED,
    DISCOVERED,
    FINISHED
} VertexStatus;
typedef struct StepResult {
    DGRALNode* from;
    VertexStatus fromStatus;
    DGRALNode* to;
    VertexStatus toStatus;
} StepResult;


#endif
