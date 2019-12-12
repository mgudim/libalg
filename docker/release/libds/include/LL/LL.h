#ifndef LL
#define LL


typedef struct LLNode {
    void* data;
    struct LLNode* next;
} LLNode;


void insertAfter(LLNode* node, LLNode* llNode);
LLNode* unlinkAfter(LLNode* llNode);


#endif
