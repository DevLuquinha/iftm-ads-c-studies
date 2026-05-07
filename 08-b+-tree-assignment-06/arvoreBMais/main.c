#include <stdio.h>
#include <stdlib.h>
#include "arvoreBMais.h"

int main()
{
    arvorebm* tree;
    int vet[] = {10, 20, 5, 6, 12, 30, 7, 17, 3, 25, 1};
    int tam=11;

    tree = cria_arvore(3);
    for (int i=0; i<tam; i++) {
        insere_chave_arvore(tree,vet[i]);
    }

    printf("\nArvore B+\n\n");
    mostraArvore(tree);
    printf("\n\n");

    struct chave* chave = get_chave(30, tree);
    if (chave != NULL){
        printf("\nO valor eh: %i", chave->valor);
    } else {
        printf("\nDeu ruim parceiro.");
    }

    return 0;
}
