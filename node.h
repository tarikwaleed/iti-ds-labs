#ifndef NODE_H_
#define NODE_H_
#include <stdlib.h>
typedef struct Node {
  int Data;
  struct Node *Prev;
  struct Node *Next;
} Node;
Node *CreateNode(int data) {
  // Allocate the node in the heap
  Node *newNode = (Node*)malloc(sizeof(Node));
  // Fill its members
  newNode->Data = data;
  newNode->Prev = NULL;
  newNode->Next = NULL;
  return newNode;
}
#endif