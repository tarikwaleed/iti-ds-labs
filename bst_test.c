#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

int main() {
  Tree tree;
  tree.Root = NULL;

  BST_add(&tree, 50);
  BST_add(&tree, 40);
  BST_add(&tree, 30);
  BST_add(&tree, 60);
  BST_add(&tree, 70);
  BST_add(&tree, 45);
  BST_add(&tree, 25);
  BST_add(&tree, 65);

  Display(tree.Root);
  printf("\n");
  // printf("Max depth is: %d", GetMaxDepth(tree.Root));

  return 0;
}
