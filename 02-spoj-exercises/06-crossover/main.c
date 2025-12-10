#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char value;
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

// Prototipes
char GetChar();
int GetInt();
Node* CreateNode(char value);
DoubleLinkedList* CreateDoubleList();
void AddValue(DoubleLinkedList* list, char value);
DoubleLinkedList* GetGeneSequence();
void ShowGeneSequence(DoubleLinkedList* list);
void SwitchGenes(DoubleLinkedList** geneSequence1, DoubleLinkedList** geneSequence2, DoubleLinkedList* switchSequence1, DoubleLinkedList* switchSequence2);
int GetListLength(DoubleLinkedList* list);
int IsEquals(char c1, char c2);
int CanSwitch(Node* startGenSeq, Node* startSwitchSeq, int lengthSwitchList);
Node* GetEndNode(Node* startGenSeq, Node* startSwitchSeq, int lengthSwitchList);
void SwitchInitNodes(Node* init1, Node* init2, DoubleLinkedList** list1, DoubleLinkedList** list2);
void SwitchEndNodes(Node* end1, Node* end2, DoubleLinkedList** list1, DoubleLinkedList** list2);
void SwitchGenes(DoubleLinkedList** geneSequence1, DoubleLinkedList** geneSequence2, DoubleLinkedList* switchSequence1, DoubleLinkedList* switchSequence2);
DoubleLinkedList* FreeList(DoubleLinkedList* list);

char GetChar()
{
    char c = ' ';
    scanf("%c", &c);

    return c;
}

int GetInt()
{
    int value;
    scanf("%i", &value);

    return value;
}

Node* CreateNode(char value)
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

void AddValue(DoubleLinkedList* list, char value)
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

DoubleLinkedList* GetGeneSequence()
{
    DoubleLinkedList* list = CreateDoubleList();

    char c = ' ';
    while(c != '\n')
    {
        c = GetChar();
        if(c != '\n')
        {
            AddValue(list, c);
        }
    }

    return list;
}

int GetListLength(DoubleLinkedList* list)
{
    int length = 0;
    Node* startList = NULL;

    if(list != NULL && list->head != NULL)
    {
        startList = list->head;
    }

    while(startList != NULL)
    {
        length++;
        startList = startList->next;
    }

    return length;
}

void ShowGeneSequence(DoubleLinkedList* list)
{
    Node* start = NULL;

    if(list != NULL && list->head != NULL)
    {
        start = list->head;
    }

//    printf("[");
    while(start != NULL)
    {
        printf("%c", start->value);
        start = start->next;
//         if(start != NULL)
//         {
//             printf(", ");
//         }
    }
//    printf("]");
}

int IsEquals(char c1, char c2)
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

