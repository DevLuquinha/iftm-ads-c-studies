#include <stdio.h>
#include <stdlib.h>
#include "arvoreb.h"

    int main()
    {
        Arvoreb *tree;
        int vet[] = {30, 50, 05, 10, 25, 60, 55, 40, 45, 15, 35, 20, 28, 38, 32};
        int tam=15;
        tree = cria_arvoreb(5);

        for (int i=0; i<tam; i++){
            insere_valor_arvore(tree,vet[i]);
        }

        imprime_arvore_visual(tree);

        return 0;
    }
