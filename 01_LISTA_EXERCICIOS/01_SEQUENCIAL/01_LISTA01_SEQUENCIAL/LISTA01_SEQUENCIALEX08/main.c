/*===============================================================

    - Elabore um algoritmo que receba a idade de uma pessoa (em anos, considerando que já tenha feito
    aniversário em 2024). Calcule e mostre em que ano esta pessoa nasceu.

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
    int idade, anoNascimento;

    //INICIALIZAR VARIAVEIS
    idade = 0;
    anoNascimento = 0;

    printf("\nDigite a sua idade: ");
    fflush(stdin);
    scanf("%d", &idade);

    anoNascimento = 2024 - idade;

    //FINALIZAR PROGRAMA
    printf("\n Vc nasceu no ano de %d", anoNascimento);
    printf ("\n\n\n FIM DO PROGRAMA, VALEUUUU :) \n\n\n");

    return 0;
}
