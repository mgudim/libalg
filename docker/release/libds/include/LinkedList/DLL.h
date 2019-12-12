#ifndef DLL_INC
#define DLL_INC


typedef struct DLLNode {
    void* data;
    struct DLLNode* next;
    struct DLLNode* prev;
} DLLNode;


void dllInsertAfter(DLLNode* nodeToInsert, DLLNode* node);
void dllUnlink(const DLLNode* node);


#endif
