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
    Node* initNode = NULL;

    if(list != NULL && list->init != NULL)
    {
        initNode = list->init;
    }

    printf("[");
    while(initNode != NULL)
    {
        printf("%i", initNode->value);
        
        initNode = initNode->next;

        if(initNode != NULL)
            printf(", ");
    }
    printf("]");
}

void RemoveLastElement(List* *list)
{
   (*list)->end->prev->next = NULL; 
}

void Append(List* list, int value)
{
    Node* newNode = NewNode(value);
    if(list->init == NULL)
    {
        list->init = newNode;
        list->end = newNode;
    }
    else
    {
        list->end->next = newNode;
        newNode->prev = list->end;
        list->end = newNode;
    }
}

int main()
{
    // Escreva uma função que retire o último elemento de uma dada lista.
    // A função deve retornar o ponteiro para a lista alterada

    List* list = NewList();
    Append(list, 1);
    Append(list, 2);
    Append(list, 3);
    Append(list, 4);

    printf("LISTA INICIAL: ");
    ShowList(list);

    RemoveLastElement(&list);

    printf("\nLISTA FINAL: ");
    ShowList(list);

    return 0;
}