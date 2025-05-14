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
#define size 50

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
    int vectorA[size], vectorB[size];
    int i, num;

    //INICIALIZAR VARIAVEIS
    for(i = 0; i < size; i++)
        vectorA[i] = vectorB[i] = 0;

    num = 0;

    for(i = 0; i < size; i++)
    {
        do
        {
            num = rand() % (size * 2);
        }while(num == 0);

        vectorA[i] = num;

    }

    for(i = 0; i < size; i++)
    {
        vectorB[i] = vectorA[i] + 5;
    }

    for(i = 0; i < size; i++)
    {
        Sleep(50);
        printf("\nVetor A[%2.d]: %2.d", i + 1, vectorA[i]);
        printf("\nVetor B[%2.d]: %2.d", i + 1, vectorB[i]);
        printf("\n================");
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
