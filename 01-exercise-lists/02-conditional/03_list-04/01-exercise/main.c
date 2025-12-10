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
    float num1, num2, resul;
    char ope;
    //INICIALIZAR VARIAVEIS
    num1 = num2, resul = 0;
    ope = ' ';

    printf("\nDigite o primeiro numero: ");
    fflush(stdin);
    scanf("%f", &num1);

    printf("\nDigite o segundo numero: ");
    fflush(stdin);
    scanf("%f", &num2);

    printf("\nDigite a operacao (+, -, *, /): ");
    fflush(stdin);
    scanf("%c", &ope);

    if(ope != '+' && ope != '-' && ope != '*' && ope != '/')
    {
        printf("\nErro! Nenhuma das operacoes foi marcada, marque a operacao corretamente!");
    }
    else
    {
        if(ope == '+')
        {
            printf("O valor de %.2f + %.2f = %.2f", num1, num2, num1 + num2);
        }
        else if(ope == '-')
        {
            printf("O valor de %.2f - %.2f = %.2f", num1, num2, num1 - num2);
        }
        else if(ope == '*')
        {
            printf("O valor de %.2f * %.2f = %.2f", num1, num2, num1 * num2);
        }
        else if(ope == '/')
        {
            if(num2 == 0)
            {
                printf("Erro! O valor do segundo numero eh igual a 0, nao pode realizar uma divisao por 0");
            }
            else
            {
                printf("O valor de %.2f / %.2f = %.2f", num1, num2, num1 / num2);
            }
        }
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
