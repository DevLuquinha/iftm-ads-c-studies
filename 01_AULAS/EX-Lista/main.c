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
    printf("\n[");
    while(list != NULL)
    {
        printf("%i", list->info);
        list = list->next;
        if(list != NULL)
            printf(", ");
    }
    printf("]");
}

int main()
{
    // Inicializar a lista
    Node* list = NULL;
    list = AddStartValue(list, 10);
    list = AddEndValue(list, 3);
    
    ShowList(list);
    
    // list = AddStartValue(list, 20);

    return 0;
}