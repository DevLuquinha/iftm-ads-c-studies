#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

int main()
{
    printf("\nArvore B\n\n");
    Arvoreb *tree;
    int vet[] = {23,45,65,28,33,64,7,34,9,87,90,14,54,38};
    int tam=14;
    tree = cria_arvoreb(3);

    for (int i=0; i<tam; i++){
        insere_valor_arvore(tree,vet[i]);
    }

    emOrdem(tree->raiz);

    printf("\n\n\n");
    return 0;
}
