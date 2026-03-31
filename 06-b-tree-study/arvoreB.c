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
    Nod *aux = NULL;
    Nob *filho = NULL;

    if (raiz != NULL) {
        *aux = *raiz->listaChaves->ini;

        while (aux != NULL){
            filho = get_filho(aux);
            emOrdem(filho);
            printf("%i, ", get_chave(aux));
            *aux = *aux->prox;
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
Nob* localiza_folha(Arvoreb *T, int k) {
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


