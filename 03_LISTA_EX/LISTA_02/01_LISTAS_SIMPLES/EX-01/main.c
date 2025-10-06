#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct list {
    int value;
    struct list* next;
};
typedef struct list List;

List* NewNode(int value)
{
    List* newNode = NULL;
    newNode = malloc(sizeof(List));
    newNode->next = NULL;
    newNode->value = value;

    return newNode;
} 

List* AddValue(int value, List* lastNode)
{
    List* newNode = NewNode(value);
    List* lastNodeCpy = lastNode;

    // 1. Verificar se a lista é null
    if(lastNode == NULL)
    {
        lastNode = newNode;
    }
    else
    {
        while(lastNodeCpy->next != NULL)
        {
            lastNodeCpy = lastNodeCpy->next;
        }
        
        lastNodeCpy->next = newNode;
    }

    return lastNode;
}

void ShowList(List* list)
{
    printf("[");
    while(list != NULL)
    {
        printf("%i", list->value);
        if(list->next != NULL)
            printf(", ");
        list = list->next; 
    }
    printf("]");
}

List* RemoveLastValue(List* list)
{
    List* auxList = list;
    List* beforeNode;

    // 1. List é null?
    if(list != NULL)
    {
        while(auxList->next != NULL)
        {
            beforeNode = auxList;
            auxList = auxList->next;
        }
        // AQUI tem Before e o último
                
        // 2. List tem 1 elemento?
        if(auxList != list)
        {
            // 3. Remover o último valor
            beforeNode->next = NULL;
        }
        else // Aqui só tem um
        {
            list = NULL;
        }
    }
    
    return list;
}

int main()
{
    // Escreva uma função que retire o último elemento de uma lista
    // Deve retornar o ponteiro da lista alterada.
    
    // 1. Criar a lista
    List* defaultList = NULL;
    
    defaultList = AddValue(1, defaultList);
    defaultList = AddValue(2, defaultList);
    defaultList = AddValue(3, defaultList);
    defaultList = AddValue(4, defaultList);
    
    printf("Lista padrao: ");
    ShowList(defaultList);

    defaultList = RemoveLastValue(defaultList);

    // 2. Retirar o último elemento
    printf("\nLista com ultimo item removido: ");
    ShowList(defaultList);

    return 0;
}