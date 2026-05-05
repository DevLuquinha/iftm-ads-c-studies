#ifndef ARVOREBMAIS_H_INCLUDED
#define ARVOREBMAIS_H_INCLUDED
#include "lista.h"
#include <Math.h>

struct noB
{
    int qtdChaves;
    struct noB *pai;
    struct noB *esquerda;
    struct lista *listaChaves;
    int folha; //1 se for folha, 0 caso contrario
    struct noB *anterior;
    struct noB *proximo;
};
typedef struct noB noB;

struct arvorebm
{
    int m; //ordem da arvore
    int altura;
    noB *raiz;
};

typedef struct arvorebm arvorebm;


noB* divide(noB* noCheio, int m);
void insere_chave_no(struct chave* k, noB *folha);
noB* localiza_folha(int k, arvorebm *tree);
noB* cria_nob();
noB* ajusta_raiz(noB* folha, noB* novo);
arvorebm* cria_arvore(int m);
void percursoEmOrdem(noB *raiz);
void  insere_chave_arvore(arvorebm* tree, int k);
void mostraArvore(arvorebm* tree);
void percursoEmNivelOtimizado(arvorebm *tree);
#endif // ARVOREBMAIS_H_INCLUDED

