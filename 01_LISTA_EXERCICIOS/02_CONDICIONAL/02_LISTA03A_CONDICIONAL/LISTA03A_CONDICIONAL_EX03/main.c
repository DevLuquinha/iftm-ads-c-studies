/*===============================================================
    Receber dois números, processar e verificar, mostrando uma mensagem de qual
    deles é o maior ou se são iguais, mostrando seu valor no vídeo.

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
    float num1, num2;

    //INICIALIZAR VARIAVEIS
    num1 = num2 = 0.0;

    printf("Digite o primeiro numero: ");
    fflush(stdin);
    scanf("%f", &num1);

    printf("Digite o segundo numero: ");
    fflush(stdin);
    scanf("%f", &num2);

    if(num1 > num2)
        printf("\n %.2f eh maior do que %.2f ", num1, num2);
    else
        if(num1 < num2)
            printf("\n %.2f eh menor do que %.2f ", num1, num2);
        else
            printf("\n %.2f eh igual a %.2f ", num1, num2);

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
