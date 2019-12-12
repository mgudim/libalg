#ifndef QLL_INC
#define QLL_INC
#include "LinkedList/LL.h"


typedef struct QLL {
    LLNode* _head;
    LLNode* _back;
} QLL;


void qllC(QLL* self, LLNode* head);
int qllIsEmpty(const QLL* self);
LLNode* qllPeekFront(const QLL* self);
LLNode* qllPeekBack(const QLL* self);
void qllPush(QLL* self, LLNode* node);
LLNode* qllPop(QLL* self);


#endif
