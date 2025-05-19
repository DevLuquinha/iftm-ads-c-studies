/*===============================================================

    CURSO: ANALISE E DESENVOLVIMENTO DE SISTEMAS - ADS
    1º PERÍODO - DISCIPLINA DE ALGORITMO E LÓGICA DE PROGRAMAÇÃO
    Nome do aluno(a): Lucas Emmanuel Rodrigues Firmino de Paula
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: Maio 2025

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
#include <conio.h>
#define size 3
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
    float studentsScore[size];
    char studentsName[size][100];
    int i;

    //INICIALIZAR VARIAVEIS
    for(i = 0; i < size; i++)
    {
        studentsScore[i] = 0;
        strcpy(studentsName[i], "");
    }

    i = 0;
    for(i = 0; i < size; i++)
    {
        do
        {
            printf("\nInforme o nome do aluno %d: ", i + 1);
            gets(studentsName[i]);
        }while(strcmp(studentsName[i], "") == 0);

        do
        {
            printf("\nDigite a nota de %s: ", studentsName[i]);
            fflush(stdin);
            scanf("%f", &studentsScore[i]);
        }while(studentsScore[i] < 0 || studentsScore[i] > 10);
    }



    for(i = 0; i < size; i++)
    {
        printf("\n%s tirou a nota %.2f", studentsName[i], studentsScore[i]);
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
