#include "../assignment1/linked_list.h"
#include <stdlib.h>
#include<stdio.h>

void LinkedListBubbleSort(LinkedList* list)
{

    for (Node* current = list->head; current!=NULL; current = current->Next) /* starts with head and itrate till NULL value*/
    {
        for (Node* nextNode = current->Next; nextNode!=NULL; nextNode = nextNode->Next) /* starts with head and itrate till NULL value*/
        {
            if (current->Data > nextNode->Data)
            {
                // Swapping Logic
                int temp = nextNode->Data;
                nextNode->Data = current->Data;
                current->Data = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    LinkedList myList = {.head = NULL, .tail = NULL};
    Add(&myList, 4);
    Add(&myList, 2);
    Add(&myList, 1);
    Add(&myList, 5);
    Add(&myList, 3);
    printf("Original List\n");
    Display(&myList);// 4  2  1  5  3
    // Problem1:LinkedBuubleSort
    // LinkedListBubbleSort(&myList);
    // Display(&myList);// 1  2  3  4  5 
    return 0;
}
