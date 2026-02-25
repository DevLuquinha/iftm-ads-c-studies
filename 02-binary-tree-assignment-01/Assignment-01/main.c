#include <stdio.h>
#include <stdlib.h>

#define LEN 15

struct node
{
    int value;
    int heightLevel;
    struct node* left;
    struct node* right;
};
typedef struct node Node;

Node* NewNode(int value, int heightLevel)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    node->heightLevel = heightLevel;

    return node;
}

Node* InsertNode(Node* root, int value, int heightLevel)
{
    // 1. The root is null
    if (root == NULL)
    {
        Node* node = NewNode(value, heightLevel);
        return node;
    }
    else
    {
        // 2. The node on right
        if (value > root->value)
        {
            root->right = InsertNode(root->right, value, heightLevel + 1);
        }
        else if (value < root->value) // 3. The node on left
        {
            root->left = InsertNode(root->left, value, heightLevel + 1);
        }

        return root;
    }
}

void GetTreeHeight(Node* root, int* maxHeight)
{
    if (root != NULL)
    {
        if (root->heightLevel > *maxHeight)
        {
            *maxHeight = root->heightLevel;
        }
        GetTreeHeight(root->left, maxHeight);
        GetTreeHeight(root->right, maxHeight);
    }
}

void GetMaxValue(Node* root, int* maxValue)
{
    if (root != NULL)
    {
        if (root->value > *maxValue)
        {
            *maxValue = root->value;
        }

        GetMaxValue(root->left, maxValue);
        GetMaxValue(root->right, maxValue);
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

void ShowInOrder(Node* root)
{
    if (root != NULL)
    {
        ShowInOrder(root->left);
        printf("%i, ", root->value);
        ShowInOrder(root->right);
    }
}

void ShowPostOrder(Node* root)
{
    if (root != NULL)
    {
        ShowInOrder(root->left);
        ShowInOrder(root->right);
        printf("%i, ", root->value);
    }
}

int main()
{
    int values[LEN] = { 25, 12, 40, 9, 18, 33, 50, 29, 37, 45, 60, 15, 20, 48, 55 };

    Node* root = NULL;

    for(int i = 0; i < LEN; i++)
    {
        root = InsertNode(root, values[i], 0);
    }

    // 1. Show the tree in order
    printf("The tree IN ORDER: ");
    ShowInOrder(root);

    // 2. Get the height
    int treeHeight = 0;
    GetTreeHeight(root, &treeHeight);

    printf("\nThe Tree Height is %i\n", treeHeight);

    // 3. Get the max
    int maxValue = 0;
    GetMaxValue(root, &maxValue);

    printf("\nThe max value on tree is %i", maxValue);
    return 0;
}
