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

int GetListLength(List* list)
{
    Node* nodeStart = list->start;
    int quant = 0;
    while(nodeStart != NULL)
    {
        quant++;
        nodeStart = nodeStart->next;
    }

    return quant;
}

void RemoveItensByList(List* *list, List* listRemove)
{
    Node* startList = (*list)->start;
    Node* startListRemove = listRemove->start;

    int listRemoveLen = GetListLength(listRemove);
    int countAux = 0;

    Node* nodeIn = NULL;
    Node* nodeOut = NULL;

    // If has values to remove
    if(listRemove->start != NULL && listRemove->end != NULL)
    {
         // Iterate over list
         while(startList != NULL)
         {
            if(startListRemove != NULL)
            {
                // Find the nodeIn
                if(startList->value == startListRemove->value && nodeIn == NULL)
                {
                    nodeIn = startList;
                    startListRemove = startListRemove->next;
                    countAux++;
                }
                else if(startList->value == startListRemove->value)
                {
                    nodeOut = startList;
                    startListRemove = startListRemove->next;
                    countAux++;
                }
                else if(countAux < listRemoveLen)
                {
                    nodeIn = NULL;
                    nodeOut = NULL;
                    startListRemove = listRemove->start;
                    countAux = 0;
                }
            }

            startList = startList->next;
         }

         if(nodeIn != NULL && nodeOut != NULL)
         {
            if(nodeIn->value == listRemove->start->value && 
                nodeOut->value == listRemove->end->value && 
                countAux == listRemoveLen)
            {
                nodeIn->prev->next = nodeOut->next;
            }
         }
    }

    // 10 4 6 8 9 1 {4 6 8 12} 3 - 4 6 8 12 -----> 10 4 6 8 9 1 3
    
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
        if(value != -1)
            AddValueList(&list, value);
    } while (value != -1);

    // Get the listRemove
    do
    {
        value = GetInt();
        if(value != -1)
            AddValueList(&listRemove, value);
    } while (value != -1);

    ShowList(list);

    printf("\n");

    ShowList(listRemove);

    RemoveItensByList(&list, listRemove);

    printf("\n");
    ShowList(list);

    return 0;
}