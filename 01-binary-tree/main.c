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

Node* InsertNode(int value, Node* root)
{
    Node* newNode = NewNode(value);

    // 1. The Root is null
    if (root == NULL)
    {
        return newNode;
    }
    else
    {
        // 2. The value on right
        if (value > root->value)
        {
            root->right = InsertNode(value, root->right);
        }
        else if (value < root->value)
        {
            root->left = InsertNode(value, root->left);
        }
        else
        {
            printf("\nThe %i already exists in the tree!", value);
        }

        return root;
    }
}

int main()
{
    printf("Hello world!\n");
    return 0;
}
