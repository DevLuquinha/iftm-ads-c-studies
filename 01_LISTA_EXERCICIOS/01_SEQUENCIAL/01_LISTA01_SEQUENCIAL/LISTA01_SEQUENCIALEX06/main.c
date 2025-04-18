/*===============================================================

     Elabore um algoritmo que leia (receba) um número inteiro entre 1 e 10 (desprezar a verificação,
    imagine que ninguém irá digitar um número menor que 1 ou maior que 10, por enquanto), calcule e mostre
    no vídeo a tabuada deste número.

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
    int num;

    //INICIALIZAR VARIAVEIS
    num = 0;

    printf("\nDigite um numero entre 1 e 10: ");
    fflush(stdin);
    scanf("%d", &num);

    printf("\n %d x 1 =  %d", num, num * 1);
    printf("\n %d x 2 =  %d", num, num * 2);
    printf("\n %d x 3 =  %d", num, num * 3);
    printf("\n %d x 4 =  %d", num, num * 4);
    printf("\n %d x 5 =  %d", num, num * 5);
    printf("\n %d x 6 =  %d", num, num * 6);
    printf("\n %d x 7 =  %d", num, num * 7);
    printf("\n %d x 8 =  %d", num, num * 8);
    printf("\n %d x 9 =  %d", num, num * 9);
    printf("\n %d x 10 = %d", num, num * 10);
    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA, VALEUUUU :) \n\n\n");

    return 0;
}
