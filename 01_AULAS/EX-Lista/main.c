#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node* next;
};
typedef struct node Node;

Node* NewNode(int value)
{
    // Inicializar a estrutura
    Node* new = NULL;
    new = malloc(sizeof(Node));

    // Atribuir os valores
    new->info = value;
    new->next = NULL;

    return new;
}

int main()
{
    // Inicializar a estrutura
    Node* node = NULL;
    node = NewNode(10);

    printf("TESTE\n");
    printf("%i", node->info);

    return 0;
}