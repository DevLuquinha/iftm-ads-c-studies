#include "arvoreB.h"
#include <math.h>

int get_chave(Nod *aux) {
    return ((Chave*)aux->info)->valorChave;
}

void set_chave(Nod *aux, int valor) {
    ((Chave*)aux->info)->valorChave = valor;
}

Nob* get_filho(Nod* aux) {
    return ((Chave*)aux->info)->filho;
}

void set_filho(Nod* aux, Nob* pont) {
    ((Chave*)aux->info)->filho = pont;
}

void emOrdem(Nob* raiz) {
    Nod *aux;
    if (raiz != NULL) {
        aux = raiz->listaChaves->ini;
        while(aux != NULL) {
            emOrdem(((Chave*)aux->info)->filho);
            printf("%d ", get_chave(aux));
            aux=aux->prox;
        }
        emOrdem(raiz->direita);
    }
}


Arvoreb* cria_arvoreb(int m) {
    Arvoreb *arvoreb = (Arvoreb*) malloc(sizeof(Arvoreb));
    arvoreb->altura = 0;
    arvoreb->ordem = m;
    arvoreb->raiz = cria_nob();

    return arvoreb;
}

Nob* cria_nob() {
    Nob* novo = (Nob*)malloc(sizeof(Nob));
    novo->direita = NULL;
    novo->folha = true;
    novo->pai = NULL;
    novo->qtdChaves = 0;
    novo->listaChaves = cria_listad();
    return novo;
}

Chave* cria_chave(int valor) {
    Chave *ch = (Chave*)malloc(sizeof(Chave));
    ch->filho = NULL;
    ch->valorChave = valor;
    return ch;
}

//encontre uma folha para inserir a chave  K
Nob*  localiza_folha(Arvoreb *T, int k) {
    Nob *aux = T->raiz;
    Nod *aux_lista;

    if (aux != NULL) {
        while (!aux->folha) {
            aux_lista = aux->listaChaves->ini;
            while (aux_lista != NULL && k > get_chave(aux_lista) ){
                aux_lista = aux_lista->prox;
            }

            if (aux_lista == NULL)
                aux = aux->direita;
            else
                aux = get_filho(aux_lista);
        }
    }
    return aux;
}

void insere_chave_lista_no(Nob *no, Chave *k) {
    Nod* aux;

    //PERCORRE A LISTA ATÉ PASSAR TODOS OS NÚMEROS MENORES
    aux = no->listaChaves->ini;
    while (aux != NULL && k->valorChave > get_chave(aux)) {
        aux = aux->prox;
    }
    //SE ESTIVER AINDA ESTIVER NO INICIO, ELE DEVE SER INSERIDO NO COMEÇO DA LISTA
    if (aux == no->listaChaves->ini) {
        insere_inicio_listad(no->listaChaves,(void*)k);
    } else {
        //SE PASSOU O ÚLTIMO ELEMENTO
        if (aux == NULL)
            insere_fim_listad(no->listaChaves,(void*)k);
        else { //SE NÃO FOI NO INICIO, E NEM NO FINAL, INSERÇÃO NO MEIO, CORRIGIR AS LIGAÇÕES APÓS INSERÇÃO
            Nod* novo = cria_nod((void*)k);
            novo->prox = aux;
            novo->ant = aux->ant;
            aux->ant->prox = novo;
            aux->ant = novo;
        }
    }
    no->qtdChaves++;
}

void imprime_nivel(Nob* no, int nivel_atual, int nivel_alvo) {
    // 1. Condição de parada (recursão)
    if (no == NULL) {
        return;
    }

    // 2. Condição de Impressão (nivel_alvo vem do loop)
    if (nivel_atual == nivel_alvo) {
        printf("[");

        // Percorre a lista duplamente encadeada de chaves deste nó
        Nod* aux = no->listaChaves->ini;
        while(aux != NULL){
            printf("%d ", get_chave(aux));
            aux = aux->prox;
        }

        printf("] ");
    }
    // 3. Condição de Descida (Precisa descer na árvore)
    else {
        Nod* aux = no->listaChaves->ini;

        // 3.1. Dispara a recursão para os filhos à esquerda de cada chave do nó
        while (aux != NULL) {
            // Desce um nível (nivel_atual + 1) passando o ponteiro do filho esquerdo
            imprime_nivel(get_filho(aux), nivel_atual + 1, nivel_alvo);
            aux = aux->prox;
        }

        // 3.2. Dispara a recursão para o ponteiro fixo à direita (último filho)
        imprime_nivel(no->direita, nivel_atual + 1, nivel_alvo);
    }
}

