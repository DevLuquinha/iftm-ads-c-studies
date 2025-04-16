/*===============================================================

    Elabore um algoritmo que leia (receba) um valor correspondente a graus Farenheit. Calcule e
    apresente a conversão deste valor para graus Celsius.
    Utilize a fórmula:

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
    float grausC, grausF;

    //INICIALIZAR VARIAVEIS
    grausC = 0;
    grausF = 0;

    printf("\nDigite os graus em Fareheint: ");
    fflush(stdin);
    scanf("%f", &grausF);

    grausC = 5.0 / 9.0 * (grausF - 32);

    //FINALIZAR PROGRAMA
    printf("\n\n\n%.2f sao %.2f graus Celsius.", grausF, grausC);
    printf ("\n\n\n FIM DO PROGRAMA, VALEUUUU :) \n\n\n");

    return 0;
}
