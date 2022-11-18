#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    //will be reserved in the stack
    LinkedList myList = {.head = NULL, .tail = NULL};
    Add(&myList, 3);
    Add(&myList, 4);
    Add(&myList, 6);
    Display(&myList);// 3  4  6  
    InsertAfterX(&myList,7,6);
    Display(&myList); // 3  4  6  7  
    int data=GetDataByIndex(&myList,1);
    printf("%d\n",data);

    return 0;

}
