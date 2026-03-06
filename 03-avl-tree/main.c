#include <stdlib.h>
#include <stdio.h>
#define LEN 15

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

int GetHeight(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = GetHeight(root->left);
    int rightHeight = GetHeight(root->right);

    if (leftHeight > rightHeight){
        return leftHeight + 1;
    }
    else 
    {
        return rightHeight + 1;
    }
}

int GetBalanceFactor(Node* node)
{
    int factor = 0;
    if (node != NULL)
    {
        // Balance Factor = Hl - Hr
        factor = GetHeight(node->left) - GetHeight(node->right);
    }

    return factor;
}

Node* RotationRight(Node* unbalanced)
{
    Node* child = unbalanced->left;
    unbalanced->left = child->right;
    child->right = unbalanced;

    return child;
}

Node* RotationLeft(Node* unbalanced)
{
    Node* child = unbalanced->right;
    unbalanced->right = child->left;
    child->left - unbalanced;

    return child;
}

Node* InsertNode(Node* root, int value)
{
    // 1. The root is null
    if (root == NULL)
    {
        Node* node = NewNode(value);
        return node;
    }
    else
    {
        // 2. The node on right
        if (value > root->value)
        {
            root->right = InsertNode(root->right, value);
        }
        else if (value < root->value) // 3. The node on left
        {
            root->left = InsertNode(root->left, value);
        }
        
        // 4. Calculate the current root factor
        int balanceFactor = GetBalanceFactor(root);

        // 5.1 Rotation for right
        if (balanceFactor > 1 && value < root->left->value)
        {
            return RotationRight(root);
        }

        // 5.2 Rotation for left
        if (balanceFactor < -1 && value > root->right->value)
        {
            return RotationLeft(root);
        }

        // 6.1 Double rotation (left and right)
        if (balanceFactor > 1 && value > root->left->value)
        {
            root->left = RotationLeft(root->left);
            return RotationRight(root);
        }

        // 6.2 Double rotation (right and left)
        if (balanceFactor < -1 && value < root->right->value)
        {
            root->right = RotationRight(root->right);
            return RotationLeft(root);
        }
        
        return root;
    }
}


void ShowInOrder(Node* root)
{
    if (root != NULL)
    {
        ShowInOrder(root->left);
        printf("%d, ", root->value);
        ShowInOrder(root->right);
    }
}

int main()
{
    int values[LEN] = { 25, 12, 40, 9, 18, 33, 50, 29, 37, 45, 60, 15, 20, 48, 55 };

    Node* root = NULL;

    for(int i = 0; i < LEN; i++)
    {
        root = InsertNode(root, values[i]);
    }

    printf("The current tree: ");
    ShowInOrder(root);

    return 0;
}