#include <stdio.h>
#include <stdlib.h>
#define LEN 5

struct list
{
    int value;
    struct list* next;
};
typedef struct list List; 

// List* CreateList(int arrayLen, int* array)
// {

// }

int main()
{
    // Implement a function that recieve a int array with n elements
    // and create a linked list from array elements.
    // OBS: If array is empty the function will return null list.

    int array[LEN] = {3, 8, 1, 7, 2};
    
    printf("Hello World!");
    return 0;
}