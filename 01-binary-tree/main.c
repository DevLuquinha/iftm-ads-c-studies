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

void ShowPreOrder(Node* root)
{
    if (root != NULL)
    {
        printf("%i, ", root->value);
        ShowPreOrder(root->left);
        ShowPreOrder(root->right);
    }
}

int main()
{
    printf("The Binary Search Tree");
    Node* root = NULL;
    int values[11] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65, 85};

    for(int i = 0; i < 11; i++)
    {
        root = InsertNode(values[i], root);
    }

    printf("\n\nShow Pre Order Binary Tree: ");
    ShowPreOrder(root);

    return 0;
}
