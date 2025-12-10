/*===============================================================
    K-) 1 , 2 , 3 , 4 , 8 , 9 , 10 , 11 , 22 , 23 , 24 , 25 , ... , N

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
    n = nInt= 0;

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

    while (i <= nInt)
    {
        if(pular == 4)
        {
            Sleep(50);
            printf("%d, ", i);
            pular = 1;
            i = i * 2;
        }
        else
        {
            Sleep(50);
            printf("%d, ", i);
            pular += 1;
            i += 1;
        }
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
