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

int main()
{
    // Create a function that add a student in linked List
    // The function must return a list pointer

    printf("Hello World!");
    return 0;
}