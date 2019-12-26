#ifndef GRAPH_TRAVERSAL_TEST_H
#define GRAPH_TRAVERSAL_TEST_H
extern "C" {
    #include "GraphTraversal/GraphTraversal.h"
    #include "LinkedList/LL.h"
}
#include "gtest/gtest.h"
#include <tuple>
#include <vector>
#include <string>

class GraphTraversal {
public:
    enum Type {
        BEGIN,
        DFSTy,
        BFSTy,
        END
    };
    static GraphTraversal* createGraphTraversal(Type type);
    virtual bool isDone() const = 0;
    virtual void init( DGRALNode* startVertex, unsigned numNodes) = 0;
    virtual void makeStep(StepResult* stepResult) = 0;
};


struct StepResultInd {
    int fromIdx;
    VertexStatus fromStatus;
    int toIdx;
    VertexStatus toStatus;
};


struct GraphTraversalTestData {
    GraphTraversal::Type gtType;
    unsigned numNodes;
    unsigned numEdges;
    std::vector<unsigned> froms;
    std::vector<unsigned> tos;
    std::vector<StepResultInd> expected;
};


class GraphTraversalTest :
public ::testing::TestWithParam<GraphTraversalTestData> {
protected:
    GraphTraversal* gt;
    DGRALNode* graphNodes;
    void setUpGraph(
        unsigned numNodes,
        unsigned numEdges,
        std::vector<unsigned>* froms,
        std::vector<unsigned>* tos
    );
    void checkStepResults(StepResult* sr, StepResultInd* expected);
    void TearDown() override;
private:
    LLNode* succHeads;
    LLNode* predHeads;
    LLNode* llNodes;
};


#endif
