/*===============================================================
    D-) 0 , 2 , 4 , 6 , 8 , 10 , 12 , 14 , 16 , 18 , 20 , ... , N

    CURSO: ANALISE E DESENVOLVIMENTO DE SISTEMAS - ADS
    1º PERÍODO - DISCIPLINA DE ALGORITMO E LÓGICA DE PROGRAMAÇÃO
    Nome do aluno(a): Lucas Emmanuel Rodrigues Firmino de Paula
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: Março 2025

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
    i = nInt = 0;
    n = 0;

    printf("\n Digite um numero positivo e inteiro (N): ");
    fflush(stdin);
    scanf("%f", &n);

    nInt = n;   // Pega a parte inteira do float

    while(nInt != n || n <= 0)
    {
        if(n <= 0)
            printf("\n Erro! Vc digitou um numero negativo ou 0.");
        else if(nInt != n)
            printf("\n Erro! Vc nao digitou um numero inteiro.");

        printf("\n Digite novamente um numero positivo e inteiro (N): ");
        fflush(stdin);
        scanf("%f", &n);

        nInt = n;
    }

    while(i <= nInt)
    {
        if(i == nInt || i == nInt -1)
        {
            Sleep(50);
            printf("%d", i);
            i += 2;
        }
        else
        {
            Sleep(50);
            printf("%d, ", i);
            i += 2;
        }
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
