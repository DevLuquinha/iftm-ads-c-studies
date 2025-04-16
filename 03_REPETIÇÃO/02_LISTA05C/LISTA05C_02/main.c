/*===============================================================


    CURSO: ANALISE E DESENVOLVIMENTO DE SISTEMAS - ADS
    1º PERÍODO - DISCIPLINA DE ALGORITMO E LÓGICA DE PROGRAMAÇÃO
    Nome do aluno(a): Lucas Emmanuel Rodrigues Firmino de Paula
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: Abril 2025

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
    float num;
    int numInt, resul;

    //INICIALIZAR VARIAVEIS
    num = numInt = 0;
    resul = 1;
    do
    {

        printf("\nDigite um numero para realizar o fatorial: ");
        fflush(stdin);
        scanf("%f", &num);
        numInt = num;
        if(numInt != num || numInt <= 1)
            printf("\nDigite apenas numeros inteiros e positivos!");

    }while(numInt != num || numInt <= 0);

    system("cls");

    for(numInt; numInt > 1; numInt--)
        resul = resul * numInt;

    //FINALIZAR PROGRAMA
    printf("O resultado do fatorial:");
    printf("\n\n%.0f! = %d", num, resul);
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
