#include <stdio.h>
#include "array_stack.h"
#include "linked_stack.h"
int main(int argc, char const *argv[])
{
    // ArrayStack stack={.top=-1,.count=0};
    // push(&stack,1);
    // push(&stack,2);
    // push(&stack,3);
    // push(&stack,4);// top-to-bottom: 4  3  2  1  
    // printf("Stack Before Pop:\n");
    // display(&stack);
    // int a;
    // pop(&stack,&a);
    // printf("Popped Value is: %d\n",a);
    // printf("Stack After Pop:\n");
    // display(&stack);
    LinkedStack stack={.top=NULL};
    LinkedStackPush(&stack,1);
    LinkedStackPush(&stack,2);
    LinkedStackPush(&stack,3);
    LinkedStackPush(&stack,4);
    LinkedStackDisplay(&stack);
    int a;
    LinkedStackPop(&stack,&a);
    printf("Stack After Pop:\n");
    LinkedStackDisplay(&stack);
    printf("Popped Value: %d \n",a);

    return 0;
}
 