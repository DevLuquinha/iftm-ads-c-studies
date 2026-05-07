#include "arvoreBMais.h"

arvorebm* cria_arvore(int m) {
    arvorebm* tree = (arvorebm*)malloc(sizeof(arvorebm));
    tree->m = m;
    tree->altura = 0;
    tree->raiz = NULL;
    return tree;
}

noB* cria_nob() {
    noB* novo = (noB*) malloc(sizeof(noB));
    novo->esquerda = NULL;
    novo->pai = NULL;
    novo->folha = 1;
    novo->qtdChaves = 0;
    novo->listaChaves = cria_lista();
    novo->anterior = NULL;
    novo->proximo = NULL;
    return novo;
}

Chave* get_chave(int valorChave, arvorebm* tree){
    if (tree->raiz == NULL){
        return NULL;
    }

    noB* aux = tree->raiz;
    Chave* chaveAux = NULL;

    // 1. Enquanto não for folha
    while(aux->folha != 1){
        // 2. A chave está para esquerda
        if (valorChave < aux->listaChaves->inicio->valor){
            aux = aux->esquerda;
        } else{
            chaveAux = aux->listaChaves->inicio;

            // 3. Iterar sobre cada chave da lista de chaves
            while(chaveAux != NULL && valorChave >= chaveAux->valor){
                chaveAux = chaveAux->prox;
            }

            // 4. Não está na lista de chaves
            if (chaveAux == NULL){
                aux = aux->listaChaves->fim->filho;
            } else if (chaveAux->ant == NULL){
                aux = chaveAux->filho;
            } else {
                aux = (noB*)chaveAux->ant->filho;
            }
        }
    }

    if (aux != NULL){
        chaveAux = aux->listaChaves->inicio;
        while(chaveAux != NULL && valorChave != chaveAux->valor){
            chaveAux = chaveAux->prox;
        }
    } else {
        chaveAux = NULL;
    }

    return chaveAux;
}

float get_fator_ocupacao(arvorebm* tree){
    if (tree == NULL || tree->raiz == NULL){
        return 0;
    }

    float folhasUsadas = 0;
    float capacidadeTotal = 0;

    noB* aux = tree->raiz;

    // 1. Enquanto não for folha
    while(aux->folha != 1){
        aux = aux->esquerda;
    }

    // 2. Iterar sobre cada folha
    while(aux != NULL){
        folhasUsadas += aux->qtdChaves;
        capacidadeTotal += tree->m - 1;

        aux = aux->proximo;
    }

    float fatorOcupacao = 0;
    if (capacidadeTotal != 0){
        fatorOcupacao = folhasUsadas / capacidadeTotal;
    }

    return fatorOcupacao;
}

int get_soma_folhas(arvorebm* tree){
    if (tree == NULL || tree->raiz == NULL){
        return 0;
    }

    noB* aux = tree->raiz;
    while (aux->folha != 1){
        aux = aux->esquerda;
    }

    Chave* chaveAux = NULL;

    int soma = 0;
    while (aux != NULL){
        chaveAux = aux->listaChaves->inicio;
        while(chaveAux != NULL){
            soma += chaveAux->valor;
            chaveAux = chaveAux->prox;
        }

        aux = aux->proximo;
    }

    return soma;
}

// LOCALIZA FOLHA PARA INSERIR K
noB* localiza_folha(int k, arvorebm *tree) {
    noB *aux = tree->raiz;
    Chave *auxL;
    noB *resposta;

    if (tree->raiz == NULL) {
        resposta = NULL;
    } else {
        while (aux->folha != 1) {
            if (k < aux->listaChaves->inicio->valor) {
                aux = aux->esquerda;
            } else {
                auxL = aux->listaChaves->inicio;
                while (auxL != NULL && k > auxL->valor) {
                    auxL = auxL->prox;
                }

                if (auxL == NULL) {
                    aux = aux->listaChaves->fim->filho;
                } else {
                    aux = (noB*)auxL->ant->filho;
                }
            }
        }
        resposta = aux;
    }
    return resposta;
}

//INSERE VALOR K NA LISTA DE UM NO
void insere_chave_no(Chave* k, noB *folha) {
    insere_ordenado(k, folha->listaChaves);
    folha->qtdChaves++;
}

//INSERE UM VALOR NA ÁRVORE
void insere_chave_arvore(arvorebm* tree, int k) {
    Chave* chave = NULL;
    noB* aux;
    noB* novo;

    // Localiza a folha onde a chave 'k' deve ser inserida
    noB* noBParaInserir = localiza_folha(k, tree);

    if (noBParaInserir == NULL) {
        // Caso a árvore esteja vazia, cria a primeira folha (que será a raiz)
        aux = cria_nob();
        insere_chave_no(cria_chave(k), aux);  // Cria e insere a chave na nova folha
        tree->raiz = aux;                  // Define a nova folha como raiz
        tree->altura++;                    // Atualiza a altura da árvore
    } else {
        int continuar = 1;
        // Enquanto precisar inserir ou dividir e subir chaves
        while (continuar) {
            if (chave == NULL) {
                // Primeira inserção: cria a chave com o valor 'k'
                insere_chave_no(cria_chave(k), noBParaInserir);
            } else {
                // Inserções subsequentes usam a chave promovida da divisão anterior
                insere_chave_no(chave, noBParaInserir);
            }

            // Se a folha ainda tem espaço, encerra o loop
            if (noBParaInserir->qtdChaves < tree->m) {
                continuar = 0;
            } else { // Se não, temos que dividir
                // Caso contrário, divide o nó cheio
                novo = divide(noBParaInserir, tree->m);

                if (noBParaInserir->pai == NULL) {
                    // Se o nó dividido era a raiz, cria uma nova raiz
                    tree->raiz = ajusta_raiz(noBParaInserir, novo);
                    tree->altura++;       // Aumenta a altura da árvore
                    continuar = 0;        // Após criar nova raiz, finaliza inserção
                } else {
                    // Se não era a raiz, prepara a chave para subir para o pai
                    if (noBParaInserir->folha) {
                        // Se o nó dividido é folha, pega o menor valor do novo nó
                        chave = cria_chave(novo->listaChaves->inicio->valor);
                        chave->filho = novo;
                    } else {
                        // Se for nó interno, remove a primeira chave da nova lista
                        chave = remove_inicio_lista(novo->listaChaves);
                        novo->esquerda = chave->filho;
                        chave->filho = NULL;
                    }
                    // Continua subindo a chave no nó pai
                    noBParaInserir = noBParaInserir->pai;
                }
            }
        }
    }
}

