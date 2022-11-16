#ifndef LINKED_LIST_H
#define LINKED_LIST_H


typedef struct Node
{
    int Data;
    struct Node* Prev;
    struct Node* Next;
}Node;

typedef struct LinkedList
{
    struct Node* head;
    struct Node* tail;

}LinkedList;


//void Add(LinkedList *myList, int data)

void Add(LinkedList* mylist,int data)
{
    Node *newNode = malloc(sizeof(Node));
    newNode->Data = data;
    newNode->Prev = newNode->Next = NULL;

    if(mylist->head == NULL)
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

void Display(LinkedList* mylist)
{
    struct Node* current = mylist->head;

    while(current != NULL)
    {
        printf("%d  ", current->Data);
        current = current->Next;
    }
    printf("\n");
}

Node* GetNodeByData(LinkedList* mylist,int data)
{
    Node *current = mylist->head;

    while(current != NULL)
    {
        if(data == current->Data)
            return current;

        current = current->Next;
    }

    return NULL;
}

void Remove(LinkedList* mylist,int data)
{
    struct Node* node = GetNodeByData(mylist,data);

    if(node == NULL)
        return;

    if(node == mylist->head)
    {
        if(mylist->head == mylist->tail)
        {
            mylist->head = mylist->tail = NULL;
        }
        else
        {
           mylist->head =  mylist->head->Next;
           mylist->head->Prev = NULL;
        }
    }
    else if(node == mylist->tail)
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

void InsertAfter(int data, int afterData)
{

}

int GetDataByIndex(int index)
{

}

int GetCount()
{

}


Node* Reverse()
{

}

void InPlaceReverse()
{

}


#endif // LINKED_LIST_H