void imprime_arvore_visual(Arvoreb* T) {
    // 1. Validação de segurança: verifica se a árvore foi inicializada e se não está vazia
    if (T == NULL || T->raiz == NULL) {
        printf("Arvore vazia!\n");
        return;
    }

    printf("\n=== Arvore B* ===\n");

    // 2. Laço principal: percorre os níveis da árvore de 0 (raiz) até a profundidade máxima (altura)
    for (int i = 0; i <= T->altura; i++) {
        imprime_nivel(T->raiz, 0, i);
        printf("\n");
    }

    printf("=================\n");
}

bool canInsertRight(Nob* no_atual, Arvoreb *T) {
    // 1. A raiz não tem pai (não tem irmãos).
    if (no_atual->pai == NULL) {
        return false;
    }

    // 2. Busca no pai qual chave possui o ponteiro para o 'no_atual'
    Nod* chave_aponta_atual = no_atual->pai->listaChaves->ini;

    // Percorre a lista do pai até encontrar a chave cujo "filho" seja o nó atual
    while (chave_aponta_atual != NULL && get_filho(chave_aponta_atual) != no_atual) {
        chave_aponta_atual = chave_aponta_atual->prox;
    }

    // 3. Se achou a chave, identifica o irmão da direita
    if (chave_aponta_atual != NULL) {
        Nob* irmao_direito = NULL;

        // O irmão direito é o filho da PRÓXIMA chave da lista do pai
        if (chave_aponta_atual->prox != NULL) {
            irmao_direito = get_filho(chave_aponta_atual->prox);
        } else {
            // Se não houver próxima chave, o irmão é o ponteiro 'direita' fixo do pai
            irmao_direito = no_atual->pai->direita;
        }

        // 4. Valida se o irmão existe e se possui espaço para redistribuição
        if (irmao_direito != NULL && irmao_direito->qtdChaves < T->ordem - 1) {
            return true;
        } else {
            return false;
        }
    }

    // Se chave_aponta_atual for NULL, o no_atual já é o ponteiro 'direita' do pai.
    // Portanto, ele é o último filho e não possui vizinho à direita.
    return false;
}

bool canInsertLeft(Nob* no_atual, Arvoreb *T) {
    // 1. A raiz não tem pai (não tem irmãos).
    if (no_atual->pai == NULL) {
        return false;
    }

    // 2. Busca no pai qual chave possui o ponteiro para o 'no_atual'
    Nod* chave_aponta_atual = no_atual->pai->listaChaves->ini;
    while (chave_aponta_atual != NULL && get_filho(chave_aponta_atual) != no_atual) {
        chave_aponta_atual = chave_aponta_atual->prox;
    }

    Nob* irmao_esquerdo = NULL;

    // 3. Cenário A: O 'no_atual' é o ponteiro 'direita' do pai (não está na lista)
    if (chave_aponta_atual == NULL) {
        // O vizinho da esquerda é o filho atrelado à ÚLTIMA chave do pai
        irmao_esquerdo = get_filho(no_atual->pai->listaChaves->fim);
    }
    // 4. Cenário B: O 'no_atual' está na lista, então o vizinho é a chave ANTERIOR
    else if (chave_aponta_atual->ant != NULL) {
        irmao_esquerdo = get_filho(chave_aponta_atual->ant);
    }

    // 5. Valida se o irmão existe e se possui espaço para redistribuição
    if (irmao_esquerdo != NULL && irmao_esquerdo->qtdChaves < T->ordem - 1) {
        return true;
    }

    return false;
}

