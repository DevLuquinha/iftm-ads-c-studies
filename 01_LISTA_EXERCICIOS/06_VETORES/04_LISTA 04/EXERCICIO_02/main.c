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
#define len 24

//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void ClearVector(int vec[])
{
    for(int i = 0; i < len; i++)
        vec[i] = 0;
}
//===============================================================
int VerifyRepeatedNumbers(int vec[], int size, int number)
{
    int IsRepeated = 0; // 0 --> False e 1 --> True
    for(int i = 0; i < size; i++)
    {
        if(vec[i] == number)
            IsRepeated = 1;
    }

    return IsRepeated;
}
//===============================================================
void SetVectorValues(int vec[])
{
    for(int i = 0; i < len; i++)
    {
        int number = rand() % len;
        if(i == 0)
            vec[i] = number;
        else
        {
            while(VerifyRepeatedNumbers(vec, i, number) == 1)
            {
                number = rand() % len;
            }
            vec[i] = number;
        }
    }
}
//===============================================================
void ShowVector(int vec[])
{
    int j = 0;

    for(int i = 0; i < len; i++)
    {
        if(j % 6 == 0)
        {
            printf("\n");
            j = 0;
        }
        printf("%4d", vec[i]);
        j++;
    }

}
//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    int vector[len];

    //INICIALIZAR VARIAVEIS
    ClearVector(vector);

    // Atribuir Valores ao Vetor
    SetVectorValues(vector);

    // Mostrar Vetor
    printf("VETOR SEM NUMEROS REPETIDOS");
    printf("\n===========================");
    ShowVector(vector);
    printf("\n===========================\n");
    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
