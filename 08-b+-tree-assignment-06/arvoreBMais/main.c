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

    int valorChave = 10;
    Chave* chaveEncontrada = get_chave(valorChave, tree);
    if (chaveEncontrada == NULL){
        printf("\nO valor %i nao esta presente na arvore :(", valorChave);
    } else {
        printf("\nO valor %i ESTA presente na arvore :)", chaveEncontrada->valor);
    }

    float fatorOcupacao = get_fator_ocupacao(tree);
    printf("\nO fator de ocupacao eh %.2f", fatorOcupacao);

    printf("\n\n\FIM TRABALHO B+");

    return 0;
}
