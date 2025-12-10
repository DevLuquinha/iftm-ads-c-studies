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
#define tam 50
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
    int numVector[tam];
    int i, oddNumbers, evenNumbers;

    //INICIALIZAR VARIAVEIS
    for(i = 0; i < tam; i++)
        numVector[i] = 0;

    oddNumbers = evenNumbers = 0;

    // RECEBE OS VALORES ALEATORIOS PARA O VETOR
    for(i = 0; i < tam; i++)
    {
        numVector[i] = rand() % (tam * 2);
        printf("\nVALOR POS[%d]: %d", i, numVector[i]);
    }

    // system("cls");

    // MOSTRAR NUMEROS PARES
    printf("\n===========VALORES PARES===========\n");
    for(i = 0; i < tam; i++)
    {
        if(i % 2 == 0)
        {
            printf(" %d ", i, numVector[i]);
            oddNumbers++;

            if(oddNumbers % 5 == 0)
            printf("\n");
        }

        Sleep(50);
    }

    // MOSTRAR NUMEROS PARES
    printf("\n===========VALORES IMPARES===========\n");
    for(i = 0; i < tam; i++)
    {
        if(i % 2 == 1)
        {
            printf(" %d ", i, numVector[i]);
            evenNumbers++;

            if(evenNumbers % 5 == 0)
            printf("\n");
        }

        Sleep(50);
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
