#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "listadupla.h"

struct nob
{
        bool folha;// se eh for folha
        int qtdChaves;
        struct nob* pai;
        Listad *listaChaves;
        struct nob* direita;
};

typedef struct nob Nob;

struct arvoreb
{
    Nob *raiz;
    int altura;
    int ordem; //nro maximo de filhos de um nó
};
typedef struct arvoreb Arvoreb;

struct chave
{
    int valorChave;
    Nob *filho;
};
typedef struct chave Chave;

void emOrdem(Nob* raiz);
Nob* cria_nob();
Chave* cria_chave(int valor);
Arvoreb* cria_arvoreb(int m);
Nob*  localiza_folha(Arvoreb *T, int k);
void insere_chave_lista_no(Nob *no, Chave *k);
void insere_valor_arvore (Arvoreb *T, int k);
Nob* divide_no(Nob* no_dividir);
Nob* cria_nova_raiz(Nob* no_inserir, Nob* novo, Chave *ch);
Arvoreb* libera_arvoreb(Arvoreb *T);
Nob* libera_nob(Nob* raiz);

#endif // ARVOREB_H_INCLUDED
