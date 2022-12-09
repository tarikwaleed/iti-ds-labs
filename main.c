#include "array_stack.h"
#include "linked_list.h"
#include "linked_stack.h"
#include "math.h"
#include "stdio.h"
#include "stdlib.h"
int main(int argc, char const *argv[]) {
  const char* operation="LinkdedListGetDataByIndex";
  LinkedList list = {.head = NULL, .tail = NULL,.lenght=0};

  LinkedListInsert_tail(&list, 1);
  LinkedListInsert_tail(&list, 2);
  LinkedListInsert_tail(&list, 3);
  LinkedListInsert_tail(&list,4);
  LinkedListInsert_tail(&list,5);

  printf("List Before %s operation:\n",operation);
  LinkedListDisplay(&list);

  /////////////////////// TEST //////////////////////////
  int result=LinkedListGetDataByIndex(&list,2);
  /////////////////////// TEST //////////////////////////
  printf("%d\n",result);
  printf("%d\n",list.head->Data);

  // printf("List After %s operation:\n",operation);
  // LinkedListDisplay(&list);
  return 0;
}