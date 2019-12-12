#ifndef HASH_TABLES
#define HASH_TABLES
#include <stddef.h>


typedef struct KeyValuePairNode {
    int key;
    void* value;
    struct KeyValuePairNode* next;
} KeyValuePairNode;


typedef struct ChainedHashTableData {
    size_t numBuckets;
    KeyValuePairNode* bucketsArray;
} ChainedHashTableData;


//value has to be LLNode* with data field containing key-value pair.
void initializeBucketsArray(
    KeyValuePairNode* bucketHeads,
    ChainedHashTableData* chainedHashTableData
);
void insertPrimeMod16Chained(
    KeyValuePairNode* keyValuePairNode,
    ChainedHashTableData* chainedHashTableData
);
KeyValuePairNode* deletePrimeMod16Chained(
    int key,
    ChainedHashTableData* chainedHashTableData
);
void* findPrimeMod16Chained(
    int key,
    ChainedHashTableData* chainedHashTableData
);


#endif
