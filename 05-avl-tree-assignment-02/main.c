#include <stdio.h>
#include <stdlib.h>

#define LEN 20

struct node
{
    struct node* left;
    struct node* right;
    int value;
};
typedef struct node Node;

Node* newNode(int value){
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->value = value;

    return node;
}

int getHeight(Node* root){
    if (root == NULL){
        return 0;
    }

    int lefthHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (lefthHeight > rightHeight){
        return lefthHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int getBalanceFactor(Node* root){
    if (root == NULL){
        return 0;
    }

    int leftHeight = getHeight(root->left);
    int heightHeight = getHeight(root->right);

    return leftHeight - heightHeight;
}

Node* rotateLeft(Node* unbalanced){
    Node* child = unbalanced->right;
    unbalanced->right = child->left;
    child->left = unbalanced;
    
    return child;
}

Node* rotateRight(Node* unbalanced){
    Node* child = unbalanced->left;
    unbalanced->left = child->right;
    child->right = unbalanced;

    return child;
}

Node* insertNode(Node* root, int value){
    // 1. Check if the node is a leaf
    if (root == NULL){
        Node* node = newNode(value);
        return node;
    }

    // 2. Iterate trought tree 
    if (value < root->value){
        // 2.1 Node is on left
        root->left = insertNode(root->left, value);
    } else if (value > root->value){
        // 2.2 Node is on right
        root->right = insertNode(root->right, value);
    }

    // 3. Get node balance factor
    int balanceFactor = getBalanceFactor(root);

    // 4.1 Simple Rotation left
    if (balanceFactor < -1 && value > root->right->value){
        return rotateLeft(root);
    }

    // 4.2 Simple Rotation right
    if (balanceFactor > 1 && value < root->left->value){
        return rotateRight(root);
    }

    // 4.3 Double Rotation left_right
    if (balanceFactor > 1 && value > root->left->value){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // 4.4 Double Rotation right_left
    if (balanceFactor < -1 && value < root->right->value){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void showInOrder(Node* root){
    if (root != NULL){
        showInOrder(root->left);
        printf("%i, ", root->value);
        showInOrder(root->right);
    }
}

Node* getNode(Node* root, int value){
    if (root == NULL){
        return NULL;
    }

    if (value < root->value){
        return getNode(root->left, value);
    } else if (value > root->value){
        return getNode(root->right, value);
    } 

    return root;
}

int isSameTree(Node* t1, Node* t2){
    if (t1 == NULL && t2 == NULL){
        return 1; // True
    }

    if (t1 == NULL || t2 == NULL){
        return 0; // False
    }

    if (t1->value != t2->value){
        return 0; // False
    }

    int isSameLeft = isSameTree(t1->left, t2->left);
    int isSameRight = isSameTree(t1->right, t2->right);

    if (isSameLeft == 1 && isSameRight == 1){
        return 1; // True
    } else {
        return 0; // False
    }
}

int isLeaf(Node* node){
    if (node == NULL){
        return 0; // False
    }

    if (node->left == NULL && node->right == NULL){
        return 1; // True
    } else {
        return 0; // False
    }
}

int hasChildren(Node* node){
    if (node == NULL){
        return 0; // False
    }

    if (node->left != NULL && node->right != NULL){
        return 1; // True
    } else {
        return 0; // False
    }
}

int isStrict(Node* root){
    if (root == NULL){
        return 1;
    }

    if (isLeaf(root) == 1){
        return 1;
    }

    if (hasChildren(root) == 1){
        int isStrictLeft = isStrict(root->left);
        int isStrictRight = isStrict(root->right);

        if (isStrictLeft == 1 && isStrictRight == 1){
            return 1;
        }
    }

    return 0;
}

int main(){
    int values[LEN] = { 30, 10, 20, 40, 50, 25, 45, 43, 41, 70, 65, 15, 5, 8, 55, 58, 57, 75, 80, 78 };
    Node* tree1 = NULL;
    Node* tree2 = NULL;

    for(int i = 0; i < LEN; i++){
        tree1 = insertNode(tree1, values[i]);
        tree2 = insertNode(tree2, values[i]);
    }
    
    printf("The BST 1: ");
    showInOrder(tree1);

    printf("\nThe BST 2: ");
    showInOrder(tree2);

    // 1. Verify if the trees are identical
    int isIdentical = isSameTree(tree1, tree2);
    if (isIdentical == 1){
        printf("\nThe trees are identical!");
    } else {
        printf("\nOPS! The trees are not identical!");
    }

    // 2. Verify if the tree is strict
    int isStrictTree = isStrict(tree1);
    if (isStrictTree == 1){
        printf("\nThe tree is STRICT!");
    } else {
        printf("\nOPS! The tree is not STRICT!");
    }

    return 0;
}