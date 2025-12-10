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

Node* NewNode(int value)
{
    Node* node = malloc(sizeof(Node));
    node->prev = NULL;
    node->next = NULL;
    node->value = value;

    return node;
}

List* CreateList()
{
    List* list = malloc(sizeof(List));
    list->start = NULL;
    list->end = NULL;

    return list;
}

void AddValueList(List* *list, int value)
{
    Node* newNode = NewNode(value);
    Node* startNode = (*list)->start;
    Node* endNode = (*list)->end;

    // 1. Default list is not INITIALIZED
    if(*list == NULL)
    {
        *list = CreateList();
        (*list)->start = newNode;
        (*list)->end = newNode;
    }
    else
    {
        // 2. The default list don't have any value
        if(startNode == NULL && endNode == NULL)
        {
            (*list)->start = newNode;
            (*list)->end = newNode;
        }
        else
        {
            endNode->next = newNode;
            newNode->prev = endNode;
            (*list)->end = newNode;
        }
    }
}

void ShowList(List* list)
{
    Node* startNode = NULL;

    if(list != NULL && list->start != NULL)
    {
        startNode = list->start;
    }

    printf("[");
    while (startNode != NULL)
    {
        printf("%i", startNode->value);
        
        startNode = startNode->next;
        if(startNode != NULL)
            printf(", ");
    }
    printf("]");
}

Node* Minimum(List* list)
{
    Node* nodeMin = NULL;
    Node* startNode = NULL;

    if(list != NULL && list->start != NULL)
    {
        startNode = list->start;
        nodeMin = startNode;

        while(startNode != NULL)
        {
            if(startNode != NULL && startNode->value < nodeMin->value)
            {
                nodeMin = startNode;
            }
            
            startNode = startNode->next;
        }
    }

    return nodeMin;
}

Node* Maximum(List* list)
{
    Node* maximum = NULL;
    Node* startNode = NULL;

    if(list != NULL && list->start != NULL)
    {
        startNode = list->start;
        maximum = startNode;

        while(startNode != NULL)
        {
            if(startNode != NULL && startNode->value > maximum->value)
            {
                maximum = startNode;    
            }

            startNode = startNode->next;
        }
    }

    return maximum;
}

int main()
{
    List* list = CreateList();
    AddValueList(&list, 1);
    AddValueList(&list, 2);
    AddValueList(&list, 3);

    printf("LISTA PADRAO: ");
    ShowList(list);
    
    // 1. Get the Minimum and Maximum
    Node* min = Minimum(list);
    Node* max = Maximum(list);
    
    if(min != NULL)
    {
        printf("\nO MENOR: %i", min->value);
    }
    if(max != NULL)
    {
        printf("\nO MAIOR: %i", max->value);
    }
    
    printf("\nLISTA DEPOIS: ");
    ShowList(list);

    return 0;
}
