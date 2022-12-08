#include "array_stack.h"
#include "linked_list.h"
#include "linked_stack.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
int main(int argc, char const *argv[]) {
  const char* operation="LinkedListInsert_tail";
  LinkedList list = {.head = NULL, .tail = NULL,.lenght=0};
  LinkedListInsert_tail(&list, 1);
  LinkedListInsert_tail(&list, 2);
  LinkedListInsert_tail(&list, 3);
  LinkedListInsert_tail(&list,4);
  LinkedListInsert_tail(&list,5);
  printf("List Before %s operation:\n",operation);
  LinkedListDisplay(&list);
  /////////////////////// TEST //////////////////////////
  // LinkedList(&list,4);
  /////////////////////// TEST //////////////////////////
  printf("List After %s operation:\n",operation);
  LinkedListDisplay(&list);
  printf("%d",list.lenght);
  return 0;
}