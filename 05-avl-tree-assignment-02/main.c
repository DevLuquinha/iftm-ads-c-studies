#include <stdio.h>
#include <stdlib.h>

#define LEN 22

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

    return root;
}

void showInOrder(Node* root){
    if (root != NULL){
        showInOrder(root->left);
        printf("%i, ", root->value);
        showInOrder(root->right);
    }
}

int main(){
    int values[LEN] = { 0, 10, 20, 40, 50, 25, 45, 43, 41, 70, 65, 15, 5, 8, 55, 58, 57, 75, 80, 78 };
    Node* root = NULL;

    for(int i = 0; i < LEN; i++){
        root = insertNode(root, values[i]);
    }

    printf("The BST: ");
    showInOrder(root);

    return 0;
}