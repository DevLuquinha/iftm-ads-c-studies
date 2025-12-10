/*===============================================================
    CURSO: ANALISE E DESENVOLVIMENTO DE SISTEMAS - ADS
    1º PERÍODO - DISCIPLINA DE ALGORITMO E LÓGICA DE PROGRAMAÇÃO
    Nome do aluno(a): Lucas Emmanuel Rodrigues Firmino de Paula
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: Junho 2025

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
#define ROW 5
#define COLUMN 6
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void ClearMatriz(float matriz[][COLUMN], int row, int column);
void ShowMatriz(float matriz[][COLUMN], int row, int column);
//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void ClearMatriz(float matriz[][COLUMN], int row, int column)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            matriz[i][j] = 16.35;
        }
    }
}
//===============================================================
void ShowMatriz(float matriz[][COLUMN], int row, int column)
{
    printf("=============== MATRIZ %dx%d ================\n", ROW, COLUMN);
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            printf(" %5.1f ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("===========================================");
}
//===============================================================
void FillMatriz(float matriz[][COLUMN], int row, int column)
{
    float num = 0.0;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
        {
            do
            {
                num = rand() % 100;
            }while(num == 0);

            matriz[i][j] = num;
        }
    }
}
//===============================================================

//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // Criar Variaveis
    float matriz[ROW][COLUMN];

    ClearMatriz(matriz, ROW, COLUMN);

    FillMatriz(matriz, ROW, COLUMN);

    // ITEM A
    ShowMatriz(matriz, ROW, COLUMN);

    // ITEM B
    printf("\nO valor do elemento da matriz[4,5] eh: %.1f", matriz[3][4]);

    // Finalizar Programa
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
