#include "lista.h"

Chave* cria_chave_vazia() {
    Chave *novo;
    novo = (Chave*)malloc(sizeof(Chave));
    novo->valor = 0;
    novo->ant = novo->prox = NULL;
    novo->filho = NULL;
    return novo;
}

Chave* cria_chave(int valor) {
    Chave *novo;
    novo = (Chave*)malloc(sizeof(Chave));
    novo->valor = valor;
    novo->ant = novo->prox = NULL;
    novo->filho = NULL;
    return novo;
}

lista* cria_lista() {
    lista *l;
    l = (lista*)malloc(sizeof(lista));
    l->inicio = NULL;
    l->fim = NULL;
    return l;
}

int lista_vazia(lista *l) {
    if (l->inicio == NULL) {
        return 1;
    } else {
        return 0;
    }
}

void insere_inicio(lista *l, Chave *novo) {
    novo->prox = l->inicio;
    if (l->fim == NULL) {
        l->fim = l->inicio = novo;
    } else {
        l->inicio->ant = novo;
        novo->prox = novo;
        l->inicio = novo;
    }
}

void insere_fim(lista *l, Chave *novo) {
    if (l->inicio == NULL) {
        l->inicio = l->fim = novo;
    } else {
        l->fim->prox = novo;
        novo->ant = l->fim;
        l->fim = novo;
    }
}

Chave* remove_inicio_lista(lista *l) {
    Chave *aux;
    if (lista_vazia(l) == 1) {
        return NULL;
    } else {
        if (l->inicio == l->fim) {
            aux = l->inicio;
            l->inicio = NULL;
            l->fim = NULL;
            return aux;
        } else {
            aux = l->inicio;
            l->inicio = l->inicio->prox;
            l->inicio->ant = NULL;
            aux->prox = NULL;
            return aux;
        }
    }
}

Chave* remove_fim_lista(lista *l) {
    Chave *aux;
    if (lista_vazia(l) == 1) {
        return NULL;
    } else {
        if (l->inicio == l->fim) {
            aux = l->fim;
            l->inicio = NULL;
            l->fim = NULL;
            return aux;
        } else {
            aux = l->fim;
            l->fim = l->fim->ant;
            l->fim->prox = NULL;
            aux->ant = NULL;
            return aux;
        }
    }
}

lista* quebra_lista(lista *l, int aux) {
    lista* l2;
    Chave* auxlista;
    l2 = cria_lista();
    if (l->inicio == NULL) {
        return NULL;
    } else {
        auxlista = l->inicio;
        while (aux != 0) {
            auxlista = auxlista->prox;
            aux--;
        }
        l2->inicio = auxlista;
        l2->fim = l->fim;
        l->fim = auxlista->ant;
        l->fim->prox = NULL;
        l2->inicio->ant = NULL;
        auxlista->ant = NULL;
        return l2;
    }
}

void insere_ordenado(Chave* novo, lista *l) {
    Chave* aux1;
    Chave* aux2;
    aux1 = l->inicio;
    if (l->inicio == NULL) {
        l->inicio = novo;
        l->fim = novo;
    } else {
        if (novo->valor < l->inicio->valor) {
            l->inicio->ant = novo;
            novo->prox = l->inicio;
            l->inicio = novo;
        } else {
            if (novo->valor > l->fim->valor) {
                l->fim->prox = novo;
                novo->ant = l->fim;
                l->fim = novo;
            } else {
                while (aux1 != NULL && novo->valor > aux1->valor) {
                    aux1 = aux1->prox;
                }
                novo->prox = aux1;
                aux2 = aux1->ant;
                novo->ant = aux1->ant;
                aux1->ant = novo;
                aux2->prox = novo;
            }
        }
    }
}
