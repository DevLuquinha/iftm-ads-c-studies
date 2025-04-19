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
    float num, soma, media, resul;
    int qtdCal;
    float pos;
    char query;

    // INICIALIZAR VARIAVEIS
    num = soma = resul = media = qtdCal = 0;
    pos = 0;
    query = ' ';

    do
    {
        printf("\nDigite um numero, para finalizar digite 0: ");
        fflush(stdin);
        scanf("%f", &num);

        if(num != 0)
        {
            pos++;
            resul = pow((num * pos), pos);
            printf("\nCALCULO %.0f:", pos);
            printf("\n(%.2f * %.0f)^%.0f: %.2f\n", num, pos, pos, resul);

            soma += resul;
            qtdCal++;
        }
    }while(num != 0);

    if(qtdCal == 0)
    {
        system("cls");
        printf("Infelizmente o usuario nao realizou nenhum calculo :(");
        printf("\nPara imprimir um relatorio, reinicie o programa e informe valores!");
    }
    else
    {
        media = soma / qtdCal;

        do
        {
            printf("\nPara a impressao do relatorio final, deseja:");
            printf("\nApagar o historico de operacoes? <<S>> ou <<N>>: ");
            fflush(stdin);
            scanf("%c", &query);
        }while(query != 'S' && query != 's' && query != 'n' && query != 'N');

        if(query == 'S' || query == 's')
            system("cls");
        else
            printf("\n");
        printf("RELATORIO FINAL");
        printf("\n=================================================");
        printf("\nA soma de todos os calculos: %.2f", soma);
        printf("\nA media aritmetica: %.2f", media);
        printf("\nA quantidade de calculos: %d", qtdCal);
        printf("\n=================================================");
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\nFIM DO PROGRAMA - VAI EMBORA DAQUI :) \n\n\n");

    return 0;
}
