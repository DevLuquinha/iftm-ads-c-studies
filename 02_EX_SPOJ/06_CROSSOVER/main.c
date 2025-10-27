#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* next;
    struct node* prev;
};
typedef struct node Node;

struct doublyLinkedList
{
    Node* head;
    Node* tail;
};
typedef struct doublyLinkedList DoubleLinkedList;

int GetInt()
{
    int value = 0;
    scanf("%i", &value);

    return value;
}

Node* CreateNode(int value)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->value = value;

    return newNode;
}

DoubleLinkedList* CreateDoubleList()
{
    DoubleLinkedList* list = malloc(sizeof(DoubleLinkedList));
    list->head = NULL;
    list->tail = NULL;

    return list;
}

void AddValue(DoubleLinkedList* list, int value)
{
    Node* newNode = CreateNode(value);

    if(list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
    }
    else
    {
        list->tail->next = newNode;
        newNode->prev = list->tail;
        list->tail = newNode;
    }
}

DoubleLinkedList* GetList()
{
    DoubleLinkedList* list = CreateDoubleList();

    int v = GetInt();
    while (v != -1)
    {
        if(v != -1)
        {
            AddValue(list, v);
        }

        v = GetInt();
    }

    return list;
}

void ShowList(DoubleLinkedList* list)
{
    Node* start = NULL;

    if(list != NULL && list->head != NULL)
    {
        start = list->head;
    }

    printf("[");
    while(start != NULL)
    {
        printf("%i", start->value);
        start = start->next;
        if(start != NULL)
        {
            printf(", ");
        }
    }
    printf("]");
}

int IsEquals(int c1, int c2)
{
    int isEquals = 0; // Default value is FALSE

    if(c1 == c2)
    {
        isEquals = 1;
    }
    else // FORCE TO FALSE
    {
        isEquals = 0;
    }

    return isEquals;
}

int CanSwitch(Node* startSeq, Node* startSwitchSeq, int lengthSwitchList)
{
    int canSwitch = 0; // Default is FALSE or 0

    int isEqual = 0;
    int countSeq = 0;
    
    while(startSwitchSeq != NULL)
    {
        isEqual = IsEquals(startSeq->value, startSwitchSeq->value);
        if(isEqual == 1) 
        {
            countSeq++;
        }
        else
        {
            startSwitchSeq = NULL;
        }

        if(startSwitchSeq != NULL)
        {
            // Iterave over two lists
            startSeq = startSeq->next;
            startSwitchSeq = startSwitchSeq->next;
        }
    }

    if(countSeq == lengthSwitchList)
    {
        canSwitch = 1;
    }
    else
    {
        canSwitch = 0;
    }
    
    return canSwitch;
}

Node* GetEndNode(Node* startGenSeq, Node* startSwitchSeq, int lengthSwitchList)
{
    Node* endNode = NULL;

    int isEqual = 0;
    int countSeq = 0;
    
    while(startSwitchSeq != NULL)
    {
        isEqual = IsEquals(startGenSeq->value, startSwitchSeq->value);
        if(isEqual == 1) 
        {
            countSeq++;
        }
        else
        {
            startSwitchSeq = NULL;
        }

        if(countSeq == lengthSwitchList)
        {
            endNode = startGenSeq;
        }

        if(startSwitchSeq != NULL)
        {
            startGenSeq = startGenSeq->next;
            startSwitchSeq = startSwitchSeq->next;
        }
    }
    
    return endNode;
}

void SwitchInitNodes(Node* node1, Node* node2)
{
    Node* nodePrevCopy1 = node1->prev;
    Node* nodePrevCopy2 = node2->prev;
    
    nodePrevCopy1->next = node2;
    node2->prev = nodePrevCopy1;

    nodePrevCopy2->next = node1;
    node1->prev = nodePrevCopy2;
}

void SwitchEndNodes(Node* node1, Node* node2)
{
    Node* nodeNext1 = node1->next;
    Node* nodeNext2 = node2->next;
    
    node1->next = nodeNext2;
    nodeNext2->prev = node1;

    node2->next = nodeNext1;
    nodeNext1->prev = node2;
}

void Switch(Node* init1, Node* end1, Node* init2, Node* end2)
{
    // Switch first 
    Node* nodePrevCopy1 = init1->prev;
    Node* nodePrevCopy2 = init2->prev;
    
    Node* nodeNext1 = end1->next;
    Node* nodeNext2 = end2->next;

    nodePrevCopy1->next = init2;
    init2->prev = nodePrevCopy1;

    nodePrevCopy2->next = init1;
    init1->prev = nodePrevCopy2;
    
    end1->next = nodeNext2;
    nodeNext2->prev = end1;

    end2->next = nodeNext1;
    nodeNext1->prev = end2;
}

void SwitchSequence(DoubleLinkedList** list1, DoubleLinkedList** list2, DoubleLinkedList* switch1, DoubleLinkedList* switch2)
{
    // Find the switch(start+end) nodes
    Node* initList1 = (*list1)->head;
    Node* initList2 = (*list2)->head;

    // Init and End nodes of will switch
    Node* initRemoveSeq1 = NULL;
    Node* endRemoveSeq1 = NULL;

    Node* initRemoveSeq2 = NULL;
    Node* endRemoveSeq2 = NULL;

    int canSwitchList1 = 0;
    int canSwitchList2 = 0;

    while(initList1 != NULL)
    {
        canSwitchList1 = 0;
        canSwitchList1 = CanSwitch(initList1, switch1->head, 2);
        if(canSwitchList1 == 1)
        {
            initRemoveSeq1 = initList1; // Find 1° Node to Switch
            endRemoveSeq1 = GetEndNode(initList1, switch1->head, 2);

            while(initList2 != NULL)
            {
                canSwitchList2 = 0;
                canSwitchList2 = CanSwitch(initList2, switch2->head, 2);

                if(canSwitchList2 == 1)
                {
                    initRemoveSeq2 = initList2;
                    endRemoveSeq2 = GetEndNode(initList2, switch2->head, 2);
                    
                    // SWITCH NODES
                    // SwitchInitNodes(initRemoveSeq1, initRemoveSeq2);
                    // SwitchEndNodes(endRemoveSeq1, endRemoveSeq2);

                    Switch(initRemoveSeq1, initRemoveSeq2, endRemoveSeq1, endRemoveSeq2);

                    initList2 = NULL;
                }
                
                // Iterate over 2° list
                if(initList2 != NULL)
                {
                    initList2 = initList2->next;
                }
            }
        }

        if(canSwitchList1 == 1 && canSwitchList2 == 1)
        {
            initList1 = endRemoveSeq2;
        }
        else
        {
            // Iterate over 1° list
            initList1 = initList1->next;
        }
    }
}

int main()
{

    DoubleLinkedList* list1 = GetList();
    DoubleLinkedList* list2 = GetList();
    
    DoubleLinkedList* switch1 = GetList();
    DoubleLinkedList* switch2 = GetList();

    ShowList(list1);

    printf("\n");

    ShowList(list2);

    printf("\n");

    SwitchSequence(&list1, &list2, switch1, switch2);

    ShowList(list1);

    printf("\n");

    ShowList(list2);

    printf("\n");
    
    return 0;
}