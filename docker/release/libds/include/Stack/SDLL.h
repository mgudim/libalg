#ifndef SDLL_INC
#define SDLL_INC
#include "LinkedList/DLL.h"


typedef struct SDLL {
    DLLNode* _head;
    DLLNode* _tail;
} SDLL;;

void sdllC(SDLL* self, DLLNode* head, DLLNode* tail);
int sdllIsEmpty(const SDLL* self);
DLLNode* sdllPeek(const SDLL* self);
void sdllPush(SDLL* self, DLLNode* node);
DLLNode* sdllPop(SDLL* self);


#endif
