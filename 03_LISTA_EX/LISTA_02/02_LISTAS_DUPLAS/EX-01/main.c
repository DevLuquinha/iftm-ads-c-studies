#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int value;
    struct node* prev;
    struct node* next;
};
typedef struct node Node;

struct list
{
    Node* init;
    Node* end;
};
typedef struct list List;

Node* NewNode(int value)
{
    Node* node = malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->value = value;
    return node;
}

List* NewList()
{
    List* list = malloc(sizeof(List));
    list->init = NULL;
    list->end = NULL;
    return list;
}

void AddStartValue(List* *list, int value)
{
    Node* node = NewNode(value);
    Node* initNode = NULL;
    Node* endNode = NULL;

    // 1. If the default list is NULL
    if(*list == NULL)
    {
        *list = NewList();

        (*list)->init = node;
        (*list)->end = node;
    }
    else
    {
        // 2. If there is a list but don't have any node
        if((*list)->init == NULL && (*list)->end == NULL)
        {
            (*list)->init = node;
            (*list)->end = node;
        }
        else
        {
            initNode = (*list)->init;

            initNode->prev = node;
            node->next = initNode;
            (*list)->init = node;
        }
    }
}

void AddEndValue(List* *list, int value)
{
    Node* node = NewNode(value);
    Node* initNode = NULL;
    Node* endNode = NULL;

    // 1. If the default list is NULL
    if(*list == NULL)
    {
        // 1.1 Create the 'default' list
        *list = NewList();
        
        (*list)->init = node; 
        (*list)->end = node;
    }
    else
    {
        // 2. If there is a list but don't have any node
        if((*list)->init == NULL && (*list)->end == NULL)
        {
            (*list)->init = node;
            (*list)->end = node;
        }
        else
        {
            // 3. Support vars
            initNode = (*list)->init;
            endNode = (*list)->end;

            endNode->next = node;
            node->prev = endNode;
            (*list)->end = node;
        }
    }
}

void ShowList(List* list)
{    
    printf("[");
    while(list != NULL && list->init != NULL)
    {
        printf("%i", list->init->value);
        
        list->init = list->init->next;

        if(list->init != NULL)
            printf(", ");
    }
    printf("]");
}

int main()
{
    // Escreva uma função que retire o último elemento de uma dada lista.
    // A função deve retornar o ponteiro para a lista alterada

    List* defaultList = NewList();
    AddEndValue(&defaultList, 1);
    AddEndValue(&defaultList, 2);
    AddEndValue(&defaultList, 3);

    ShowList(defaultList);
    return 0;
}