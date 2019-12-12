#ifndef CHT_INC
#define CHT_INC
#include "LinkedList/LL.h"
#include <stddef.h>


typedef struct KVPair {
    int key;
    void* value;
} KVPair;
typedef unsigned (*HashingFunction)(int, unsigned);
typedef struct CHT {
    LLNode* _buckets;
    unsigned _numBuckets;
    HashingFunction _hashFn;
} CHT;


void chtC(
    CHT* self,
    LLNode* buckets,
    unsigned numBuckets,
    HashingFunction hashFn
);
LLNode* chtFind(const CHT* self, int key);
void chtInsert(CHT* self, LLNode* kvPairNode);
LLNode* chtRemove(CHT* self, int key);


#endif
