#include <stdio.h>
#include <stdlib.h>
#include "../assignment1/linked_list.h"
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0
typedef struct LinkedStack
{
    Node* top;
}LinkedStack;
void LinkedStackPush(LinkedStack* stack,int value){
    Node* ptr=(Node*)malloc(sizeof(Node));
    ptr->Data=value;
    ptr->Next=NULL;
    if(stack->top!=NULL)
        ptr->Next=stack->top;
    stack->top=ptr;
}
void LinkedStackDisplay (LinkedStack* stack){
    Node* current=stack->top;
    while (current!=NULL){
        printf("%d ",current->Data);
        current=current->Next;
    }
    printf("\n");
}
int LinkedStackPop(LinkedStack* stack,int* value){
    Node* temp;
    if(stack->top == NULL){
        return FALSE;
    }
    temp= stack->top;
    *value=temp->Data;
    stack->top=stack->top->Next;
    return TRUE;
    
}