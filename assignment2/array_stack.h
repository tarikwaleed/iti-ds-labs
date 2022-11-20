#include <stdio.h>
#define MAXSIZE 10
#define TRUE 1
#define FALSE 0
typedef struct ArrayStack
{
    int stk[MAXSIZE];
    int top;
	int count;
    
}ArrayStack;

int isEmpty(ArrayStack* stack) {
	if (stack->top == -1)
		return TRUE;
	else
		return FALSE;
}
void push(ArrayStack* stack, int n) {
	if(stack->top == MAXSIZE - 1) {
		printf("Warning: Stack is full, You can't add'\n");
		return;
	} else {
		(stack->top)++;
		stack->stk[stack->top] = n;
		(stack->count)++;
	}
}

int pop(ArrayStack* stack,int* value) {
	if (isEmpty(stack)) { 
		// printf("Stack is empty\n");
		return FALSE; 
	} else {
		int temp;
		temp = stack->stk[stack->top--];
        *value=temp;
		(stack->count)--;
        return TRUE;
	}
}

int peek(ArrayStack* stack,int* value) {
	if (isEmpty(stack)) {
		// printf("Stack is empty\n");
		return FALSE;
	} else {
		*value=stack->stk[stack->top];
		return TRUE;
	}
}


void display(ArrayStack* stack) {
	for (int i=stack->count-1; i >= 0; i--)
		printf("%d  ", stack->stk[i]);
	printf("\n");
}