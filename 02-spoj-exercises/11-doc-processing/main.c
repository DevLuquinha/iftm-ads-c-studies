#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct node
{
    int data;
    struct node* prev;
    struct node* next;
};
typedef struct node Node;

struct doublyList
{
    Node* init;
    Node* end;
};
typedef struct doublyList DoublyList;

int GetInt()
{
    int num = 0;
    scanf("%d", &num);
    return num;
}

Node* NewNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

DoublyList* NewDoublyList()
{
    DoublyList* list = (DoublyList*)malloc(sizeof(DoublyList));
    list->init = NULL;
    list->end = NULL;
    return list;
}

void AddEndValueInDoublyList(DoublyList* list, int data)
{
    Node* newNode = NewNode(data);

    if(list->end == NULL)
    {
        list->init = newNode;
        list->end = newNode;
    }
    else
    {
        newNode->prev = list->end;
        list->end->next = newNode;
        list->end = newNode;
    }
}

void RemoveInitValueInDoublyList(DoublyList* list)
{
    if(list->init != NULL)
    {
        Node* temp = list->init;
        list->init = list->init->next;

        if(list->init == NULL)
            list->end = NULL;
        else
            list->init->prev = NULL;

        free(temp);
    }
}

void RemoveEndValueInDoublyList(DoublyList* list)
{
    if(list->end != NULL)
    {
        Node* temp = list->end;
        list->end = list->end->prev;

        if(list->end == NULL)
            list->init = NULL;
        else
            list->end->next = NULL;

        free(temp);
    }
}

void ReverseDoublyList(DoublyList* list)
{
    if (list == NULL || list->init == NULL) return;

    Node* current = list->init;
    Node* temp = NULL;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; 
    }

    // Change the init and end pointers
    temp = list->init;
    list->init = list->end;
    list->end = temp;
}

int main()
{
    DoublyList* processDoublyList = NewDoublyList();

    // Create and clear the command input
    char command[100]; 
    strcpy(command, "");

    // Create and clear the command id
    int commandId = 0;

    // Create the boolean type
    int isNormal = 1; // Default is true, 1 = Normal, 0 = Urgent.
    
    int processAmount = 0;
    int commandAmount = GetInt();
    
    for(int i = 0; i < commandAmount; i++)
    {
        // O espaço antes de %s ignora whitespace (enter, espaços), dispensando o getchar()
        scanf(" %s", command);
        
        if(strcmp(command, "URGENT") == 0)
        {
            if (isNormal == 1) {
                // Change Normal -> Urgent
                // The list doesn't need to be reversed here based on the transfer logic
                isNormal = 0; 
            }
        }
        else if(strcmp(command, "NORMAL") == 0)
        {
            if (isNormal == 0) {
                // Change Urgent -> Normal
                // The list needs to be reversed here based on the transfer logic
                ReverseDoublyList(processDoublyList);
                isNormal = 1; 
            }
        }
        else if(strcmp(command, "ADD") == 0)
        {
            commandId = GetInt();
            AddEndValueInDoublyList(processDoublyList, commandId);
            processAmount++;
        }
        else if(strcmp(command, "PROCESS") == 0)
        {
            if(processDoublyList->init != NULL)
            {
                if(isNormal == 1)
                {
                    // Normal: Remove at the beginning (Queue)
                    printf("%d\n", processDoublyList->init->data);
                    RemoveInitValueInDoublyList(processDoublyList);
                }
                else 
                {
                    // Urgent: Remove at the end (Stack)
                    printf("%d\n", processDoublyList->end->data);
                    RemoveEndValueInDoublyList(processDoublyList);
                }
                processAmount--;
            }
            else
            {
                printf("EMPTY\n");
            }
        }
        else if(strcmp(command, "STATUS") == 0)
        {
            printf("%d\n", processAmount);
        }
    }
    
    return 0;
}