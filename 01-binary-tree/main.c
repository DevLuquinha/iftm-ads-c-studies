#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node* left;
    struct node* right;
};
typedef struct node Node;

Node* NewNode(int value)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
