#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cupon
{
    int code;
    int quantity;
};
typedef struct cupon Cupon;

struct node
{
    Cupon cupon;
    struct node* next;
};
typedef struct node Node;

struct list
{
    Node *node;
    struct list* next;
};
typedef struct list List;

Node* NewNode(int code, int quantity);
void AddValueNode(Node** list, int code, int quantity);
List* NewList(Node* nodeList);
void AddValueFinalList(Node** list, Cupon cupon);
void AddValueList(List** list, Node* nodeList);
void IterateOverList(List* list, int limit);
int GetInt();
void ShowList(Node* list, int limit);

Node* NewNode(int code, int quantity)
{
    Node* node = malloc(sizeof(Node));
    node->cupon.code = code;
    node->cupon.quantity = quantity;
    node->next = NULL;

    return node;
}

void AddValueNode(Node** list, int code, int quantity)
{
    if(*list == NULL)
    {
        *list = NewNode(code, quantity);
    }
    else
    {
        Node* current = *list;
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = NewNode(code, quantity);
    }
}

List* NewList(Node* nodeList)
{
    List* newList = malloc(sizeof(List));
    newList->node = nodeList;
    newList->next = NULL;

    return newList;
}

void AddValueFinalList(Node** list, Cupon cupon)
{
    Node* current = NULL;
    Node* previous = NULL;

    if(*list == NULL)
    {
        *list = NewNode(cupon.code, cupon.quantity);
    }
    else
    {
        current = *list;
        while(current->next != NULL && current->cupon.code != cupon.code)
        {
            previous = current;
            current = current->next;
        }
        // Aqui ou o código já existe ou chegou no fim
        
        if(current->cupon.code == cupon.code)
        {
            current->cupon.quantity += cupon.quantity;
        }
        else
        {
            if(previous == NULL)
            {
                current->next = NewNode(cupon.code, cupon.quantity);
            }
            else
            {
                // Percorrer até o final
                while(current->next != NULL)
                {
                    current = current->next;
                }

                current->next = NewNode(cupon.code, cupon.quantity);
            }
        }
    }
}

void AddValueList(List** list, Node* nodeList)
{
    if(*list == NULL)
    {
        *list = NewList(nodeList);
    }
    else
    {
        List* current = *list;
        while(current->next != NULL)
        {
            current = current->next;
        }

        current->next = NewList(nodeList);
    }
}

int ListLength(Node* list)
{
    int i = 0;
    while(list != NULL)
    {
        i++;
        list = list->next;
    }

    return i;
}

void SortList(Node* list)
{
    int listLen = ListLength(list);    
    
    Node* current = list; // i
    Node* nextNode = list; // j 

    Cupon aux;

    for(int i = 0; i < listLen; i++)
    {
        current = list;
        while(current->next != NULL) // Corrije o j - 1
        {
            nextNode = current->next;

            if(nextNode->cupon.quantity > current->cupon.quantity)
            {
                aux.code = nextNode->cupon.code;
                aux.quantity = nextNode->cupon.quantity;

                nextNode->cupon.code = current->cupon.code;
                nextNode->cupon.quantity = current->cupon.quantity;

                current->cupon.code = aux.code;
                current->cupon.quantity = aux.quantity;
            }
            else if(current->cupon.quantity == nextNode->cupon.quantity)
            {
                if(nextNode->cupon.code < current->cupon.code) 
                {
                    aux.code = nextNode->cupon.code;
                    aux.quantity = nextNode->cupon.quantity;

                    nextNode->cupon.code = current->cupon.code;
                    nextNode->cupon.quantity = current->cupon.quantity;

                    current->cupon.code = aux.code;
                    current->cupon.quantity = aux.quantity;
                }
            }
            
            current = current->next;
        }
    }
}

void ShowList(Node* list, int limit)
{
    SortList(list);
    int i = 0;

    while(list != NULL && i < limit)
    {
        printf("%i: %i\n", list->cupon.code, list->cupon.quantity);
        i++;
        list = list->next;
    }
}

void IterateOverList(List* list, int limit)
{
    Node* finalList = NULL;

    Node* nodeAux;
    Cupon cuponAux;

    while(list != NULL)
    {
        nodeAux = list->node;
        while(nodeAux != NULL)
        {
            cuponAux = nodeAux->cupon;
            
            // Adicionar na nova lista e verificar
            AddValueFinalList(&finalList, cuponAux);

            // Iterate Over Mini List
            nodeAux = nodeAux->next;
        }
        
        list = list->next;
    }

    // Aqui tem a lista final
    ShowList(finalList, limit);
}

int GetInt()
{
    int value;
    scanf("%i", &value);

    return value;
}

int main()
{
    List* list = NULL;
    Node* cuponList = NULL;

    // C. Quantidade de Cupons Fiscais
    int cuponsQuant = GetInt();

    // N. Número de itens mais vendidos para listar
    int nItens = GetInt();

    // Variaveis auxiliar
    int itemsCupon;
    Node* listItems = NULL;
    int cuponCode;
    int cuponQuant;

    // Para cada item em C
    for(int i = 0; i < cuponsQuant; i++)
    {
        itemsCupon = GetInt();
        listItems  = NULL; 
        for(int j = 0; j < itemsCupon; j++)
        {
            // Adiciona os itens na lista node
            cuponCode = GetInt();
            cuponQuant = GetInt();
            AddValueNode(&listItems, cuponCode, cuponQuant);
        }

        // Adiciona a lista node na LISTA
        AddValueList(&list, listItems);
    }

    IterateOverList(list, nItens);
}