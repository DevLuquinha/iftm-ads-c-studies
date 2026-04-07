#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

int main()
{
    printf("\nArvore B\n\n");
        Arvoreb *tree;
    int vet[] = {25, 12, 40, 9, 18, 33, 50, 29, 37, 45, 60, 15, 20, 48, 55};
    int tam=15;
    tree = cria_arvoreb(3);

    for (int i=0; i<tam; i++){
        insere_valor_arvore(tree, vet[i]);
    }

    emOrdem(tree->raiz);

    printf("\n\n");

    int antImediato = get_ant_imediato(tree->raiz, 48);
    printf("O antecessor de 48 eh: %d", antImediato);

    return 0;
}
