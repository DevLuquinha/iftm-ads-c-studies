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
#define tam 15

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
    int aVector[tam], bVector[tam];
    int i;
    int num;

    //INICIALIZAR VARIAVEIS
    for(i = 0; i < tam; i++)
        aVector[i] = bVector[i] = 0;

    num = 0;

    // ATRIBUIÇÃO DE VALORES PARA O VETOR
    for(i = 0; i < tam; i++)
    {
        do
        {
            num = rand() % 50;
        }while(num == 0);

        aVector[i] = num;
        bVector[i] = pow(num, 2);
    }

    printf("=============VALORES DO VECTOR=============");

    for(i = 0; i < tam; i++)
    {
        Sleep(100);
        printf("\nVECTOR A[%d]: %d", i + 1, aVector[i]);
        printf("\nVECTOR B[%d]: %d", i + 1, bVector[i]);
        printf("\n===========================================");
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
