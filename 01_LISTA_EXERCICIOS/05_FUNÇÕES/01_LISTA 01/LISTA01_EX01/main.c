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
//===============================================================
//===============================================================
// Função por referência
void VerifyNumber(char msg[400], int *intNum)
{
    // Variavel responsavel por verificar se é inteiro
    float floNum = 0;

    do // Enquanto for negativo ou nulo
    {
        do // Enquanto não for inteiro
        {
            system("cls");
            // Imprime a mensagem
            printf("%s", msg);
            fflush(stdin);
            scanf("%f", &floNum);

            *intNum = floNum;    // Parte inteira
        }while(*intNum != floNum);

    }while(*intNum <= 0);
}
//===============================================================
// Função por valor
void SumNNumbers(int endNum)
{
    int sum = 0;

    for(int i = 1; i <= endNum; i++)
    {
        sum += i;
    }
    printf("O somatorio dos N's inteiros comecando por 1 ate %d: %d", endNum, sum);
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int num = 0;
    int resul = 0;

    // Função por referência
    VerifyNumber("Digite um numero inteiro e positivo: ", &num);

    // Função por valor
    SumNNumbers(num);

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
