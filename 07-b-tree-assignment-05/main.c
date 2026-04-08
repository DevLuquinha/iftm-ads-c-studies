#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

#define LEN 15

int main()
{
    int vet[LEN] = {25, 12, 40, 9, 18, 33, 50, 29, 37, 45, 60, 15, 20, 48, 55};
    Arvoreb *tree = cria_arvoreb(3);

    for (int i=0; i<LEN; i++){
        insere_valor_arvore(tree, vet[i]);
    }

    printf("Arvore B: ");
    emOrdem(tree->raiz);

    int antImediato = get_ant_imediato(tree->raiz, 33);
    printf("\n1-) O antecessor de 33 eh: %d", antImediato);

    int countElements = 0;
    count_elements(tree->raiz, &countElements);
    printf("\n3-) A quantidade de elementos na arvore eh: %d", countElements);

    return 0;
}
