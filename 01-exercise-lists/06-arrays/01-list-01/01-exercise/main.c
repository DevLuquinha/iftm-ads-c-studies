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
    float numVet[10];
    int i;
    float num;

    //INICIALIZAR VARIAVEIS
    for(i = 0; i < 10; i++)
        numVet[i] = 0;

    i = 0;
    while(i < 10)
    {
        num = 0;
        printf("\nDigite o numero para a posicao %d: ", i + 1);
        fflush(stdin);
        scanf("%f", &num);

        numVet[i] = num;
        i++;
    }

    // LIMPAR A TELA
    system("cls");

    //FINALIZAR PROGRAMA
    printf("Os valores do vetor de tamanho 10:");
    printf("\n=================================:");

    for(i = 0; i < 10; i++)
        printf("\nPosicao %2.d ---> %.2f", i + 1, numVet[i]);

    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