void insere_valor_arvore (Arvoreb *T, int k) {
    Chave *chaveAInserir = cria_chave(k);
    Nob *no_inserir = localiza_folha(T, k);
    Nob *novo;
    int sair = 0;
    while(!sair) {
        insere_chave_lista_no(no_inserir, chaveAInserir);
        if (no_inserir->qtdChaves < T->ordem)//se esta acima do limite
            sair = 1;//nao está acima do limite, acaba a insercao
        else {// está acima do limite

            // 1. Tenta redistribuir para o irmão da DIREITA (apenas folhas)
            if (no_inserir->folha && canInsertRight(no_inserir, T)){
                // 1.1 Remove a última chave do nó atual (que estourou o limite)
                Chave* ultima_chave_removida = (Chave*) remove_fim_listad(no_inserir->listaChaves);
                no_inserir->qtdChaves--;

                // 1.2 Localiza o nó na lista do pai que atua como separador entre o nó atual e o irmão da direita
                Nod* no_separador_pai = no_inserir->pai->listaChaves->ini;
                while (no_separador_pai != NULL && get_filho(no_separador_pai) != no_inserir) {
                    no_separador_pai = no_separador_pai->prox;
                }

                if (no_separador_pai != NULL){
                    // A chave do pai desce para o irmão, e a removida sobe para o pai
                    int valor_antigo_separador = get_chave(no_separador_pai);
                    set_chave(no_separador_pai, ultima_chave_removida->valorChave);
                    ultima_chave_removida->valorChave = valor_antigo_separador;

                    // Identifica o irmão da direita
                    Nob* irmao_direita;
                    if (no_separador_pai->prox != NULL) {
                        irmao_direita = get_filho(no_separador_pai->prox);
                    } else {
                        irmao_direita = no_inserir->pai->direita;
                    }

                    // Insere a chave que desceu no início do irmão da direita
                    insere_chave_lista_no(irmao_direita, ultima_chave_removida);
                    sair = 1;
                }
            }
            // 2. Tenta redistribuir para o irmão da ESQUERDA (apenas folhas)
            else if (no_inserir->folha &&canInsertLeft(no_inserir, T)) {
                // Remove a primeira chave do nó atual
                Chave* chave_subindo = (Chave*) remove_inicio_listad(no_inserir->listaChaves);
                no_inserir->qtdChaves--;

                // Localiza o separador correto no pai para o Vizinho Esquerdo
                Nod* no_separador_pai = no_inserir->pai->listaChaves->ini;
                while (no_separador_pai != NULL && get_filho(no_separador_pai) != no_inserir) {
                    no_separador_pai = no_separador_pai->prox;
                }

                // Ajuste do separador para o lado esquerdo.
                if (no_separador_pai == NULL) {
                    no_separador_pai = no_inserir->pai->listaChaves->fim;
                } else {
                    no_separador_pai = no_separador_pai->ant;
                }

                if (no_separador_pai != NULL) {
                    // A chave do pai desce para o irmão, e a removida sobe para o pai
                    int valor_antigo_pai = get_chave(no_separador_pai);
                    set_chave(no_separador_pai, chave_subindo->valorChave);
                    chave_subindo->valorChave = valor_antigo_pai;

                    // Insere no final do irmão da esquerda
                    Nob* irmao_esquerda = get_filho(no_separador_pai);
                    insere_chave_lista_no(irmao_esquerda, chave_subindo);
                    sair = 1;
                }
            }
            else {
                novo = divide_no(no_inserir);
                chaveAInserir = (Chave*)remove_fim_listad(no_inserir->listaChaves); // A variável chave A inserir Agora recebe o valor retirado
                no_inserir->qtdChaves--;

                if (no_inserir->pai == NULL) {//dividiu a raiz
                    T->raiz = cria_nova_raiz(no_inserir, novo, chaveAInserir);
                    T->altura++;
                    sair=1;
                } else
                    no_inserir = no_inserir->pai;
            }
        }
    }
}

