#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
    int Data;
    struct Node *Prev;
    struct Node *Next;
} Node;

typedef struct LinkedList
{
    struct Node *head;
    struct Node *tail;

} LinkedList;

// void Add(LinkedList *myList, int data)

void Add(LinkedList *mylist, int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = NULL;
    newNode->Next = NULL;

    if (mylist->head == NULL)
    {
        mylist->head = mylist->tail = newNode;
    }
    else
    {
        mylist->tail->Next = newNode;
        newNode->Prev = mylist->tail;
        mylist->tail = newNode;
    }
}

void Display(LinkedList *mylist)
{
    struct Node* current = mylist->head;

    while (current != NULL)
    {
        printf("%d  ", current->Data);
        current = current->Next;
    }
    printf("\n");
}

Node* GetNodeByData(LinkedList *mylist, int data)
{
    Node* current = mylist->head;

    while (current != NULL)
    {
        if (current->Data == data)
            return current;

        current = current->Next;
    }

    return NULL;
}

void Remove(LinkedList *mylist, int data)
{
    struct Node *node = GetNodeByData(mylist, data);

    // the node doesn't exist in the list
    if (node == NULL)
        return;

    // the node is the first elemnt in the list
    if (node == mylist->head)
    {
        // the node is the first and only element
        if (mylist->head == mylist->tail)
        {
            mylist->head = mylist->tail = NULL;
        }
        // the node is the first and there are other nodes
        else
        {
            mylist->head = mylist->head->Next;
            mylist->head->Prev = NULL;
        }
    }
    // the node is the last element in the array
    else if (node == mylist->tail)
    {
        mylist->tail = mylist->tail->Prev;
        mylist->tail->Next = NULL;
    }
    else
    {
        node->Prev->Next = node->Next;
        node->Next->Prev = node->Prev;
    }

    free(node);
}

void InsertAfterX(LinkedList *mylist, int data, int xData)
{
    Node *x = GetNodeByData(mylist, xData);
    if (x != NULL)
    {
        Node *newNode = malloc(sizeof(Node));
        newNode->Data = data;
        newNode->Next = x->Next;
        newNode->Prev = x;
        x->Next = newNode;
        if(x==mylist->tail){
            mylist->tail=newNode;
        }
        else{
            newNode->Next->Prev=newNode;
        }
    }
}

int GetDataByIndex(LinkedList* mylist,int index)
{
    Node* x=mylist->head;
    int count=0;
    while(x!=NULL){
        if(index==count){
            return x->Data;
        }
        count++;
        x=x->Next;
    }
    return 0;

}

int GetCount(LinkedList* mylist)
{
    Node* x=mylist->head;
    int count=0;
    while(x!=NULL){
        count++;
        x=x->Next;
    }
    return count;
}

Node* Reverse()
{
}

void InPlaceReverse()
{
}

#endif // LINKED_LIST_H
