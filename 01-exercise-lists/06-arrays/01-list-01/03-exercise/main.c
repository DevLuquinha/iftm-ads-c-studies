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
#define tam 20
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
    float aVector[tam], bVector[tam], cVector[tam];
    int i;

    //INICIALIZAR VARIAVEIS
    for(i = 0; i < tam; i++)
        aVector[i] = bVector[i] = cVector[i] = 0;

    // RECEBE VALORES
    for(i = 0; i < tam; i++)
    {
        aVector[i] = rand() % 50;
        bVector[i] = rand() % 50;
        cVector[i] = aVector[i] + bVector[i];
    }

    printf("=============VALORES DO VECTOR=============");

    for(i = 0; i < tam; i++)
    {
        Sleep(100);
        printf("\nVECTOR A[%d]: %.2f", i + 1, aVector[i]);
        printf("\nVECTOR B[%d]: %.2f", i + 1, bVector[i]);
        printf("\nVECTOR C[%d]: %.2f + %.2f = %.2f", i + 1, aVector[i], bVector[i], cVector[i]);
        printf("\n===========================================");
    }


    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