noB* divide(noB* noCheio, int m) {
    // Calcula o ponto de divisão da lista de chaves (meio do nó)
    int meio = floor(m / 2.0);

    // Quebra a lista de chaves do nó cheio em duas: a original e a nova (parte da direita)
    lista *listaNova = quebra_lista(noCheio->listaChaves, meio);
    Chave* aux = listaNova->inicio;

    // Inicializa atributos do novo nó com base no nó original
    noB* novoNo = cria_nob();
    novoNo->pai = noCheio->pai;
    novoNo->esquerda = NULL;
    novoNo->folha = noCheio->folha;
    novoNo->listaChaves = listaNova;
    novoNo->qtdChaves = m - meio;     // Número de chaves no novo nó
    noCheio->qtdChaves = meio;        // Número de chaves que restaram no nó original

    // Se o nó que está sendo dividido **não é folha**
    if (noCheio->folha == 0) {
        // Atualiza os ponteiros pai dos filhos das chaves do novo nó
        while (aux != NULL) {
            if (aux->filho != NULL) {
                ((noB*)aux->filho)->pai = novoNo;
            }
            aux = aux->prox;
        }
    } else { // Se o nó é folha, atualiza os ponteiros de lista encadeada entre folhas
        novoNo->anterior = noCheio;               // novoNo aponta para o nó anterior (noCheio)
        if (noCheio->proximo != NULL) {
            noCheio->proximo->anterior = novoNo;  // ajusta o anterior do próximo nó
            novoNo->proximo = noCheio->proximo;   // novoNo aponta para o próximo do nó cheio
        }
        noCheio->proximo = novoNo;                // nó cheio aponta para novoNo como seu próximo
    }

    return novoNo;  // Retorna o novo nó criado após a divisão
}

noB* ajusta_raiz(noB* raizOriginal, noB* novo) {
    noB* novaRaiz = cria_nob();  // Cria um novo nó que será a nova raiz
    novaRaiz->folha = 0;         // A nova raiz nunca é folha
    novaRaiz->esquerda = raizOriginal;  // A subárvore à esquerda da raiz é a raiz antiga
    novaRaiz->pai = NULL;        // Como é a raiz, ela não possui pai

    // Se o nó que foi dividido era uma folha
    if (raizOriginal->folha == 1) {
        // Insere na nova raiz o menor valor do novo nó (isso promove a chave para a raiz)
        insere_chave_no(cria_chave(novo->listaChaves->inicio->valor), novaRaiz);
    } else {
        // Remove a primeira chave do novo nó (caso seja nó interno)
        Chave* chave = remove_inicio_lista(novo->listaChaves);

        // Insere essa chave na nova raiz
        insere_chave_no(chave, novaRaiz);

        // Ajusta os ponteiros de filho: o ponteiro filho da chave removida agora é o esquerdo do novo nó
        novo->esquerda = chave->filho;
        chave->filho = NULL;
    }

    // Atualiza os ponteiros pai de folha e novo
    raizOriginal->pai = novaRaiz;
    novo->pai = novaRaiz;

    // O ponteiro filho da chave na nova raiz agora aponta para o novo nó (direita da chave promovida)
    novaRaiz->listaChaves->inicio->filho = novo;

    // Ajusta os ponteiros de lista encadeada entre folhas
    raizOriginal->proximo = novo;
    novo->anterior = raizOriginal;

    return novaRaiz;  // Retorna a nova raiz criada
}

void mostraNo(noB* raiz) {
    Chave* aux = raiz->listaChaves->inicio;
    printf("[");
    while (aux != NULL) {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("] ");
}

void mostrar_nivel(noB* raiz, int nivel) {
    if (raiz == NULL) return;

    if (nivel == 1) {
        mostraNo(raiz);
    } else {
        // Mostra os filhos do ponteiro à esquerda primeiro
        mostrar_nivel(raiz->esquerda, nivel - 1);

        // Em seguida, mostra os filhos dos nós nas chaves
        Chave* aux = raiz->listaChaves->inicio;
        while (aux != NULL) {
            mostrar_nivel((noB*)aux->filho, nivel - 1);
            aux = aux->prox;
        }
        printf("   ");
    }
}

void mostraArvore(arvorebm* tree) {
    for (int i = 0; i <= tree->altura; i++) {
        mostrar_nivel(tree->raiz, i + 1); // níveis começam do 1
        printf("\n");
    }
}
