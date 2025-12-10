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
    float num;  // Num bruto,  sem verificação de inteiro
    int numInt, qtdNum;
    int menor, maior;
    float media, soma;

    //INICIALIZAR VARIAVEIS
    num = numInt = qtdNum = soma = media = menor = maior = 0;

    do
    {
        printf("\n Digite um numero inteiro: ");
        fflush(stdin);
        scanf("%f", &num);

        numInt = num;

        while(numInt != num)
        {
            printf("\n Digite APENAS numeros inteiros: ");
            fflush(stdin);
            scanf("%f", &num);
            numInt = num;
        }

        if(numInt != 0)
        {
            if(qtdNum == 0)
            {
                maior = menor = numInt;
            }
            else
            {
                if(numInt > maior)
                    maior = numInt;
                if(numInt < menor)
                    menor = numInt;
            }
            qtdNum++;
            soma += numInt;
        }


    }while(numInt != 0);

    media = soma / qtdNum;

    //FINALIZAR PROGRAMA
    printf("\nA quantidade de numeros digitados eh: %d", qtdNum);
    printf("\nA soma dos numeros digitados eh: %.0f", soma);
    printf("\nA media dos numeros digitados eh: %.2f", media);
    printf("\nA menor numero digitado eh: %d", menor);
    printf("\nA maior numero digitado eh: %d", maior);
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
