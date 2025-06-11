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
void FillMatriz(float matriz[][col])
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
void ClearMatriz(float matriz[][col])
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
void ShowMatriz(float matriz[][col])
{
    for(int r = 0; r < row; r++)
    {
        for(int c = 0; c < col; c++)
        {
            printf("%9.0f ", matriz[r][c]);
            Sleep(50);
        }
        printf("\n");
    }
}
//===============================================================
void ClearVectorRow(float vector[], int length)
{
    for(int i = 0; i < length; i++)
        vector[i] = 0.0;
}
//===============================================================
void GetVectorRow(float matriz[][row], float vector[], int length)
{
    float sum = 0;

    for(int r = 0; r < row; r++)
    {
        sum = 0;

        for(int c = 0; c < col; c++)
            sum += matriz[r][c];

        vector[r] = sum;
    }
}
//===============================================================
void ShowVectorRow(float vector[], int length)
{
    printf("\nVETOR LINHAS: [ ");

    for(int i = 0; i < length; i++)
    {
        if(i + 1 == length)
            printf("%.0f ]", vector[i]);
        else
            printf("%.0f, ", vector[i]);

        Sleep(100);
    }

//    for(int i = 0; i < length; i++)
//    {
//        printf("\n%.0f", vector[i]);
//    }
}
//===============================================================
//===============================================================
void ClearVectorColumn(float vector[], int length)
{
    for(int i = 0; i < length; i++)
        vector[i] = 0.0;
}
//===============================================================
void GetVectorColumn(float matriz[][row], float vector[], int length)
{
    float sum = 0;

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
void ShowVectorColumn(float vector[], int length)
{
    printf("\nVETOR COLUNAS: [ ");

    for(int i = 0; i < length; i++)
    {
        if(i + 1 == length)
            printf("%.0f ]", vector[i]);
        else
            printf("%.0f, ", vector[i]);

        Sleep(100);
    }
}
//===============================================================
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // Criar variáveis
    float matriz[row][col];
    char name[100];
    float sumVecRows[row];
    float sumVecCols[col];

    // Limpar a matriz e as variáveis
    ClearMatriz(matriz);

    fflush(stdin);
    strcpy(name, "");

    ClearVectorRow(sumVecRows, row);
    ClearVectorColumn(sumVecCols, col);

    // Atribuir a variavel por referência
    GetName(name);

    // Exibição do video
    printf("=======================================================");
    printf("\nOla meu querido usuario(a): %s", name);
    printf("\n=======================================================");

    FillMatriz(matriz);
    GetVectorRow(matriz, sumVecRows, row);
    GetVectorColumn(matriz, sumVecCols, col);

    printf("\n              MATRIZ NA FORMA DE ENTRADA");
    printf("\n=======================================================\n");

    ShowMatriz(matriz);
    printf("=======================================================");

    printf("\n               VETOR DA SOMA DAS LINHAS");
    printf("\n=======================================================");

    ShowVectorRow(sumVecRows, row);

    printf("\n=======================================================");

    printf("\n               VETOR DA SOMA DAS COLUNAS");
    printf("\n=======================================================");

    ShowVectorColumn(sumVecCols, col);

    printf("\n=======================================================");
    // FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
