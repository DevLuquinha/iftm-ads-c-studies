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

int IsLeaf(Node* node)
{
    if (node == NULL)
    {
        return -1; // Error handling
    }

    if (node->left == NULL && node->right == NULL)
    {
        return 1; // True
    }
    else
    {
        return 0; // False
    }
}

void IsFilled(Node* root, int* isFilled, int treeHeight)
{
    if (root != NULL)
    {
        // Check if the node is a leaf
        if (IsLeaf(root) == 1 )
        {
            if (treeHeight != root->heightLevel)
            {
                *isFilled = 0; 
            }
        }

        IsFilled(root->left, isFilled, treeHeight);
        IsFilled(root->right, isFilled, treeHeight);
    }
}

Node* GetMinNode(Node* node)
{
    Node* current = node;
    
    // Always will be the max right possible 
    while (current && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

Node* RemoveValue(Node* root, int value)
{
    // 1. Empty tree or node not found
    if (root == NULL)
    {
        return root;
    }

    // The node is left
    if (value < root->value)
    {
        root->left = RemoveValue(root->left, value);
    }
    else if (value > root->value)
    {
        root->right = RemoveValue(root->right, value);
    }
    else // FIND THE NODE!
    {
        // A CASE: Node with just one subtree
        if (root->left == NULL)
        {
            Node* temp = root->right;
            free(root); 

            return temp;
        }   
        else if (root->right == NULL)
        {
            Node* temp = root->left;
            free(root);

            return temp;
        }
        
        // B CASE: Node with two subtrees
        // Find the smalest value on right;
        Node* temp = GetMinNode(root->right);

        // Copy the value for current node
        root->value = temp->value;

        // Remove the "original" node
        root->right = RemoveValue(root->right, temp->value);
    }

    return root;
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

    // 2. Get the height (A)
    int treeHeight = 0;
    GetTreeHeight(root, &treeHeight);

    printf("\n\nA. The Tree Height is %i", treeHeight);

    // 3. Get the max (B)
    int maxValue = 0;
    GetMaxValue(root, &maxValue);

    printf("\nB. The max value on tree is %i", maxValue);

    // 4. Tree is filled? (C)
    int isFilled = 1; // True;
    IsFilled(root, &isFilled, treeHeight);

    if (isFilled == 0)
    {
        printf("\nC. The tree is NOT filled");
    }
    else if (isFilled == 1)
    {
        printf("\nC. The tree is filled");
    }

    // 5. Remove a value on tree (D)
    int valueToRemove = 45;

    printf("\nD. Tree before ( with %d ): ", valueToRemove);
    ShowInOrder(root);

    root = RemoveValue(root, valueToRemove);

    printf("\nD. Tree after  (remove %d): ", valueToRemove);
    ShowInOrder(root);

    return 0;
}
