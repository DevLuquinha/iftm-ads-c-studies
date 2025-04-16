/*===============================================================
    R-) 1 , 4 , 2 , 5 , 3 , 6 , 4 , 7 , 5 , 8 , ... , N

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
    int i1, i4, nInt;
    float n;

    //INICIALIZAR VARIAVEIS
    i1 = 1;
    i4 = 4;
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
            printf("\n Erro! O valor digitado nao eh positivo!");
        printf("\n Digite um numero inteiro e positivo (N): ");
        fflush(stdin);
        scanf("%f", &n);
        nInt = n;
    }

    system("cls");

    while(i1 <= nInt || i4 <= nInt)
    {
        if(i4 == nInt)
        {
            Sleep(50);
            printf("%d, %d", i1, i4);
            i1 = nInt + 1;  // Força a saida do laço
            i4++;
        }
        else
        {
            Sleep(50);
            printf("%d, %d, ", i1, i4);
            i1++;
            i4++;
        }
    }
    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
