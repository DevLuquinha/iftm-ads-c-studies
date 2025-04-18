/*===============================================================


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
    int i, numInt;
    float num;

    // Quantitativo dos dados
    int nPos, nNeg, nPar, nImp, nMai, nMen;

    //INICIALIZAR VARIAVEIS
    i = num = 0;
    nPos = nNeg = nPar = nImp = nMai = nMen = 0;

    while(numInt != 0)
    {
        numInt = 0;
        printf("\nDigite um numero inteiro para o senso de municipio: ");
        fflush(stdin);
        scanf("%f", &num);

        numInt = num;

        while(numInt != num)
        {
            system("cls");
            printf("\nERRO! Digite um numero INTEIRO para o senso de municipio: ");
            fflush(stdin);
            scanf("%f", &num);
            numInt = num;
        }

        if(numInt > 0)
            nPos++;
        if(numInt < 0)
            nNeg++;
        if(numInt % 2 == 0 && numInt != 0)
            nPar++;
        if(numInt % 2 != 0)
            nImp++;

        if(i == 0)
        {
            nMai = numInt;
            nMen = numInt;
        }
        else
        {
            if(numInt > nMai)
                nMai = numInt;
            if(numInt < nMen)
                nMen = numInt;
        }
        i++;
    }

    system("cls");

    //FINALIZAR PROGRAMA
    printf("\n------TABELA SENSO DO MUNICIPIO------\n");
    printf("\nQUANTIDADE DE POSITIVOS:          %d", nPos);
    printf("\nQUANTIDADE DE NEGATIVOS:          %d", nNeg);
    printf("\nQUANTIDADE DE PARES:              %d", nPar);
    printf("\nQUANTIDADE DE IMPARES:            %d", nImp);
    printf("\nO MAIOR VALOR DIGITADO:           %d", nMai);
    printf("\nO MENOR VALOR DIGITADO:           %d", nMen);
    printf("\n-------------------------------------\n\n");
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
