/*===============================================================

    Elabore um algoritmo que receba (leia) três números via teclado e apresente o resultado da soma
    das combinações, dois a dois, destes três números.

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
    float num1, num2, num3;

    //INICIALIZAR VARIAVEIS
    num1 = 0;
    num2 = 0;
    num2 = 0;

    printf("\nDigite o valor no numero A: ");
    fflush(stdin);
    scanf("%f", &num1);

    printf("\nDigite o valor no numero B: ");
    fflush(stdin);
    scanf("%f", &num2);

    printf("\nDigite o valor no numero C: ");
    fflush(stdin);
    scanf("%f", &num3);

    //FINALIZAR PROGRAMA
    printf("\n\n\n A + B = %.1f ", num1 + num2);
    printf("\n A + C = %.1f ", num1 + num3);
    printf("\n B + C = %.1f ", num2 + num3);
    printf ("\n\n\n FIM DO PROGRAMA, VALEUUUU :) \n\n\n");

    return 0;
}
