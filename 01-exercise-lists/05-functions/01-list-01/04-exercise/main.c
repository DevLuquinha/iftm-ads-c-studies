/*===============================================================
    CURSO: ANALISE E DESENVOLVIMENTO DE SISTEMAS - ADS
    1º PERÍODO - DISCIPLINA DE ALGORITMO E LÓGICA DE PROGRAMAÇÃO
    Nome do aluno(a): Lucas Emmanuel Rodrigues Firmino de Paula
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: Maio 2025

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
#include <conio.h>
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================

//===============================================================
float GetFloat()
{
    float number = 0;

    printf("Digite um numero positivo: ");
    fflush(stdin);
    scanf("%f", &number);
    return number;
}
//===============================================================
void VerifyNumber(float *number)
{
    while(*number <= 0)
    {
        printf("\nDigite APENAS um numero positivo: ");
        fflush(stdin);
        scanf("%f", &*number);
    }
}
//===============================================================
void Factorial(float number)
{
    system("cls");

    printf("O VALOR DE %.0f!", number);
    printf("\n===================================================\n");

    float result = 1;
    for(float i = number; i > 0; i--)
    {
        // Printa o Numero
        Sleep(250);
        printf("%.0f", i);
        if(i == 1)
            printf(" = ");
        else
            printf(", ");

        // Realiza o Calculo
        result *= i;
    }

    printf("%.0f", result);
    printf("\n===================================================");
}
//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // CRIAR VARIAVEIS
    float number = 0;

    // RECEBE UM NUMERO FLOAT
    number = GetFloat();

    // VERIFICA SE É NEGATIVO
    VerifyNumber(&number);

    // REALIZAR CALCULO FATORIAL
    Factorial(number);

    // FINALIZAR PROGRAMA
    printf ("\n\n\nFIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
