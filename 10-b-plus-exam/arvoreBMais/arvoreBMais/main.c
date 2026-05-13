#include <stdio.h>
#include <stdlib.h>
#include "arvoreBMais.h"

int main()
{
    arvorebm* tree;
    int vet[] = {5, 4, 6, 7, 8, 2, 9, 10, 11, 20, 30, 29, 25, 40, 26, 28, 22, 21};
    int tam=18;

    tree = cria_arvore(5);
    for (int i=0; i<tam; i++) {
        insere_chave_arvore(tree,vet[i]);
    }

    printf("\nArvore B+\n\n");
    mostraArvore(tree);
    printf("\n\n");

    int soma = somaChaves(tree);
    printf("\n2. A soma dos valores presentes na arvore eh: %i", soma);

    printf("\n3. ");

    Chave* chave = exibirValores(30, 3, tree);
    if (chave != NULL){
        printf("\nA chave retornada eh %i", chave->valor);
    }

    return 0;
}
