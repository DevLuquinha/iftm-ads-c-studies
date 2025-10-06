#include <stdlib.h>
#include <stdio.h>
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
    Node* start;
    Node* end;
};
typedef struct list List;

List* NewDefaultList()
{
    List* list = malloc(sizeof(List));
    list->start = NULL;
    list->end = NULL;

    return list;
}

Node* NewNode(int value)
{
    Node* node = malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->value = value;

    return node;
}

void AddValueList(List* *list, int value)
{
    Node* node = NewNode(value);
    Node* startNode = NULL;
    Node* endNode = NULL;

    // If the list no has values
    if((*list)->start == NULL && ((*list)->end == NULL))
    {
        (*list)->start = node;
        (*list)->end = node;
    }
    else
    {
        (*list)->end->next = node;
        node->prev = (*list)->end;
        (*list)->end = node;
    }
}

void ShowList(List* list)
{
    Node* aux = list->start;

    printf("[");
    while (aux != NULL)
    {
        printf("%i", aux->value);
        aux = aux->next;
        if(aux != NULL)
            printf(", ");
    }
    printf("]");
}

int GetInt()
{
    int num;
    scanf("%i", &num);

    return num;
}

int main()
{
    List* list = NewDefaultList();
    List* listRemove = NewDefaultList();

    int value = -1;
    
    // Get the defaultList 
    do
    {
        value = GetInt();
        AddValueList(&list, value);
    } while (value != -1);

    // Get the listRemove
    do
    {
        value = GetInt();
        AddValueList(&listRemove, value);
    } while (value != -1);

    ShowList(list);

    printf("\n");
    
    ShowList(listRemove);
    return 0;
}