#include <stdio.h>
#include <stdlib.h>
#define LEN 5

struct list
{
    int value;
    struct list* next;
};
typedef struct list List; 

List* NewNode(int value)
{
    List* newNode = malloc(sizeof(List));
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

void AddValue(List* list, int value)
{
    List* auxList = list;

    while(auxList->next != NULL)
    {
        auxList = auxList->next;
    }

    // End node
    auxList->next = NewNode(value);
}

List* CreateList(int arrayLen, int* array)
{
    List* list = NULL;

    // 1. Array is empty
    if(arrayLen > 0)
    {
        // Foreach elem in array
        for(int i = 0; i < arrayLen; i++)
        {
            if(i == 0)
            {
                list = NewNode(array[i]);
            }    
            else
            {
                AddValue(list, array[i]);
            }
        }
    }

    return list;
}

void ShowArray(int len, int array[])
{
    printf("{");
    for(int i = 0; i < len; i++)
    {
        printf("%i", array[i]);
        if(i+1 != len)
            printf(", ");
    }
    printf("}");
}

void ShowList(List* list)
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

int main()
{
    // Implement a function that recieve a int array with n elements
    // and create a linked list from array elements.
    // OBS: If array is empty the function will return null list.

    int array[LEN] = {3, 8, 1, 7, 2};
    List* list = CreateList(LEN, array);

    printf("ARRAY: ");
    ShowArray(LEN, array);

    printf("\nLIST : ");
    ShowList(list);

    return 0;
}