int CanSwitch(Node* startGenSeq, Node* startSwitchSeq, int lengthSwitchList)
{
    int canSwitch = 0; // Default is FALSE or 0

    int isEqual = 0;
    int countSeq = 0;

    while(startSwitchSeq != NULL)
    {
        if(startGenSeq != NULL)
        {
            isEqual = IsEquals(startGenSeq->value, startSwitchSeq->value);
        }

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
            if(startGenSeq->next != NULL)
            {
                startGenSeq = startGenSeq->next;
            }

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

void SwitchInitNodes(Node* init1, Node* init2, DoubleLinkedList** list1, DoubleLinkedList** list2)
{    
    Node* nodePrev1 = init1->prev;
    Node* nodePrev2 = init2->prev;

    // If the init1 was the first node of list
    if(nodePrev1 == NULL)
    {
        (*list1)->head = init2;
    }
    else
    {
        nodePrev1->next = init2;
    }
    init2->prev = nodePrev1;

    // if the init2 was the first node of list
    if(nodePrev2 == NULL)
    {
        (*list2)->head = init1;
    }
    else
    {
        nodePrev2->next = init1;
    }
    init1->prev = nodePrev2;
}

void SwitchEndNodes(Node* end1, Node* end2, DoubleLinkedList** list1, DoubleLinkedList** list2)
{
   Node* nodeNext1 = end1->next;
   Node* nodeNext2 = end2->next;

    if(nodeNext1 == NULL)
    {
        (*list1)->tail = end2;
    }
    else
    {
        end1->next = nodeNext2;
    }
    nodeNext2->prev = end1;

    if(nodeNext2 == NULL)
    {
        (*list2)->tail = end1;
    }
    else
    {
        end2->next = nodeNext1;
    }
    nodeNext1->prev = end2;
}

void SwitchGenes(DoubleLinkedList** geneSequence1, DoubleLinkedList** geneSequence2, DoubleLinkedList* switchSequence1, DoubleLinkedList* switchSequence2)
{
    // Start of genes lists default
    Node* startGenSeq1 = (*geneSequence1)->head;
    Node* startGenSeq2 = (*geneSequence2)->head;

    // Start of char list of switch sequence
    Node* startSwitchSeq1 = switchSequence1->head;
    Node* startSwitchSeq2 = switchSequence2->head;

    // Length of the SwitchSeq list
    int lenSwitchSeq1 = GetListLength(switchSequence1);
    int lenSwitchSeq2 = GetListLength(switchSequence2);

    // Init and End nodes of will switch
    Node* initRemoveSeq1 = NULL;
    Node* endRemoveSeq1 = NULL;

    Node* initRemoveSeq2 = NULL;
    Node* endRemoveSeq2 = NULL;

    int count = 0;
    int canSwitchList1 = 0;
    int canSwitchList2 = 0;

    while(startGenSeq1 != NULL)
    {
        canSwitchList1 = 0;
        canSwitchList1 = CanSwitch(startGenSeq1, startSwitchSeq1, lenSwitchSeq1);

        if(canSwitchList1 == 1)
        {
            initRemoveSeq1 = startGenSeq1;
            endRemoveSeq1 = GetEndNode(startGenSeq1, startSwitchSeq1, lenSwitchSeq1);

            // Verify if has value in 2° Sequence
            while(startGenSeq2 != NULL)
            {
                canSwitchList2 = 0;
                canSwitchList2 = CanSwitch(startGenSeq2, startSwitchSeq2, lenSwitchSeq2);

                if(canSwitchList2 == 1)
                {
                    initRemoveSeq2 = startGenSeq2;
                    endRemoveSeq2 = GetEndNode(startGenSeq2, startSwitchSeq2, lenSwitchSeq2);


                    startGenSeq2 = NULL;
                }

                if(canSwitchList2 != 1)
                {
                    // Iterate over 2° list
                    startGenSeq2 = startGenSeq2->next;
                }
            }
        }

        // SWWITCH NODES
        if(canSwitchList1 == 1 && canSwitchList2 == 1)
        {
            SwitchInitNodes(initRemoveSeq1, initRemoveSeq2, geneSequence1, geneSequence2);
            SwitchEndNodes(endRemoveSeq1, endRemoveSeq2, geneSequence1, geneSequence2);

            startGenSeq1 = (*geneSequence1)->head;
            startGenSeq2 = (*geneSequence2)->head;

            canSwitchList1 = 0;
            canSwitchList2 = 0;
        }
        else
        {
            startGenSeq1 = startGenSeq1->next;
        }
    }
}

DoubleLinkedList* FreeList(DoubleLinkedList* list)
{
    Node* start = list->head;
    Node* aux = NULL;

    if(list != NULL && list->head != NULL)
    {
        start = list->head;
    }

    while(start != NULL)
    {
         aux = start;
         start = start->next;

         if(aux != NULL)
         {
             free(aux);
         }
    }

    list->head = NULL;
    list->tail = NULL;

    return list;
}

int main()
{
    DoubleLinkedList* geneSequence1 = GetGeneSequence();
    DoubleLinkedList* geneSequence2 = GetGeneSequence();

    int pairsCount = GetInt();
    getchar();

    DoubleLinkedList* switchSequence1 = NULL;
    DoubleLinkedList* switchSequence2 = NULL;

    // Foreach pair in pairsCount
    for(int i = 0; i < pairsCount; i++)
    {
        switchSequence1 = GetGeneSequence();
        switchSequence2 = GetGeneSequence();

        SwitchGenes(&geneSequence1, &geneSequence2, switchSequence1, switchSequence2);

        // Clear the temp lists
        switchSequence1 = FreeList(switchSequence1);
        switchSequence2 = FreeList(switchSequence2);
    }

    // Print the Gene Sequences
    ShowGeneSequence(geneSequence1);
    printf("\n");
    ShowGeneSequence(geneSequence2);
    getchar();
    return 0;
}
