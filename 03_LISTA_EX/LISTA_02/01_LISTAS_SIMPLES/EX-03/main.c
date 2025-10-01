#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct listStudent
{
    char name[80];
    float grade;
    struct listStudent* next;
};
typedef struct listStudent ListStudent;

ListStudent* NewNode(char* name, float grade)
{
    ListStudent* node = malloc(sizeof(ListStudent));
    strcpy(node->name, name);
    node->grade = grade;
    node->next = NULL;
    
    return node;
}

ListStudent* AddStudent(ListStudent* list, char* name, float grade)
{
    ListStudent* aux;
    ListStudent* newNode = NewNode(name, grade);

    // 1. The list is NULL?
    if(list != NULL)
    {
        aux = list;
        list = newNode;
        list->next = aux;
    }
    else
    {
        list = newNode;
    }

    return list;
}

void ShowList(ListStudent* list)
{
    printf("[");
    while(list != NULL)
    {
        printf("{NOME: %s, NOTA: %.2f}", list->name, list->grade);
        list = list->next;
        if(list != NULL)
            printf(", ");
    }
    printf("]");
}

int main()
{
    // Create a function that add a student in linked List
    // The function must return a list pointer

    ListStudent* list = NULL;
    list = AddStudent(list, "Lucas Emmanuel", 15.5);
    list = AddStudent(list, "Felipe Lara", 25.5);
    list = AddStudent(list, "Eduardo", 0.5);
    
    printf("LISTA: ");
    ShowList(list);

    return 0;
}