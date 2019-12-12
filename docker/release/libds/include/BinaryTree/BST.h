#ifndef BST_INC
#define BST_INC
#include "Utils/Utils.h"


typedef struct BSTNode {
    void* key;
    void* data;
    struct BSTNode* parent;
    struct BSTNode* leftChild;
    struct BSTNode* rightChild;
} BSTNode;
typedef struct BST {
    BSTNode* _root;
    ComparisonFunction _compareFn;
} BST;


void bstC(BST* self, ComparisonFunction compareFn);
void bstPrint(const BST* self, PrintFunction printFn);
BSTNode* bstFind(const BST* self, void* key);
BSTNode* bstFindMinInSubtree(BSTNode* root);
BSTNode* bstFindMaxInSubtree(BSTNode* root);
void bstInsert(BST* self, BSTNode* node);
void bstUnlink(BST* self, BSTNode* node);


#endif
