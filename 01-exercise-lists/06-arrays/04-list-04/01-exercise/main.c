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
#define len 10
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void ClearVector(int vector[])
{
    for(int i = 0; i < len; i++)
        vector[i] = 0;
}
//===============================================================
void SetVectorValues(int vector[])
{
    int num;

    for(int i = 0; i < len; i++)
    {
        do
        {
            num = rand() % (len + 2);
        }while(num == 0);

        vector[i] = num;
    }

}
//===============================================================
void FindNumber(int vector[], int number)
{
    int totalInVector = 0;

    for(int i = 0; i < len; i++)
    {
        if(number == vector[i])
        {
            printf("\nO %d esta na posicao %d do vetor (Vetor[%d])", number, i, i);
            totalInVector++;
        }
    }

    if(totalInVector == 0)
        printf("\nInfelizmente o valor de %d nao foi encontrado no vetor.", number);

    printf("\n");
}
//===============================================================

//===============================================================
void ShowVector(int vector[])
{
    int j = 0;
    for(int i = 0; i < len; i++)
    {
        j++;
        printf(" [%d] - %2d ", i, vector[i]);
        if(j % 5 == 0)
        {
            printf("\n");
            j = 0;
        }
    }
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int vector[len];
    int num = 0;

    //INICIALIZAR VARIAVEIS
    ClearVector(vector);

    // Atribuir valores aleatorios para o vetor
    SetVectorValues(vector);

    do
    {
        system("cls");

        // Mostrar Vetor
        printf("Vetor de numeros inteiros");
        printf("\n==================================================================================\n");
        ShowVector(vector);
        printf("==================================================================================");

        printf("\nDigite o numero entre [1-%d].Continuar qualquer tecla - Finalizar tecle 0: ", len);
        fflush(stdin);
        scanf("%d", &num);
        if(num != 0)
        {
            FindNumber(vector, num);
            getch();
        }
    }
    while(num != 0);

    //FINALIZAR PROGRAMA

    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
