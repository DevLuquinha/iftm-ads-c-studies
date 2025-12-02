#include <stdlib.h>
#include <stdio.h>

struct leaf
{
    int data;
    struct leaf* left;
    struct leaf* right;
};
typedef struct leaf Leaf;

Leaf* NewLeaf(int data)
{
    Leaf* leaf = malloc(sizeof(Leaf));
    leaf->data = data;
    leaf->left = NULL;
    leaf->right = NULL;

    return leaf;
}

Leaf* InsertLeaf(Leaf* root, int data)
{
    Leaf* newLeaf = NewLeaf(data);

    if(root == NULL)
    {
        root = newLeaf;
    }
    else
    {
        Leaf* currentParent = NULL;
        Leaf* currentLeaf = root;

        // Iterave over the tree to find the last leaf
        while(currentLeaf != NULL)
        {
            // Storage the 'parent'
            currentParent = currentLeaf;

            // The new leaf is smallest
            if(newLeaf->data < currentLeaf->data)
            {
                currentLeaf = currentLeaf->left;
            }
            else
            {
                currentLeaf = currentLeaf->right;
            }
        }

        // Here the currentLeaf is null and his parent is the 
        // last node of the tree
        
        // The new leaf needs to insert in left
        if(newLeaf->data < currentParent->data)
        {
            currentParent->left = newLeaf;
        }
        else
        {
            currentParent->right - newLeaf;
        }
    }

    return root;
}

void InOrder(Leaf* root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%i ", root->data);
        InOrder(root->right);
    }
}

int main()
{
    // Leaf* root = NULL;
    // root = InsertLeaf(root, 7);
    // root = InsertLeaf(root, 4);
    // root = InsertLeaf(root, 3);

    // printf("[ ");
    // InOrder(root);
    // printf("]");

    printf("Hello, World!\n");

    return 0;
}