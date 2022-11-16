#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

int main()
{
    LinkedList myList = {.head = NULL, .tail = NULL};
    Add(&myList, 3);
    Add(&myList, 4);
    Add(&myList, 5);
    Add(&myList, 5);
    Display(&myList);
    Remove(&myList,5);
    Display(&myList);

    return 0;
    printf("Hello world!\n");
    return 0;
}
