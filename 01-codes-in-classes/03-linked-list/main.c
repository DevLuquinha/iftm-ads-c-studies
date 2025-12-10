#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* next;
};
typedef struct node Node;

Node* NewNode(int value)
{
    // Inicializar a estrutura
    Node* new = NULL;
    new = malloc(sizeof(Node));

    // Atribuir os valores
    new->info = value;
    new->next = NULL;

    return new;
}

Node* AddStartValue(Node* list, int value)
{
    Node* node;
    if(list == NULL)
    {
        list = NewNode(value);
    }
    else
    {
        node = NewNode(value);
        node->next = list;
        list = node;
    }
    
    return list;
}

Node* AddEndValue(Node* list, int value)
{
    // Começa com a lista
    Node* currentNode = list;

    // 1. Verificar se a lista é NULL
    if(list == NULL)
    {
        list = NewNode(value);
    }
    else
    {
        // 2. Laço até chegar no NULL
        while(currentNode->next != NULL)
        {
            currentNode = currentNode->next;
        }
        
        // 3. Atribuir o valor para o ultimo nó
        currentNode->next = NewNode(value);
    }
    
    return list;
}

void ShowList(Node* list)
{
    printf("[");
    while(list != NULL)
    {
        printf("%i", list->info);
        list = list->next;
        if(list != NULL)
            printf(", ");
    }
    printf("]");
}

Node* RemoveInitialValue(Node* list)
{
    Node* firstElem = list;

    // 1. Verificar se a lista é NULL
    if(list != NULL)
    {
        // 2. Verificar se só tem 1 elemento
        if(firstElem->next == NULL) 
        {
            firstElem = NULL;
        }
        else
        {
            firstElem = firstElem->next;
        }
    }

    return firstElem;
}

Node* RemoveLastValue(Node** list)
{
    Node* currentValue = *list;
    Node* beforeValue, *return_value = NULL; 

    // 1. Verificar se a lista é NULL
    if(*list != NULL)
    {
        // 2. Percorrer até o último node
        while(currentValue->next != NULL)
        {
            beforeValue = currentValue;
            currentValue = currentValue->next;
        }

        // 3. Verificar se a lista tem mais de 1 elemento
        if(*list != currentValue) // Possui mais de um elemento
        {
            beforeValue->next = currentValue->next;
        }
        else // Possui apenas um elemento
        {
            *list = currentValue->next;
        }        
            
        return_value = currentValue;
    }

    return return_value;
}

int main()
{
    // Inicializar a lista
    Node* list = NULL;
    list = AddStartValue(list, 10);
    list = AddStartValue(list, 20);
    list = AddEndValue(list, 3);
    
    printf("LISTA INICIAL: ");
    ShowList(list);
    
    printf("\n\nLISTA FINAL: ");
    Node* last =  RemoveLastValue(&list);
    ShowList(list);

    printf("\nULTIMO: ");
    ShowList(last);
    return 0;
}