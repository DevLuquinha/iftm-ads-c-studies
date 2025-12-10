/*===============================================================
    c-) 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 10 , 11 , ... , N


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
    int i, nInt;
    float n;

    //INICIALIZAR VARIAVEIS
    i = 0;
    n = nInt = 0;

    printf("\n Digite um valor inteiro e positivo para N: ");
    fflush(stdin);
    scanf("%f", &n);

    nInt = n;   // Parte inteira do float

    while(nInt != n || n < 0)
    {
        if(n < 0)
            printf("\n Erro! O numero digitado eh negativo!");
        else if(nInt != n)
            printf("\n Erro! O numero digitado nao eh inteiro");

        printf("\n Digite apenas um valor inteiro e positivo para N: ");
        fflush(stdin);
        scanf("%f", &n);
        nInt = n;
    }

    // Limpa a linha de comando
    system("cls");

    while(i <= nInt)
    {
        if(i == nInt)
        {
            Sleep(50);
            printf("%d", i);
            i += 1;
        }
        else
        {
            Sleep(50);
            printf("%d, ", i);
            i += 1;
        }
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
