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

Node* Minimum(Node* list)
{
    Node* minimum = list;
    Node* aux;

    while(list != NULL)
    {
        if(list->value < minimum->value)
        {
            minimum = list;
        }
        list = list->next;
    }

    return minimum;
}

Node* Maximum(Node* list)
{
    Node* maximum = list;
    Node* aux;

    while(list != NULL)
    {
        if(list->value > maximum->value)
        {
            maximum = list;
        }
        list = list->next;
    }

    return maximum;
}

int main()
{
    // Create the List Functions
    Node* list = NULL;
    AddValue(&list, 6);
    AddValue(&list, 10);
    AddValue(&list, 8);
    AddValue(&list, 4);
    
    Node* minimum = Minimum(list);
    Node* maximum = Maximum(list);
    
    printf("\nLISTA: ");
    ShowList(list);

    printf("\n\n============ RESULTADOS ============");
    printf("\n1.MINIMUM/MAXIMUM");
    printf("\nO menor valor: %i", minimum->value);
    printf("\nO maior valor: %i", maximum->value);
    printf("\n====================================");
    return 0;
}
