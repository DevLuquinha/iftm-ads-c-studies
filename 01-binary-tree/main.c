#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* left;
    struct node* right;
};
typedef struct node Node;

int main()
{
    printf("Hello world!\n");
    return 0;
}
