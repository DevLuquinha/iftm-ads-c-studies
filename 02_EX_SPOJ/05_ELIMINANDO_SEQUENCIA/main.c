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

}

void ShowList(List* list)
{
    Node* aux = list->start;

    printf("[");
    while (aux != NULL)
    {
        printf("%i");
        if(aux != NULL)
            printf(", ");
        aux = aux->next;
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
    
    printf("LISTA: ");
    ShowList(list);
    
    return 0;
}