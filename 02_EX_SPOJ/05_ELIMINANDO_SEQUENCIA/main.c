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

int GetInt()
{
    int num;
    scanf("%i", &num);

    return num;
}

int main()
{
    List* list = NewDefaultList();
    
    printf("Hello World");
    return 0;
}