Nob* divide_no(Nob* no_dividir) {
    Chave* ch_subir;
    Nod* aux;

    // Calcula o número de elementos que serão movidos para o novo nó
    int nro_elem_no_dividir = ceil(no_dividir->qtdChaves/2.0);

    // Divide a lista de chaves do nó em duas partes
    Listad* lista_nova = divide_lista(no_dividir->listaChaves, nro_elem_no_dividir);

    // Cria um novo nó para a árvore e Atribui a lista de chaves dividida (nova) ao novo nó
    Nob *novo_no = cria_nob();
    novo_no->listaChaves = lista_nova;

    // Mantém o mesmo estado de folha e pai
    novo_no->folha = no_dividir->folha;
    novo_no->pai = no_dividir->pai;

    // Atualiza a quantidade de chaves do novo nó e do nó original
    novo_no->qtdChaves = no_dividir->qtdChaves - nro_elem_no_dividir;
    no_dividir->qtdChaves = nro_elem_no_dividir;

    // Caso o nó a ser dividido tenha um nó à direita, atualiza a ligação entre eles
    if (no_dividir->direita != NULL) {
        novo_no->direita = no_dividir->direita;
        novo_no->direita->pai = novo_no;
    }

    // Pega a chave que será promovida (a última chave do nó dividido)
    ch_subir = (Chave*)no_dividir->listaChaves->fim->info;

    // Atualiza o ponteiro "direita" do nó original para apontar para o filho que chave promovida tinha antes de subir
    no_dividir->direita = ch_subir->filho;

    // Atualiza o filho da chave promovida para o nó original
    ch_subir->filho = no_dividir;

    // Abaixo, tratamos a atualização do ponteiro no nó pai
    Nob *pai = NULL;
    if (no_dividir->pai != NULL) {
        pai = no_dividir->pai;

         // Percorre a lista de chaves do pai para localizar o nó filho a ser atualizado
        aux = pai->listaChaves->ini;
        while (aux != NULL && no_dividir != get_filho(aux)) {//((Chave*) aux->info)->valorChave
            aux = aux->prox;
        }

         // Se o nó a ser dividido era o nó da direita, ajustamos o ponteiro do pai para o novo nó
        if (no_dividir == pai->direita)
            pai->direita = novo_no;
        else // Caso contrário, ajustamos o ponteiro do filho no pai para o novo nó
            set_filho(aux,novo_no);
    }

    // Se o nó não for folha, atualiza os filhos do novo nó
    if (!no_dividir->folha) {
        aux = novo_no->listaChaves->ini;
        while (aux != NULL) {
            if (get_filho(aux)!= NULL)
                get_filho(aux)->pai = novo_no;
            aux = aux->prox;
        }
    }
    return novo_no;
}

Nob* cria_nova_raiz(Nob* no_inserir, Nob* novo, Chave *ch) {
    // Cria um novo nó para a raiz
    Nob *nova_raiz = cria_nob();
    nova_raiz->folha = false;

    // A chave recebida será promovida para a nova raiz, com o nó de inserção se tornando o filho da chave
    ch->filho = no_inserir;

    // Insere a chave na nova raiz. Esse processo vai adicionar a chave
    // na lista de chaves do novo nó, ordenando a estrutura.
    insere_chave_lista_no(nova_raiz, ch);

    no_inserir->pai = nova_raiz;
    nova_raiz->direita = novo;
    novo->pai = nova_raiz;

    return nova_raiz;
}

Arvoreb* libera_arvoreb(Arvoreb *T) {
    T->raiz = libera_nob(T->raiz);
    free(T);
    return NULL;
}

Nob* libera_nob(Nob* raiz) {
    Nod *aux;
    if (raiz != NULL) {
        aux = raiz->listaChaves->ini;
        while(aux != NULL) {
            ((Chave*)aux->info)->filho = libera_nob(((Chave*)aux->info)->filho);
            aux=aux->prox;
        }
        raiz->direita=libera_nob(raiz->direita);
        free(raiz);
    }
    return NULL;
}


