#ifndef TREE_H
#define TREE_H
#include "bst_node.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
  BSTNode *Root;
} Tree;
void GoRight(BSTNode *current) {
  *current = *current->Right;
}
void GoLeft(BSTNode *current) {
  *current = *current->Left;
}
void Display(BSTNode *node) {
  if (!node)
    return;

  Display(node->Left);
  printf("%d  ", node->Data);
  Display(node->Right);
}

void BST_add(Tree *tree, int data) {
  BSTNode *node = CreateBSTNode(data);

  if (!(tree->Root)) {
    tree->Root = node;
  } else {
    BSTNode *current = tree->Root;
    BSTNode *parent;

    while (current) {
      parent = current;
      if (data > current->Data)
        // GoRight(&current);
        current = current->Right;
      else
        current = current->Left;
      // GoLeft(&current);
    }
    if (data > parent->Data)
      parent->Right = node;
    else
      parent->Left = node;
  }
}
// void BST_add_recursive(Tree *tree, int data) {
//   // base case
//   if (!tree->Root) {
//     tree->Root = CreateBSTNode(data);
//   } else if (data > tree->Root->Data) {
//     tree->Root->Right
//   }
// }


// BSTNode *GetNodeByData(Tree *tree, int data) {
//   BSTNode *current = tree->Root;

//   while (current != NULL) {
//     if (data == current->Data)
//       return current;

//     if (data > current->Data)
//       current = current->Right;
//     else
//       current = current->Left;
//   }

//   return NULL;
// }

// BSTNode *GetParent(Tree *tree, BSTNode *node) {
//   BSTNode *parent = tree->Root;

//   while (parent != NULL) {
//     if (parent->Left == node || parent->Right == node)
//       return parent;

//     if (node->Data > parent->Data)
//       parent = parent->Right;
//     else
//       parent = parent->Left;
//   }

//   return NULL;
// }

// BSTNode *GetMaxRight(BSTNode *node) {
//   BSTNode *current = node;

//   while (current->Right != NULL) {
//     current = current->Right;
//   }

//   return current;
// }

// void Remove(Tree *tree, int data) {
//   BSTNode *node = GetNodeByData(tree, data);

//   if (node == NULL)
//     return;

//   if (node == tree->Root) {
//     if (node->Left == NULL && node->Right == NULL) {
//       tree->Root = NULL;
//     } else if (node->Right == NULL) {
//       tree->Root = tree->Root->Left;
//     } else if (node->Left == NULL) {
//       tree->Root = tree->Root->Right;
//     } else {
//       BSTNode *newRoot = tree->Root->Left;
//       BSTNode *maxRight = GetMaxRight(newRoot);

//       maxRight->Right = tree->Root->Right;
//       tree->Root = newRoot;
//     }
//   } else {
//     BSTNode *parent = GetParent(tree, node);
//     BSTNode *newChild;

//     if (node->Left == NULL && node->Right == NULL) {
//       newChild = NULL;
//     } else if (node->Right == NULL) {
//       newChild = node->Left;
//     } else if (node->Left == NULL) {
//       newChild = node->Right;
//     } else {
//       BSTNode *newParent = node->Left;
//       BSTNode *maxRight = GetMaxRight(newParent);

//       maxRight->Right = node->Right;

//       newChild = newParent;
//     }

//     if (parent->Left == node)
//       parent->Left = newChild;
//     else
//       parent->Right = newChild;
//   }

//   free(node);
// }

// int GetMaxDepth(BSTNode *node) {
//   if (!node)
//     return 0;
//   int x = 1 + GetMaxDepth(node->Right);
//   int y = 1 + GetMaxDepth(node->Left);
//   return x > y ? x : y;
// }

#endif // TREE_H
