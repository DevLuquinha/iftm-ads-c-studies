#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* next;
};
typedef struct node Node;

Node* NewNode(int value)
{
    Node* node = malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;

    return node;
}

void AddValue(Node** list, int value)
{
    Node* node = NewNode(value);
    Node* currentNode = NULL;

    if(*list == NULL)
    {
        node->next = node;
        *list = node;
    }
    else
    {
        // Has only 1 value
        if(*list == (*list)->next)
        {
            node->next = *list;
            (*list)->next = node;
        }
        else // Has two or more values
        {
            currentNode = (*list)->next;
            while(currentNode->next != *list)
            {
                currentNode = currentNode->next;
            }

            node->next = *list;
            currentNode->next = node;
        }
    }
}

Node* RemoveLastValue(Node** list)
{
    Node* currentNode = NULL;
    Node* nextNode = NULL;
    Node* prevNode = NULL;
    
    if(*list != NULL && (*list)->next != NULL)
    {
        currentNode = *list;
        prevNode = NULL;
        nextNode = (*list)->next;

        while(nextNode != *list)
        {
            prevNode = currentNode;
            
            currentNode = nextNode;
            
            // Iterate over cicle list
            nextNode = nextNode->next;
        }  
        
        if(prevNode == NULL)
        {
            prevNode = currentNode;
            *list = NULL;
        }

        prevNode->next = *list;
    }

    return currentNode;
}

void ShowList(Node* list)
{
    Node* currentNode = NULL;
    Node* nextNode = NULL;

    printf("[");

    if(list != NULL && list->next != NULL)
    {
        currentNode = list;
        nextNode = list->next;

        printf("%i", currentNode->value);

        while(nextNode != list)
        {
            if(nextNode != list)
            {
                printf(", ");
            }
            currentNode = nextNode;
            printf("%i", currentNode->value);

            nextNode = nextNode->next;
        }
    }
    printf("]");
}

int main()
{
    Node* list = NULL;

    AddValue(&list, 1);
    AddValue(&list, 2);
    

    printf("LISTA PADRAO: ");
    ShowList(list);

    Node* nodeRemoved = RemoveLastValue(&list);

    printf("\nLISTA REMOVIDA: ");
    ShowList(list);

    printf("\nITEM REMOVIDO: %i", nodeRemoved->value);
    return 0;
}