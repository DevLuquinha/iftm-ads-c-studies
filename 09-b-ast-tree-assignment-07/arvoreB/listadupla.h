#ifndef LISTADUPLA_H_INCLUDED
#define LISTADUPLA_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

struct nod
{
    void* info;
    struct nod *prox;
    struct nod *ant;
};

typedef struct nod Nod;

struct listad
{
    Nod *ini;
    Nod *fim;
};

typedef struct listad Listad;

Nod* cria_nod(void*);

Listad* cria_listad();

void insere_inicio_listad(Listad*, void*);

void libera_listad(Listad* L);

void insere_fim_listad(Listad*, void* valor);

//Nod* insere_ordenado_listad(Listad*, int valor);

void* remove_inicio_listad(Listad *L);

void* remove_fim_listad(Listad *L);

void mostra_listad(Listad *L);

int lista_vazia(Listad *L);
Listad* divide_lista(Listad *L, int nro_elementos);



#endif // LISTADUPLA_H_INCLUDED
