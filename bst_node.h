#if !defined(BST_NODE_)
#define BST_NODE_
#include "stdio.h"
#include "stdlib.h"

typedef struct BSTNode {
  int Data;
  struct BSTNode *Left;
  struct BSTNode *Right;
}BSTNode;
BSTNode *CreateBSTNode(int data) {
  BSTNode *node = (BSTNode *)malloc(sizeof(BSTNode));
  node->Data = data;
  node->Right = NULL;
  node->Left = NULL;
  return node;
}
#endif // BST_NODE_
