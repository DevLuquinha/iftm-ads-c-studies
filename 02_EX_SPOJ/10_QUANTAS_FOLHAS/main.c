#include <stdio.h>
#include <stdlib.h>

struct leaf
{
    int data;
    struct leaf *left;
    struct leaf *right;
};
typedef struct leaf Leaf;

int GetInt()
{
    int num = 0;
    scanf("%i", &num);

    return num;
}

Leaf *NewLeaf(int data)
{
    Leaf *leaf = malloc(sizeof(Leaf));
    leaf->data = data;
    leaf->left = NULL;
    leaf->right = NULL;

    return leaf;
}

Leaf *InsertLeaf(Leaf *root, int data)
{
    Leaf *newLeaf = NewLeaf(data);

    // 1. Verify if the tree is empty
    if (root == NULL)
    {
        root = newLeaf;
    }
    else
    {
        // 2. Create auxiliar leafs
        Leaf *lastParent = root;
        Leaf *currentLeaf = root;

        // 3. Iterate over tree
        while (currentLeaf != NULL)
        {
            lastParent = currentLeaf;
            // The new leaf is shorter than current
            if (newLeaf->data < currentLeaf->data)
            {
                currentLeaf = currentLeaf->left;
            }
            else
            {
                currentLeaf = currentLeaf->right;
            }
        }

        if (newLeaf->data < lastParent->data)
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

void ShowPreOrder(Leaf *root)
{
    if (root != NULL)
    {
        printf("%i ", root->data);
        ShowPreOrder(root->left);
        ShowPreOrder(root->right);
    }
}

void ShowInOrder(Leaf *root)
{
    if (root != NULL)
    {
        ShowInOrder(root->left);
        printf("%i ", root->data);
        ShowInOrder(root->right);
    }
}

void ShowPostOrder(Leaf *root)
{
    if (root != NULL)
    {
        ShowPostOrder(root->left);
        ShowPostOrder(root->right);
        printf("%i ", root->data);
    }
}

void GetLeafAmount(Leaf *root, int *amount)
{
    if (root != NULL)
    {
        GetLeafAmount(root->left, amount);
        if (root->left == NULL && root->right == NULL)
        {
            (*amount)++;
        }
        GetLeafAmount(root->right, amount);
    }
}

void ShowLeafs(Leaf *root)
{
    if (root != NULL)
    {
        ShowLeafs(root->left);
        if (root->left == NULL && root->right == NULL)
        {
            printf("%i eh uma folha\n", root->data);
        }
        ShowLeafs(root->right);
    }
}

Leaf *GetMinLeaf(Leaf *root)
{
    Leaf *current = root;
    while (current != NULL && current->left != NULL)
    {
        current = current->left;
    }

    return current;
}

Leaf *RemoveLeaf(Leaf *root, int leafValue)
{
    // 1. If the tree is empty
    if (root == NULL)
    {
        return root;
    }

    Leaf *lastParent = NULL;
    Leaf *currentLeaf = root;

    while (currentLeaf != NULL && currentLeaf->data != leafValue)
    {
        lastParent = currentLeaf;
        if (leafValue < currentLeaf->data)
        {
            currentLeaf = currentLeaf->left;
        }
        else
        {
            currentLeaf = currentLeaf->right;
        }
    }

    // 2. If dont find the value
    if (currentLeaf == NULL)
    {
        return root;
    }

    // --- CASE 3 (Two children) ---
    // Switch the current value by the sucessor
    // and remove the sucessor leaf.
    if (currentLeaf->left != NULL && currentLeaf->right != NULL)
    {
        // Find the Sucessor (smallest element of sub right tree)
        Leaf *sucessorParent = currentLeaf;
        Leaf *sucessor = currentLeaf->right;

        while (sucessor->left != NULL)
        {
            sucessorParent = sucessor;
            sucessor = sucessor->left;
        }

        // Copy the data of sucessor to current node
        currentLeaf->data = sucessor->data;

        // Now the remove target is the sucessor node (that have 0 or 1 child)
        // Update the pointers for the node below remove the sucessor
        currentLeaf = sucessor;
        lastParent = sucessorParent;
    }

    // --- Cases 1 e 2 (0 ou 1 Child) ---
    // Get the single child of exists (or NULL if leaf)
    Leaf *childLeaf;
    if (currentLeaf->left != NULL)
    {
        childLeaf = currentLeaf->left;
    }
    else
    {
        childLeaf = currentLeaf->right;
    }

    // If dont have parent, its removing the tree root
    if (lastParent == NULL)
    {
        free(currentLeaf);
        return childLeaf; // The new root is the son (or NULL)
    }

    // If has parent, do parent to apoint to grandson (childLeaf)
    if (lastParent->left == currentLeaf)
    {
        lastParent->left = childLeaf;
    }
    else
    {
        lastParent->right = childLeaf;
    }

    free(currentLeaf);
    return root;
}

int main()
{
    Leaf *root = NULL;

    // Insert values in tree
    int num = GetInt();
    while (num != -1)
    {
        root = InsertLeaf(root, num);
        num = GetInt();
    }

    int leafAmount = 0;

    GetLeafAmount(root, &leafAmount);

    ShowInOrder(root);

    RemoveLeafRecursive(root, 60);

    printf("\n");
    ShowInOrder(root);

    return 0;
}