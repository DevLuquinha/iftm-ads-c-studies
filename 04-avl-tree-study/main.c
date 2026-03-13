#include <stdio.h>
#include <stdlib.h>

#define LEN 3

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

    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);

    if (leftHeight > rightHeight){
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}

int getBalanceFactor(Node* root){
    if (root == NULL){
        return 0;
    }

    int leftH = getHeight(root->left);
    int rightH = getHeight(root->right);

    return leftH - rightH;
}

Node* rotateLeft(Node* unbalance){
    Node* child = unbalance->right;
    unbalance->right = child->left;
    child->left = unbalance;

    return child;
}

Node* rotateRight(Node* unbalance){
    Node* child = unbalance->left;
    unbalance->left = child->right;
    child->right = unbalance;

    return child;
}

Node* insertNode(Node* root, int value){
    if (root == NULL){
        Node* node = newNode(value);
        return node;
    }

    if (value < root->value){
        root->left = insertNode(root->left, value); 
    } else if (value > root->value){
        root->right = insertNode(root->right, value);
    }

    int balanceFactor = getBalanceFactor(root);

    // 1. Simple Rotation left
    if (balanceFactor < -1 && value > root->right->value){
        return rotateLeft(root);
    }

    // 2. Simple Rotation right
    if (balanceFactor > 1 && value < root->left->value){
        return rotateRight(root);
    }

    // 3. Double Rotation left_right
    if (balanceFactor > 1 && value > root->left->value){
        root->left = rotateLeft(root->left);
        return rotateRight(root);
    }

    // 4. Double Rotation right_left
    if (balanceFactor < -1 && value < root->right->value){
        root->right = rotateRight(root->right);
        return rotateLeft(root);
    }

    return root;
}

void showInOrder(Node* node){
    if (node != NULL){
        showInOrder(node->left);
        printf("%i, ", node->value);
        showInOrder(node->right);
    }
}

int main(){
    int values[LEN] = { 20, 15, 10 };
    Node* root = NULL;

    for (int i = 0; i < LEN; i++)
    {
        root = insertNode(root, values[i]);
    }
    
    showInOrder(root);

    return 0;
}