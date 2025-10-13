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

int main()
{
    printf("Hello World");

    return 0;
}
