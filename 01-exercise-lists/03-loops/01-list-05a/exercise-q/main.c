/*===============================================================
    Q-) 1, 1 , 2 , 3 , 5 , 8 , 13 , 21 , 34 , 55 , ... , N

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
    int nInt, resSom, somador1, somador2;
    float n;

    //INICIALIZAR VARIAVEIS
    resSom = 1;
    somador1 = 0;
    somador2 = 1;
    n = nInt = 0;

    printf("\n Digite um numero inteiro e positivo (N): ");
    fflush(stdin);
    scanf("%f", &n);
    nInt = n;

    while(nInt != n || n <= 0)
    {
        if(n <= 0)
            printf("\n Erro! O valor digitado eh menor ou igual a 0.");
        else if(nInt != n)
            printf("\n Erro! O valor digitado nao eh inteiro!");
        printf("\n Digite um numero inteiro e positivo (N): ");
        fflush(stdin);
        scanf("%f", &n);
        nInt = n;
    }

    system("cls");

    while (resSom <= nInt)
    {
        // No primeiro loop mostra apenas 1
        Sleep(25);
        printf("%d", resSom);

        // No primeiro loop vai somar 0 + 1
        resSom = somador1 + somador2;
        somador1 = somador2;
        somador2 = resSom;
        if(resSom < nInt)
            printf(", ")
    }
    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
