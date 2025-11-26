#include <stdio.h>
#include <stdlib.h>

struct leaf
{
    int data;
    struct leaf* left;
    struct leaf* right;
};
typedef struct leaf Leaf;

int GetInt()
{
    int num = 0;
    scanf("%i", &num);

    return num;
}

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

    // 1. Verify if the tree is empty
    if(root == NULL)
    {
        root = newLeaf;
    }
    else
    {
        // 2. Create auxiliar leafs
        Leaf* lastParent = root;
        Leaf* currentLeaf = root;
        
        // 3. Iterate over tree
        while(currentLeaf != NULL)
        {
            lastParent = currentLeaf;
            // The new leaf is shorter than current
            if(newLeaf->data < currentLeaf->data)
            {
                currentLeaf = currentLeaf->left;
            }
            else
            {
                currentLeaf = currentLeaf->right;
            }
        }

        if(newLeaf->data < lastParent->data)
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

void ShowPreOrder(Leaf* root)
{
    if(root != NULL)
    {
        printf("%i ", root->data);
        ShowPreOrder(root->left);
        ShowPreOrder(root->right);
    }
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

void ShowPostOrder(Leaf* root)
{
    if(root != NULL)
    {
        ShowPostOrder(root->left);
        ShowPostOrder(root->right);
        printf("%i ", root->data);
    }
}

void GetLeafAmount(Leaf* root, int* amount)
{
    if(root != NULL)
    {
        GetLeafAmount(root->left, amount);
        if(root->left == NULL && root->right == NULL)
        {
            (*amount)++;
        }
        GetLeafAmount(root->right, amount);
    }
}

void ShowLeafs(Leaf* root)
{
    if(root != NULL)
    {
        ShowLeafs(root->left);
        if(root->left == NULL && root->right == NULL)
        {
            printf("%i eh uma folha\n", root->data);
        }
        ShowLeafs(root->right);
    }
}

int main()
{
    Leaf* root = NULL;
    
    // Insert values in tree
    int num = GetInt(); 
    while (num != -1) 
    { 
        root = InsertLeaf(root, num); 
        num = GetInt(); 
    }

    int leafAmount = 0;

    GetLeafAmount(root, &leafAmount);
    
    printf("%i", leafAmount);
    return 0;
}