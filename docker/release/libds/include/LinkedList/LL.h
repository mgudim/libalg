#ifndef LL_INC
#define LL_INC


typedef struct LLNode {
    void* data;
    struct LLNode* next;
} LLNode;


void llInsertAfter(LLNode* nodeToInsert, LLNode* node);
void llUnlinkAfter(LLNode* node);


#endif
