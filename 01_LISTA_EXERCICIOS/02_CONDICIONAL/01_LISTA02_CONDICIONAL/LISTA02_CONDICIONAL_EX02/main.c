/*===============================================================

    Elaborar um algoritmo que receba o Nome e ano nascimento de uma pessoa.
    Fazer as verificações em cada entrada e se não atender a condição desejada para
    cálculo dar uma mensagem de “inválido” e finalizar o algoritmo, caso contrário,
    processar e mostrar o nome e sua idade.

    CURSO: ANALISE E DESENVOLVIMENTO DE SISTEMAS - ADS
    1º PERÍODO - DISCIPLINA DE ALGORITMO E LÓGICA DE PROGRAMAÇÃO
    Nome do aluno(a): Lucas Emmanuel Rodrigues Firmino de Paula
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: Março 2025

*/
//===============================================================
//===============================================================
//======== LOCAL PARA DECLARAR AS INCLUDES E VARS GLOBAIS =======
//===============================================================
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>

//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================


//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    char nome[90];
    int anoNascimento, idade;

    //INICIALIZAR VARIAVEIS
    strcpy(nome, "");
    anoNascimento = 0;
    idade =0;

    printf("\n Digite o seu nome: ");
    fflush(stdin);
    gets(nome);

    if(strcmp(nome, "") == 0){
        system("cls");
        printf("\n Vc nao digitou um nome, apenas clicou ENTER, reinicie o programa!");
     }
    else{
        printf(" Digite o seu ano de nascimento (1900 - 2025): ");
        fflush(stdin);
        scanf("%d", &anoNascimento);

        if(anoNascimento < 1900 || anoNascimento > 2025){
            printf("\n Erro! Ano de nascimento invalido, reinicie o programa!");
        }
        else{
            idade = 2025 - anoNascimento;
            printf("\n Ola %s, vc tem %d anos de idade.", nome, idade);
        }
     }

    //FINALIZAR PROGRAMA

    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}


