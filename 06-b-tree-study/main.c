#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

int main()
{
    printf("\nArvore B\n\n");
    Arvoreb *tree;
    int vet[] = { 10, 20, 30, 40, 50, 60, 70 };
    int tam = 7;
    tree = cria_arvoreb(3);

    for (int i=0; i<tam; i++){
        insere_valor_arvore(tree, vet[i]);
    }

    emOrdem(tree->raiz);

    // Contém valor
    if(contem_valor(tree->raiz, 60)){
        printf("\nTEM VALOR PORRA");
    } else {
        printf("\nNEM TEM MANO");
    }

    return 0;
}
