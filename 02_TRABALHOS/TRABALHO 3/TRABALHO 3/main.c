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
#define ROW 50
#define COLUMN 50
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================
void ClearMatriz(int matriz[][COLUMN], int rowLen, int colLen);
void ShowMatriz(int matriz[][COLUMN], int rowLen, int colLen);
int GetDimension();
void GetName(char name[100]);
void FillMatriz(int matriz[][COLUMN], int rowLen, int colLen);
//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
void ClearMatriz(int matriz[][COLUMN], int rowLen, int colLen)
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
void ShowMatriz(int matriz[][COLUMN], int rowLen, int colLen)
{

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
    printf("===========================================================");
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
void FillMatriz(int matriz[][COLUMN], int rowLen, int colLen)
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
void ShowRepeatedNumbers(int matriz[][COLUMN], int rowLen, int colLen)
{
    int currentElem = 0;
    int existRepeatedNumber = 0;
    int countEquals = 0;
    int auxI, auxJ = 0;
    int isThereBack = 0; // Existe numero para trás?

    for(int i = 0; i < rowLen; i++)
    {
        for(int j = 0; j < colLen; j++)
        {
            currentElem = matriz[i][j];
            isThereBack = 0;

            //===============================================
            // BLOCO VERIFICAÇÃO ANTES DO NUMERO SELECIONADO
            //===============================================

            auxJ = 0;
            for(auxI = 0; auxI < rowLen; auxI++)
            {
                if(auxJ == colLen)
                    auxJ = 0;

                while(auxJ < colLen)
                {
                    // Caso exista um numero igual, atribui como verdadeiro
                    if(currentElem == matriz[auxI][auxJ])
                    {
                        if(auxI != i || auxJ != j)
                            isThereBack = 1;
                    }

                    // Caso chegue na posição do elemento, finaliza o laço
                    if(auxI == i && auxJ == j)
                    {
                        auxI = rowLen;
                        auxJ = colLen;
                    }
                    auxJ++;
                }
            }

            // Caso não exista numero iguais para trás
            if(isThereBack == 0)
            {
                //================================================
                // BLOCO VERIFICAÇÃO DEPOIS DO NUMERO SELECIONADO
                //================================================
                auxJ = j;
                countEquals = 1;

                for(auxI = i; auxI < rowLen; auxI++)
                {
                    // Caso chegue no final da linha, quebra pra debaixo
                    if(auxJ == colLen)
                        auxJ = 0;

                    while(auxJ < colLen)
                    {
                        // Existe um outro igual
                        if(currentElem == matriz[auxI][auxJ])
                        {
                            if(auxI != i || auxJ != j)
                                countEquals++;
                        }
                        auxJ++;
                    }
                }

                if(countEquals > 1)
                {
                    printf("\nO numero %d aparece %d vezes;", currentElem, countEquals);
                    existRepeatedNumber = 1;
                }
            }
        }
    }
    if(existRepeatedNumber == 0)
        printf("\nInfelizmente, nao existe numero repetido na matriz!");
}
//===============================================================
void SortMatriz(int matriz[][COLUMN], int rowLen, int colLen)
{
    int auxNum;
    int i;
    int j;
    for(int indexElem = 1; indexElem <= rowLen * colLen; indexElem++)
    {
        for(i = 0; i < rowLen; i++)
        {
            for(j = 0; j < colLen - 1; j++) // col - 1 pois será compensado com o j + 1
            {
                // Elemento atual ser maior que o da frente
                // Troca de lugar com o da frente
                auxNum = 0;
                if(matriz[i][j] > matriz[i][j+1])
                {
                    auxNum = matriz[i][j];
                    matriz[i][j] = matriz[i][j+1];
                    matriz[i][j+1] = auxNum;
                }
            }

            // Caso o i == rowLen, não entra
            if(i < rowLen - 1)
            {
                // Verificar o ultimo elemento é maior que o da linha debaixo
                if(matriz[i][j] > matriz[i+1][0])
                {
                    auxNum = matriz[i][j];
                    matriz[i][j] = matriz[i+1][0];
                    matriz[i+1][0] = auxNum;
                }
            }
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
    int matriz[ROW][COLUMN];
    int rows, columns = 0;
    char name[100];

    // Limpar a matriz base 50x50
    ClearMatriz(matriz, ROW, COLUMN);

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

    system("cls");
    ShowMatriz(matriz, rows, columns);

    ShowRepeatedNumbers(matriz, rows, columns);

    // Finalizar Programa
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");
    return 0;
}
