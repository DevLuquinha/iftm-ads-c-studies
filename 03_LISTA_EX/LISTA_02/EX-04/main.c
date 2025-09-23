#include <stdlib.h>
#include <stdio.h>

struct node
{
    int value;
    struct node* next;
};
typedef struct node Node;

Node* NewNode(int value)
{
    Node* node = malloc(sizeof(Node*));
    node->value = value;
    node->next = NULL;

    return node;
}

void AddValue(Node** list, int value)
{
    Node* aux;

    // 1. If list is null
    if(*list == NULL)
    {
        *list = NewNode(value);
    }
    else
    {
        aux = *list;
        while(aux->next != NULL)
        {
            aux = aux->next;
        }
        
        // Here is the last node
        aux->next = NewNode(value);
    }
}

void ShowList(Node* list)
{
    printf("[");
    while(list != NULL)
    {
        printf("%i", list->value);
        list = list->next;
        if(list != NULL)
            printf(", ");
    }
    printf("]");
}

int main()
{
    // Create the List Functions
    Node* list = NULL;
    AddValue(&list, 1);
    AddValue(&list, 2);
    AddValue(&list, 3);
    AddValue(&list, 4);
    
    printf("LISTA: ");
    ShowList(list);
    return 0;
}
