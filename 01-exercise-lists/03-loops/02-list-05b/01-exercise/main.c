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
    // Variaveis para o funcionamento do programa
    int quantInt;   // Parte inteira da quantidade de elementos
    float quant;    // Quantidade de elementos
    char query;     // Pergunta se o usuário deseja continuar
    int i;

    // Variaveis para o fibonacci
    int somador1, somador2, resul;

    // Inicializar como sim, para entrar no laço
    query = 's';


    // Começa em um laço de repeticao
    while(query == 's' || query == 'S')
    {
        // inicializar as variaveis
        quant = quantInt = i = 0;
        somador1 = 0;
        somador2 = 0;
        resul = 1;

        system("cls");

        // Recebe a quantidade de termos e verifica o input
        printf("\n Digite a quantidade de termos da sequencia de fibonacci: ");
        fflush(stdin);
        scanf("%f", &quant);

        quantInt = quant;

        while(quantInt != quant || quantInt < 0)
        {
            printf("\n Erro! Vc digitou digitou um numero nao inteiro OU um numero negativo:\n\n");
            printf("\n Digite novamente a quantidade de termos da sequencia de fibonacci: ");
            fflush(stdin);
            scanf("%f", &quant);

            quantInt = quant;
        }

        system("cls");

        printf("Os %d primeiros termos da sequencia de fibonacci: \n\n", quantInt);

        while(i < quantInt)
        {
            printf("%d", resul);
            somador1 = somador2;
            somador2 = resul;
            resul = somador1 + somador2;
            i++;
            if(i < quantInt)
                printf(", ");
        }

        printf("\n\nDeseja executar o comando novamente?\n<<s>> ou <<n>>: ");
        fflush(stdin);
        scanf("%c", &query);

        while(query != 's' && query != 'S' && query != 'n' && query != 'N')
        {
            printf("\nDeseja executar o comando novamente?\n<<s>> ou <<n>>: ");
            fflush(stdin);
            scanf("%c", &query);
        }

    }
    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
