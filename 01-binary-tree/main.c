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

int GetInt()
{
    int num = 0;
    fflush(stdin);
    scanf("%i", &num);

    return num;
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

Node* FindNode(Node* root, int value)
{
    if (root != NULL)
    {
        // 1. The root is the value target  [1, 2, 3, 4, 5]
        if (root->value == value)
        {
            return root;
        }
        else if (value > root->value) // Value on right
        {
            root = FindNode(root->right, value);
        }
        else if (value < root->value) // Value on left
        {
            root = FindNode(root->left, value);
        }
    }

    return root;
}

int main()
{
    printf("The Binary Search Tree");
    Node* root = NULL;
//    int values[11] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65, 85};
    int values[9] = { 8, 4, 12, 2, 6, 10, 14, 1, 3 };

    for(int i = 0; i < 9; i++)
    {
        root = InsertNode(values[i], root);
    }

    printf("\n\nShow Pre Order Binary Tree: ");

    ShowPreOrder(root);

    printf("\n\nType the target value: ");
    int num = GetInt();

    Node* targetNode = FindNode(root, num);

    if (targetNode != NULL)
    {
        printf("\nThe value %i is on the tree", targetNode->value);
    }
    else
    {
        printf("\nThe value %i doesn't exists in tree", num);
    }

    return 0;
}
