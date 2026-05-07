#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "arvoreBMais.h"

struct chave
{
    int valor;
    struct noB *filho;
    struct chave *ant, *prox;
};
typedef struct chave Chave;

struct lista
{
    Chave *inicio;
    Chave *fim;
};

typedef struct lista lista;

lista* cria_lista();

int lista_vazia(lista *l);

void insere_inicio(lista *l, Chave* valor);

void insere_fim(lista *l, Chave* valor);

Chave* remove_inicio_lista(lista *l);

Chave* remove_fim_lista(lista *l);

lista* quebra_lista(lista *l,int aux);

void insere_ordenado(Chave* valor,lista *l);

Chave* cria_chave(int valor);

Chave* cria_chave_vazia();
#endif // LISTA_H_INCLUDED
