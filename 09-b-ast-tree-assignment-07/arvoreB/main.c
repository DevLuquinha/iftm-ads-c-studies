#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

int main()
{
    printf("\nArvore B\n\n");
    Arvoreb *tree;
    int vet[] = {30, 50, 05, 10, 25, 60, 55, 40, 45, 15, 35, 20, 28, 38, 32};
    int tam=15;
    tree = cria_arvoreb(3);

    for (int i=0; i<tam; i++){
        insere_valor_arvore(tree,vet[i]);
    }

    emOrdem(tree->raiz);

    printf("\n\n\n");
    return 0;
}
