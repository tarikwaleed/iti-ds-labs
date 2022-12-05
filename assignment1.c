#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  // will be reserved in the stack
  LinkedList myList = {.head = NULL, .tail = NULL};
  Add(&myList, 1);
  Add(&myList, 2);
  Add(&myList, 3);
  Add(&myList, 4);
  printf("Original List\n");
  Display(&myList); // 1  2  3  4
  // printf("%p\n",myList->head);
  // InsertAfterX(&myList,7,6);
  // Display(&myList); // 3  4  6  7
  // int data=GetDataByIndex(&myList,1);
  // printf("%d\n",data);
  // int count=GetCount(&myList);
  // printf("Number of elements in the list is %d\n",count);
  InPlaceReverse(&myList);
  printf("After Reverse\n");
  Display(&myList);
  return 0;
}
