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
#define row 5
#define col 5
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================

//===============================================================
void GetName(char name[])
{
    do
    {
        printf("Digite o seu nome: ");
        fflush(stdin);
        gets(name);

        if(strcmp(name, "") == 0)
            printf("\nERRO! DIGITE UM NOME !!!\n");
    }while(strcmp(name, "") == 0);

    system("cls");
}
//===============================================================
void FillMatriz(int matriz[][col])
{
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            matriz[r][c] = rand() % 50;
        }
    }
}
//===============================================================
void ClearMatriz(int matriz[][col])
{
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            matriz[r][c] = 0;
        }
    }
}
//===============================================================
void ShowMatriz(int matriz[][col])
{
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            printf("%9d ", matriz[r][c]);
            Sleep(50);
        }
        printf("\n");
    }
}
//===============================================================
void ClearVectorRow(int vector[], int length)
{
    for(int i = 0; i < length; i++)
        vector[i] = 0.0;
}
//===============================================================
void GetVectorRow(int matriz[][row], int vector[], int length)
{
    int sum = 0;

    for(int r = 0; r < row; r++)
    {
        sum = 0;

        for(int c = 0; c < col; c++)
            sum += matriz[r][c];

        vector[r] = sum;
    }
}
//===============================================================
void ShowVectorRow(int vector[], int length)
{
    printf("\nVETOR LINHAS:  [ ");

    for(int i = 0; i < length; i++)
    {
        if(i + 1 == length)
            printf("%d ]", vector[i]);
        else
            printf("%d, ", vector[i]);

        Sleep(100);
    }
}
//===============================================================
//===============================================================
void ClearVectorColumn(int vector[], int length)
{
    for(int i = 0; i < length; i++)
        vector[i] = 0.0;
}
//===============================================================
void GetVectorColumn(int matriz[][row], int vector[], int length)
{
    int sum = 0;

    for(int c = 0; c < col; c++)
    {
        sum = 0;
        for(int r = 0; r < row; r++)
        {
            sum += matriz[r][c];
        }
        vector[c] = sum;
    }
}
//===============================================================
void ShowVectorColumn(int vector[], int length)
{
    printf("\nVETOR COLUNAS: [ ");

    for(int i = 0; i < length; i++)
    {
        if(i + 1 == length)
            printf("%d ]", vector[i]);
        else
            printf("%d, ", vector[i]);

        Sleep(100);
    }
}
//===============================================================
void SumMatrices(int matrizA[][row], int matrizB[][row], int matrizResult[][row])
{
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            matrizResult[r][c] = matrizA[r][c] + matrizB[r][c];
        }
    }
}
//===============================================================
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // Criar variáveis
    int matrizA[row][col];
    int matrizB[row][col];
    int matrizC[row][col];

    char name[100];
    float sumVecRows[row];
    float sumVecCols[col];

    float totSum; // Apagar

    // Limpar as matrizes e as variáveis
    ClearMatriz(matrizA);
    ClearMatriz(matrizB);
    ClearMatriz(matrizC);

    fflush(stdin);
    strcpy(name, "");

    ClearVectorRow(sumVecRows, row);
    ClearVectorColumn(sumVecCols, col);

    // Atribuir a variavel por referência
    GetName(name);

    // Lógica crítica
    FillMatriz(matrizA);
    FillMatriz(matrizB);
    SumMatrices(matrizA, matrizB, matrizC);

//    GetVectorRow(matriz, sumVecRows, row);
//    GetVectorColumn(matriz, sumVecCols, col);
//    totSum = SumAllElements(matriz);

    // Exibição do video
    printf("=======================================================");
    printf("\nOla meu querido usuario(a): %s", name);
    printf("\n=======================================================");

    printf("\n                       MATRIZ A");
    printf("\n=======================================================\n");

    ShowMatriz(matrizA);
    printf("=======================================================");

    printf("\n                       MATRIZ B");
    printf("\n=======================================================\n");

    ShowMatriz(matrizB);
    printf("=======================================================");

    printf("\n                       MATRIZ C");
    printf("\n=======================================================\n");

    ShowMatriz(matrizC);
    printf("=======================================================");

//    printf("\n               VETOR DA SOMA DAS LINHAS");
//    printf("\n=======================================================");
//
//    ShowVectorRow(sumVecRows, row);
//
//    printf("\n=======================================================");
//
//    printf("\n               VETOR DA SOMA DAS COLUNAS");
//    printf("\n=======================================================");
//
//    ShowVectorColumn(sumVecCols, col);
//
//    printf("\n=======================================================");
//
//    printf("\nA soma de todos os elementos da matriz: %.0f", totSum);

    // FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
