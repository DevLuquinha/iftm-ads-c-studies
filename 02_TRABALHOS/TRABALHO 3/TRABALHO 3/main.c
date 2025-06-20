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
#define row 50
#define col 50
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void ClearMatriz(int matriz[][col], int rowLen, int colLen);
void ShowMatriz(int matriz[][col], int rowLen, int colLen);
int GetDimension();
void GetName(char name[100]);
void FillMatriz(int matriz[][col], int rowLen, int colLen);
//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void ClearMatriz(int matriz[][col], int rowLen, int colLen)
{
    for(int i = 0; i < rowLen; i++)
    {
        for(int j = 0; j < colLen; j++)
        {
            matriz[i][j] = 0;
        }
    }
}
//===============================================================
void ShowMatriz(int matriz[][col], int rowLen, int colLen)
{
    system("cls");
    printf("===========================================================");
    printf("\n                       MATRIZ %dx%d", rowLen, colLen);
    printf("\n===========================================================\n");

    for(int i = 0; i < rowLen; i++)
    {
        for(int j = 0; j < colLen; j++)
        {
            printf("%4d ", matriz[i][j]);
            Sleep(10);
        }
        printf("\n");
    }
    printf("===========================================================\n");
}
//===============================================================
int GetDimension()
{
    float num = 0;
    int numInt = 0;

    do
    {
        printf("\nDigite a dimensao desejada [1-50]: ");
        fflush(stdin);
        scanf("%f", &num);

        numInt = num;

        if(numInt != num)
            printf("\nERRO! DIMENSAO INCOERENTE!!! DIGITE UMA DIMENSAO INTEIRA !!!");

        if(numInt < 1 || numInt > 50)
            printf("\nERRO! DIGITE UMA DIMENSAO VALIDA!!! ENTRE 1 e 50");
    }while(numInt != num || numInt < 1 || numInt > 50);

    return numInt;
}
//===============================================================
void GetName(char name[100])
{
    // Limpar a variavel
    fflush(stdin);
    strcpy(name, "");

    do
    {
        printf("\nDigite o seu nome: ");
        fflush(stdin);
        gets(name);

        if(strcmp(name, "") == 0)
            printf("\nERRO! DIGITE UM NOME VALIDO!!!");
    }while(strcmp(name, "") == 0);
}
//===============================================================
void FillMatriz(int matriz[][col], int rowLen, int colLen)
{
    int num;

    for(int i = 0; i < rowLen; i++)
    {
        for(int j = 0; j < colLen; j++)
        {
            num = 0;
            do
            {
                num = rand() % 15;
            }while(num <= 0);

            matriz[i][j] = num;
        }
    }
}
//===============================================================
void ShowRepeatedNumbers(int matriz[][col], int rowLen, int colLen)
{
    int isRepeated = 0;  // False
    int repeatedNum = 0; // Nenhum numero repetido por padrão
    int repeatedQtd = 0; // Quantidade de vezes repetidas
    int num = 0; // Numero inicial

    for(int i = 0; i < rowLen; i++)
    {
        for(int j = 0; j < colLen; j++)
        {
            printf("\n[%d][%d]: %d", i, j, matriz[i][j]);
            getch();
        }
        printf("\n=================");
    }

     for(int i = 0; i < rowLen; i++)
    {
        num = matriz[0][1];
        for(int j = 0; j < colLen; j++)
        {
            if(num == matriz[i][j])
            {
                isRepeated = 1;
                repeatedNum = num;
                repeatedQtd++;
            }
        }
    }

    if(isRepeated == 1 && repeatedQtd > 1)
    {
        printf("\nO numero %d repetiu %d vezes", repeatedNum, repeatedQtd);
    }
}
//===============================================================
void SortMatriz(int matriz[][col], int rowLen, int colLen)
{
    int i, iAux = 0;
    int j, jAux = 0;
    int num;

    int qtdNum;

    do
    {
        jAux = 0;
        do
        {
            i = 0;

            do
            {
                j = 0;
                num = matriz[iAux][jAux];

                do
                {
                    printf("\nMAT[%d][%d]: %d <=> NUM[%d][%d]: %d", i, j, matriz[i][j], iAux, jAux, num);
                    getch();

                    j++;
                }while(j < colLen);

                i++;
            }while(i < rowLen);

            printf("\n==========CHEGOU 1==========");
            printf("\nTROCOU DE NUMERO: ");

            jAux++;
        }while(jAux < colLen);

        printf("\n==========CHEGOU 2==========");
        printf("\nTROCOU DE LINHA");

        iAux++;
    }while(iAux < rowLen);
}
//===============================================================
//===============================================================
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // Criar Variaveis
    int matriz[row][col];
    int rows, columns = 0;
    char name[100];

    // Limpar a matriz base 50x50
    ClearMatriz(matriz, row, col);

    printf("Digite a quantidade de LINHAS da matriz");
    printf("\n==========================================");
    rows = GetDimension();

    printf("\n==========================================");

    printf("\nDigite a quantidade de COLUNAS da matriz");
    printf("\n==========================================");
    columns = GetDimension();

    // GetName(name);

    FillMatriz(matriz, rows, columns);

    // Mostrar quais numeros aparecem repetidas vezes

    // printf("\nOLA %s. A matriz de dimensao [%d][%d]\n", name, rows, columns);

    ShowMatriz(matriz, rows, columns);

    SortMatriz(matriz, rows, columns);
    // Finalizar Programa
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");
    return 0;
}
