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

List* NewList()
{
    List* list = malloc(sizeof(List));
    list->init = NULL;
    list->init = NULL;
    return list;
}

int main()
{
    // Escreva uma função que retire o último elemento de uma dada lista.
    // A função deve retornar o ponteiro para a lista alterada

    List* defaultList = NULL;

    printf("Hello World");
    return 0;
}