#include "GraphTraversalTest.h"
extern "C" {
    #include "GraphTraversal/GraphTraversal.h"
    #include "GraphTraversal/DFS.h"
    #include "Graph/DGRAL.h"
    #include "Graph/GraphUtils.h"
    #include "Stack/SDLL.h"
    #include "Hashing/CHT.h"
    #include "Hashing/HashingFunctions.h"
    #include "LinkedList/DLL.h"
    #include "LinkedList/LL.h"
}
#include <tuple>
#include <vector>


static const std::vector<GraphTraversalTestData> graphTraversalTestsData = {
    #include "graphTraversalTestsData.inc"
};


class DFSGraphTraversal : public GraphTraversal {
public:
    DFSGraphTraversal();
    ~DFSGraphTraversal();
    bool isDone() const override;
    void init(DGRALNode* startVertex, unsigned numNodes) override;
    void makeStep(StepResult* stepResult) override;
private:
    unsigned memBufferSize;
    DFS* dfs;
    DLLNode* stackHead;
    DLLNode* stackTail;
    SDLL* stack;
    LLNode* buckets;
    CHT* nodeToStatusMap;
    char* memBuffer;
};


DFSGraphTraversal::DFSGraphTraversal() {
    dfs = nullptr;
    stack = nullptr;
    nodeToStatusMap = nullptr;
    memBuffer = nullptr;
    return;
}


DFSGraphTraversal::~DFSGraphTraversal() {
    delete stackHead;
    delete stackTail;
    delete stack;
    delete nodeToStatusMap;
    delete [] memBuffer;
    delete dfs;
    return;
}


bool DFSGraphTraversal::isDone() const {
    return dfs->done == 1;
}


void DFSGraphTraversal::init(DGRALNode* startVertex, unsigned numNodes) {
    stack = new SDLL;
    stackHead = new DLLNode;
    stackTail = new DLLNode;
    sdllC(stack, stackHead, stackTail);
    unsigned numBuckets = (numNodes / 3) + 1;
    buckets = new LLNode[numBuckets];
    HashingFunction hashFn = &getModPrime16;
    nodeToStatusMap = new CHT;
    chtC(nodeToStatusMap, buckets, numBuckets, hashFn);
    unsigned memBufferSize = 2 * numNodes * (
        2 * sizeof(DGRALNeighboursIterator) +
        sizeof(DGRALNode) +
        sizeof(DLLNode) +
        sizeof(LLNode)
    );
    memBuffer = new char[memBufferSize];
    dfs = new DFS;
    dfsC(dfs, stack, nodeToStatusMap, memBuffer);
    dfsInit(dfs, startVertex);
    return;
}


void DFSGraphTraversal::makeStep(StepResult* stepResult) {
    dfsMakeStep(dfs, stepResult);
    return;
}


GraphTraversal* GraphTraversal::createGraphTraversal(Type type) {
    switch (type) {
        default: {
            return nullptr;
        }
        case GraphTraversal::DFSTy: {
            return new DFSGraphTraversal();
        }
    }
    return nullptr;
}


void GraphTraversalTest::setUpGraph(
    unsigned numNodes,
    unsigned numEdges,
    std::vector<unsigned>* froms,
    std::vector<unsigned>* tos
) {
    graphNodes = new DGRALNode[numNodes];
    succHeads = new LLNode[numNodes];
    predHeads = new LLNode[numNodes];
    llNodes =  new LLNode [2 * numEdges];
    unsigned fromsArr[numEdges];
    unsigned tosArr[numEdges];
    for (unsigned i = 0; i < numEdges; ++i) {
        fromsArr[i] = (*froms)[i];
        tosArr[i] = (*tos)[i];
    }
    makeGraph(
        graphNodes,
        succHeads,
        predHeads,
        numNodes,
        fromsArr,
        tosArr,
        numEdges,
        llNodes
    );
    return;
}


void GraphTraversalTest::checkStepResults(StepResult* sr, StepResultInd* expected) {
    int expectedVertInd = expected->fromIdx;
    DGRALNode* expectedVert = (
        (expectedVertInd != -1) ? &graphNodes[expectedVertInd] : NULL
    );
    EXPECT_EQ(sr->from, expectedVert);
    EXPECT_EQ(sr->fromStatus, expected->fromStatus);
    expectedVertInd = expected->toIdx;
    expectedVert = (
        (expectedVertInd != -1) ? &graphNodes[expectedVertInd] : NULL
    );
    EXPECT_EQ(sr->to, expectedVert);
    EXPECT_EQ(sr->toStatus, expected->toStatus);
    return;
}


TEST_P(GraphTraversalTest, t0) {
    GraphTraversalTestData testData = GetParam();
    gt = GraphTraversal::createGraphTraversal(testData.gtType);
    setUpGraph(
        testData.numNodes,
        testData.numEdges,
        &testData.froms,
        &testData.tos
    );
    gt->init(&graphNodes[0], testData.numNodes);
    StepResult sr;
    for (auto stepResInd : testData.expected) {
        EXPECT_FALSE(gt->isDone());
        gt->makeStep(&sr);
        checkStepResults(&sr, &stepResInd);
    }
    EXPECT_TRUE(gt->isDone());
}


void GraphTraversalTest::TearDown() {
    delete gt;
    delete [] graphNodes;
    delete [] succHeads;
    delete [] predHeads;
    delete [] llNodes;
    return;
}


INSTANTIATE_TEST_CASE_P(
    GraphTraversalTests,
    GraphTraversalTest,
    ::testing::ValuesIn(graphTraversalTestsData)
);
