#include <stdio.h>
#include <stdlib.h>

#define LEN 16 // 3

struct node
{
    int value;
    struct node* left;
    struct node* right;
    int height;
};
typedef struct node Node;

Node* newNode(int value){
    Node* node = (Node*)malloc(sizeof(Node));
    node->left = NULL;
    node->right = NULL;
    node->value = value;
    node->height = 0;

    return node;
}

int getHeight(Node* node){
    if (node == NULL){
        return -1;
    }

    return node->height;
}

void updateHeight(Node* node){
    int heightLeft = getHeight(node->left);
    int heightRight = getHeight(node->right);

    if (heightLeft > heightRight){
        node->height = heightLeft + 1;
    } else {
        node->height = heightRight + 1;
    }
}

int getBalanceFactor(Node* root){
    if (root == NULL){
        return 0;
    }

    int factor = getHeight(root->left) - getHeight(root->right);
    return factor;
}

Node* insertNode(Node* root, int value){
    // 1. If the node is a leaf
    if (root == NULL){
        Node* node = newNode(value);
        return node;
    }

    // 2. Normal insert flow
    if (value > root->value){
        root->right = insertNode(root->right, value);
    } else if (value < root->value){
        root->left = insertNode(root->left, value);
    }

    // 3. Calculate the height value
    updateHeight(root);

    // 4. Calculate de balance factor
    int balanceFactor = getBalanceFactor(root);
    
    return root;
}

int main(){
    // a) 10 - 15 - 20
    // b) 20 - 15 - 10
    // c) 15 - 20 - 10
    // d) 10 - 20 - 15
    Node* root = NULL;
    // int values[LEN] = { 10, 25, 20 };
    int values[LEN] = { 25, 12, 40, 9, 18, 33, 50, 29, 37, 45, 60, 15, 15, 20, 48, 55 }; 
    
    for (int i = 0; i < LEN; i++){
        root = insertNode(root, values[i]);
    }
    
    printf("Hello world!");

    return 0;
}