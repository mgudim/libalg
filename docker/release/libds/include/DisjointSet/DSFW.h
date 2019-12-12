#ifndef DSFW_INC
#define DSFW_INC


typedef struct DSFWNode {
    void* data;
    struct DSFWNode* parent;
    unsigned weight;
} DSFWNode;


void dsfwMakeSet(DSFWNode* node);
DSFWNode* dsfwFind(DSFWNode* node);
void dsfwUnion(DSFWNode* x, DSFWNode* y);


#endif
