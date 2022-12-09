#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
  struct Node *head;
  struct Node *tail;
  int lenght;

} LinkedList;
void LinkedList_Display(LinkedList *mylist) {
  struct Node *current = mylist->head;

  while (current) {
    printf("%d  ", current->Data);
    current = current->Next;
  }
  printf("\n");
}
int LinkedList_GetDataByIndex(LinkedList *mylist, int index) {
  Node *current = mylist->head;
  int count = 0;
  while (current) {
    if (index == count) {
      return current->Data;
    }
    count++;
    current = current->Next;
  }
  return 0;
}

Node *LinkedList_GetNodeByData(LinkedList *mylist, int data) {
  Node *current = mylist->head;

  while (current) {
    if (current->Data == data)
      return current;
    current = current->Next;
  }
}

int GetCount(LinkedList *mylist) {
  Node *current = mylist->head;
  int count = 0;
  while (current) {
    count++;
    current = current->Next;
  }
  return count;
}

void LinkedList_Insert_tail(LinkedList *mylist, int data) {
  Node *newNode = CreateNode(data);

  // check if it's the first node that'll be inserted
  if (mylist->head == NULL) {
    mylist->head = mylist->tail = newNode;
  } else {
    mylist->tail->Next = newNode;
    newNode->Prev = mylist->tail;
    mylist->tail = newNode;
  }
  mylist->lenght++;
}
void LinkedList_Insert_head(LinkedList *mylist, int data) {
  Node *newNode = CreateNode(data);
  if (mylist->head == NULL) {
    mylist->head = mylist->tail = newNode;
  } else {
    mylist->head->Prev = newNode;
    newNode->Next = mylist->head;
    mylist->head = newNode;
  }
  mylist->lenght++;
}

void LinkedList_Insert_after_data(LinkedList *mylist, int data, int afterData) {
  Node *target = LinkedList_GetNodeByData(mylist, afterData);
  if (target) {
    Node *newNode = CreateNode(data);
    newNode->Next = target->Next;
    newNode->Prev = target;
    target->Next = newNode;
    // if (target == mylist->tail) {
    if (target->Next)
      newNode->Next->Prev = newNode;
    else
      mylist->tail = newNode;
  }
}

void LinkedList_Remove(LinkedList *mylist, int data) {
  Node *node = LinkedList_GetNodeByData(mylist, data);

  // the node doesn't exist in the list
  if (!node)
    return;

  // the node is the first elemnt in the list
  if (node == mylist->head) {
    // the node is the first and only element
    if (mylist->head == mylist->tail) {
      mylist->head = mylist->tail = NULL;
    }
    // the node is the first and there are other nodes
    else {
      mylist->head = mylist->head->Next;
      mylist->head->Prev = NULL;
    }
  }
  // the node is the last element in the array
  else if (node == mylist->tail) {
    mylist->tail = mylist->tail->Prev;
    mylist->tail->Next = NULL;
    // The node is in the middle of the array
  } else {
    node->Prev->Next = node->Next;
    node->Next->Prev = node->Prev;
  }

  free(node);
}

Node *Reverse(LinkedList *mylist) {
}

void InPlaceReverse(LinkedList *mylist) {
  if (mylist->head == NULL)
    // return mylist->head;
    return;
  Node *current = mylist->head;
  Node *temp;
  while (current) {
    // 1
    temp = current->Next;
    // 2
    current->Next = current->Prev;
    // 3
    current->Prev = temp;
    if (temp == NULL) {
      mylist->tail = mylist->head;
      mylist->head = current;
    }
    current = temp;
  }
  // return mylist->head;
}

#endif