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
    leaf->left  = NULL;
    leaf->right = NULL;

    return leaf;
}

Leaf* InsertLeaf(Leaf* root, int data)
{
    // 1. Create leaf
    Leaf* newLeaf = NewLeaf(data);

    if(root == NULL)
    {
        root = newLeaf;
    }
    else
    {
        // 2. Create the auxiliars vars
        Leaf* lastParent = NULL;
        Leaf* currentLeaf = root;

        while(currentLeaf != NULL)
        {
            // Save a copy of currentLeaf
            lastParent = currentLeaf;

            // The new leaf is smallest?
            if(data < currentLeaf->data)
            {
                currentLeaf = currentLeaf->left;
            }
            else
            {
                currentLeaf = currentLeaf->right;
            }
        }

        // 3. Insert the new leaf in the right location
        if(data < lastParent->data)
        {
            lastParent->left = newLeaf;
        }
        else
        {
            lastParent->right = newLeaf;
        }
    }

    return root;
}

void ShowInOrder(Leaf* root)
{
    if(root != NULL)
    {
        ShowInOrder(root->left);
        printf("%i ", root->data);
        ShowInOrder(root->right);
    }
}

Leaf* GetMinLeaf(Leaf* root)
{
    Leaf* lastLeaf = root;

    if(root != NULL)
    {
        while(lastLeaf->left != NULL)
        {
            lastLeaf = lastLeaf->left;
        }
    }

    return lastLeaf;
}

int main()
{
    // Create tree and insert some values
    Leaf* tree = NULL;
    tree = InsertLeaf(tree, 5);
    tree = InsertLeaf(tree, 3);
    tree = InsertLeaf(tree, 8);
    tree = InsertLeaf(tree, 4);
    tree = InsertLeaf(tree, 6);
    tree = InsertLeaf(tree, 1);
    tree = InsertLeaf(tree, 9);
    tree = InsertLeaf(tree, 7);

    Leaf* minLeaf = GetMinLeaf(tree);
    printf("O menor valor da arvore eh: %i", minLeaf->data);
    return 0;
}