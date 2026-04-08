#ifndef ARVOREB_H_INCLUDED
#define ARVOREB_H_INCLUDED
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "listadupla.h"

struct nob
{
    bool folha;          // Indica se um nó é folha (leaf node)
    int qtdChaves;       // Quantidade de chaves
    struct nob* pai;     // Ponteiro para nó PAI (parent node)
    Listad *listaChaves; // Lista duplamente encadeade contendo as "chaves"
    struct nob* direita; // Ponteiro para o filho mais a DIREITA (rightmost child)
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
    int valorChave; // O valor numerico em si
    Nob *filho;     // Ponteiro para filho a ESQUERDA
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
int get_ant_imediato(Nob* raiz, int valorBase);
void count_elements(Nob* raiz, int* amount);

#endif // ARVOREB_H_INCLUDED
