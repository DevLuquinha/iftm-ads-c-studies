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

Node* AddInitValue(Node* list, int value)
{
    Node* aux;
    if(list != NULL)
    {
        aux = list;
        list = NewNode(value);
        list->next = aux;
    }
    else
    {
        list = NewNode(value);
    }

    return list;
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

Node* Reverse(Node* list)
{
    Node* newList = NULL;    

    while(list != NULL)
    {
        newList = AddInitValue(newList, list->value);
        list = list->next;
    }

    return newList;
}

void ReverseList(Node** list)
{
    Node* prev = NULL;
    Node* current = *list;
    Node* next;

    while(current != NULL)
    {
        // Store next
        next = current->next;
        
        // Invert the next
        current->next = prev;
        
        // Advance the pointers
        prev = current;
        current = next;
    }

    // Update the list
    *list = prev;
}

Node* Copy(Node* list)
{
    Node* newList = NULL;

    while (list != NULL)
    {
        AddValue(&newList, list->value);
        list = list->next;
    }
    
    return newList;
}

Node* CopyList(Node* list)
{
    Node* newList = NULL;
    Node* newNode = NULL;

    Node* aux = NULL;

    while(list != NULL)
    {
        // Create the new Node
        newNode = malloc(sizeof(Node));
        newNode->value = list->value;
        newNode->next = NULL;

        // Verify if list is NULL
        if(newList == NULL)
        {
            newList = newNode;
        }
        else
        {
            aux->next = newNode;            
        }

        aux = newNode;

        // Iterate over list
        list = list->next;
    }

    return newList;
}

int main()
{
    // Create the List Functions
    Node* list = NULL;
    AddValue(&list, 1);
    AddValue(&list, 2);
    AddValue(&list, 3);
    AddValue(&list, 4);
    
    // 1. MINIMUM/MAXIMUM
    Node* minimum = Minimum(list);
    Node* maximum = Maximum(list);
    
    // 2. REVERSE
    Node* reverse = Reverse(list);
    
    // 3. REVERSE
    // ReverseList(&list); Ex 3
    
    // 4. COPY
    // Node* listCopied = Copy(list);

    // 5. COPY
    Node* listCopied = CopyList(list);
    
    // Show Default List
    printf("\nLISTA: ");
    ShowList(list);

    printf("\n\n============ RESULTADOS ============");
    printf("\n1.MINIMUM/MAXIMUM");
    printf("\nO menor valor: %i", minimum->value);
    printf("\nO maior valor: %i", maximum->value);
    printf("\n====================================");
    printf("\n2.REVERSE");
    printf("\nLista Reverse:");
    ShowList(reverse);
    printf("\n====================================");
    printf("\n4.Copy");
    printf("\nLista Copy:");
    ShowList(listCopied);
    printf("\n====================================");
    return 0;
}
