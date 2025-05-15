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
void IniciateVector(int vector[], int size)
{
    for(int i = 0; i < size; i++)
    {
        vector[i] = 0;
    }
}
//===============================================================
void InsertValuesVector(int vector[], int size)
{
    for(int i = 0; i < size; i++)
    {
        vector[i] = rand() % (size * 2);
    }
}
//===============================================================
int CalculateTotalOdd(int vector[], int size)
{
    int total = 0;
    for(int i = 0; i < size; i++)
    {
        if(vector[i] % 2 != 0)
            total++;
    }
    return total;
}
//===============================================================
int CalculateTotalEven(int vector[], int size)
{
    int total = 0;
    for(int i = 0; i < size; i++)
    {
        if(vector[i] % 2 == 0)
            total++;
    }
    return total;
}
//===============================================================
void ShowVector(int vector[], int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d ", vector[i]);
    }
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // CRIAR VARIAVEIS
    int vec1Size = 10;
    int vec2Size = 5;

    int vector1[vec1Size], vector2[vec2Size], i;

    // Inicializar os vetores 1 e 2
    IniciateVector(vector1, vec1Size);
    IniciateVector(vector2, vec2Size);

    // Atribuir valores vetores 1 e 2
    InsertValuesVector(vector1, vec1Size);
    InsertValuesVector(vector2, vec2Size);

    int totalOdd = CalculateTotalOdd(vector1, vec1Size);
    int totalEven = CalculateTotalEven(vector1, vec1Size);;

    // Mostrar vetor 1 e vetor 2
    printf("V1: ");
    ShowVector(vector1, vec1Size);
    printf("\nV2: ");
    ShowVector(vector2, vec2Size);

    // Mostrar quantidade de numeros impares
    printf("\n\nA quantidade pares e impares: %d e %d", totalEven, totalOdd);

    // FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
