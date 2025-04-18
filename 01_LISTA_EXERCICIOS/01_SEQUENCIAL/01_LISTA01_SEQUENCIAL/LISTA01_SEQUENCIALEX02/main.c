/*===============================================================

    Elabore um algoritmo que leia duas variáveis A e B, troque seus valores (conteúdos) e mostre no
    vídeo.

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
    char a[50], b[50], constA[50];

    //INICIALIZAR VARIAVEIS
    strcpy(a,"");
    strcpy(b,"");
    strcpy(constA, "");

    // RECEBER VARIAVEIS
    printf("Digite o conteudo de A: ");
    fflush(stdin);
    gets(a);

    printf("Digite o conteudo de B: ");
    fflush(stdin);
    gets(b);

    strcpy(constA, a);
    strcpy(a, b);
    strcpy(b, constA);

    //FINALIZAR PROGRAMA
    printf("\n O valor de A: %s \n O valor de B: %s", a, b);
    printf ("\n\n\n FIM DO PROGRAMA, VALEUUUU :) \n\n\n");

    return 0;
}
