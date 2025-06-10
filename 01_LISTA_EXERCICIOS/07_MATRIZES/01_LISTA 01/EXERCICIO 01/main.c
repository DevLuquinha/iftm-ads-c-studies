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
    // Receber o nome do usuário
    printf("\nDigite o seu nome: ");
    fflush(stdin);
    gets(name);

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
            printf("%4.0f ", matriz[r][c]);
        }
        printf("\n");
    }
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // Criar variáveis
    float matriz[row][col];
    char name[100];

    // Limpar a matriz e as variáveis
    ClearMatriz(matriz);
    fflush(stdin);
    strcpy(name, "");

    // Exibir Matriz
    printf("============================\n");
    printf(" MATRIZ NA FORMA DE ENTRADA");
    printf("\n============================\n");

    ShowMatriz(matriz);
    printf("============================");

    FillMatriz(matriz);

    printf("\n     MATRIZ PREENCHIDA");
    printf("\n============================\n");

    ShowMatriz(matriz);
    printf("============================");

    // Receber nome
    GetName(name);

    // Exibir nome
    printf("\nSeu nome: %s", name);

    // FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
