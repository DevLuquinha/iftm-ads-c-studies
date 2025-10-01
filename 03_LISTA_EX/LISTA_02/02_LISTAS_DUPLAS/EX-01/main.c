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

void AddValue(List* *list, int value)
{
    Node* prevNode = NULL;
    Node* nextNode = NULL;
    Node* currentNode = NULL;
    Node* node = NewNode(value);

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
            // node->next = (*list)->init->prev;

            // currentNode = (*list)->init;
            // while(currentNode->next != NULL)
            // {
            //     currentNode = currentNode->next;
            // }

            // // The last node
            // currentNode->next = node;
        }
    }
}

void ShowList(List* list)
{
    // Node* init = list->init;
    
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
    AddValue(&defaultList, 1);
    
    ShowList(defaultList);
    return 0;
}