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

Leaf* GetMaxLeaf(Leaf* root)
{
    Leaf* lastLeaf = root;

    if(root != NULL)
    {
        while(lastLeaf->right != NULL)
        {
            lastLeaf = lastLeaf->right;
        }
    }

    return lastLeaf;
}

void IsTreeEquals(Leaf* tree1, Leaf* tree2, int* isEquals)
{
    // Just return, without change the result
    if(tree1 == NULL && tree2 == NULL)
    {
        return;
    }

    // If one of leafs is NULL
    if(tree1 == NULL || tree2 == NULL)
    {
        *isEquals = 1; // False
        return;
    }

    // If the values are diferents
    if(tree1->data != tree2->data)
    {
        *isEquals = 1; // False
        return;
    }

    if(*isEquals == 0) // If until equals
    {
        IsTreeEquals(tree1->left, tree2->left, isEquals);
        IsTreeEquals(tree1->right, tree2->right, isEquals);
    }
}

void GetHeight(Leaf* startLeaf, int* height)
{
    if(startLeaf == NULL)
    {
        return;
    }

    if(startLeaf->left != NULL || startLeaf->right != NULL)
    {
        *height = (*height) + 1;
    }

    if(startLeaf != NULL)
    {
        GetHeight(startLeaf->left, height);
        GetHeight(startLeaf->right, height);
    }
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

    // The Second tree
    Leaf* tree2 = NULL;
    tree2 = InsertLeaf(tree2, 5);
    tree2 = InsertLeaf(tree2, 3);
    tree2 = InsertLeaf(tree2, 8);
    tree2 = InsertLeaf(tree2, 4);
    tree2 = InsertLeaf(tree2, 6);
    tree2 = InsertLeaf(tree2, 1);
    tree2 = InsertLeaf(tree2, 9);
    tree2 = InsertLeaf(tree2, 7);

    Leaf* minLeaf = GetMinLeaf(tree);
    printf("- O menor valor da arvore eh: %i", minLeaf->data);
    
    Leaf* maxLeaf = GetMaxLeaf(tree);
    printf("\n- O maior valor da arvore eh: %i", maxLeaf->data);
    
    // Verify if the tree is equals
    int isEqual = 0; // By default the tree are identics;
    IsTreeEquals(tree, tree2, &isEqual);
    
    if(isEqual == 0)
    {
        printf("\nAS ARVORES SAO IDENTICAS");
    }
    else
    {
        printf("\nAS ARVORES NAO SAO IDENTICAS");
    }

    // Get the tree height
    int treeHeight = 0;
    GetHeight(tree, &treeHeight);

    printf("A altura da arvore eh: %i", treeHeight);
    return 0;
}