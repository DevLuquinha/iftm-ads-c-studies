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
int GetNotNullOrRepeated(int vector[])
{
    int num, hasNum;

    do
    {
        hasNum = num = 0;
        do // Não Gerar numeros Nulos
        {
            num = rand() % (len + 1);
        }while(num == 0);

        for(int i = 0; i < len; i++)
        {
            if(vector[i] == num)
                hasNum = 1;
        }

        if(hasNum == 0)
            return num;

    }while(hasNum == 1);
}
//===============================================================
int GetLastIndex(int vector[])
{
    int index = 0;
    for(int i = 0; i < len; i++)
    {
        if(vector[i] == 0 && index == 0)
            index = i;
    }

    return index - 1;
}
//===============================================================
void OrderVector(int vector[], int lastIndex)
{
    int auxValue;

    for(int j = 0; j < lastIndex; j++) // Repete a quantidade de vezes do vetor
    {
        for(int i = 0; i < lastIndex; i++)
        {
            auxValue = 0;
            if(vector[i] > vector[i+1])
            {
                auxValue = vector[i];

                // Troca o valor. Ex: [3, 2] --> [2, 3]
                vector[i] = vector[i+1];
                vector[i+1] = auxValue;
            }
        }
    }
}
//===============================================================
void FillRandomNumbers(int vector[], int vectorLen)
{
    int num = 0;
    for(int i = 0; i < vectorLen; i++)
    {
        vector[i] = GetNotNullOrRepeated(vector);
    }
}
//===============================================================
void ShowVector(int vector[])
{
    int col = 0;

    for(int i = 0; i < len; i++)
    {
        if(vector[i] != 0)
        {
            if(col % 5 == 0)
            {
                printf("\n");
                col = 0;
            }
            Sleep(25);
            printf("%6d", vector[i]);
            col++;
        }
    }
}
//===============================================================
int ShowMenu()
{
    int indexMenu;

    printf("\n\n===========MENU DE OPCOES===========");
    printf("\n1 - INSERIR NUMERO");
    printf("\n2 - EXCLUIR NUMERO");
    printf("\n3 - SAIR");
    printf("\n====================================");
    do
    {
        printf("\nEscolha o numero de uma das opcoes acima...: ");
        fflush(stdin);
        scanf("%d", &indexMenu);

        if(indexMenu < 1 || indexMenu > 3)
            printf("\nOPCAO INVALIDA! ESCOLHA NOVAMENTE!!!");
    }while(indexMenu < 1 || indexMenu > 3);

    return indexMenu;
}
//===============================================================
int NumberInVector(int num, int vector[], int vectorLen)
{
    int index = -1;
    for(int i = 0; i < vectorLen; i++)
    {
        if(vector[i] == num)
            index = i;
    }

    return index;
}
//===============================================================
int GetNumber()
{
    int num = 0;

    do
    {
        printf("\nDigite o numero maior que 1 que deseje inserir: ");
        fflush(stdin);
        scanf("%d", &num);

        if(num < 1)
            printf("\nDIGITE UM NUMERO VALIDO!!!");
    }while(num < 1);

    return num;
}
//===============================================================
int GetIndexInsertNumber(int num, int vector[], int vectorLen)
{
    int index = -1;
    int findIndex = 0;

    for(int i = 0; i <= vectorLen; i++)
    {
        if(findIndex == 0 && vector[i] > num)
        {
            findIndex = 1;
            index = i;
        }
    }

    return index;
}
//===============================================================
void UpdateVector(int index, int vector[], int vectorLen)
{
    for(int i = vectorLen; i >= index; i--)
    {
        vector[i+1] = vector[i];
    }
}
//===============================================================
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    /* ESPECIFICAÇÕES DA ATIVIDADE
       1) Função para preencher até a metade de linhas do vetor
       2) Função para validar corretivamente durante a entrada para
          não ter zero nem numeros repetidos
       3) Função para ordenar o vetor em ordem crescente
       4) Função para mostrar o vetor até a posição em que está sendo utilizada
       5) Função para pesquisar no vetor a existencia ou não do número a ser inserido
       6) Função para receber o números de pesquisa e validar corretivamente não menor que 1

       -------------------------------------------------------------------------------------
       1) Será utilizada apenas um vetor para inserção e/ou exclusão (proibido uso de
          outro vetor)
       2) Só criar o menu após preencher e ordenar o vetor até a posição em que foi
          preenchida.
    */

    // CRIAR VARIAVEIS
    int vector[len];
    int lastIndex, option;

    printf("======VETOR EM FORMA DE ENTRADA======");

    // Preencher vetor com numeros aleatorios até a metade
    FillRandomNumbers(vector, len/2);

    // Vetor em forma de entrada
    ShowVector(vector);

    // Pega o index do ultimo item usado
    lastIndex = GetLastIndex(vector);

    // Vetor Ordenado
    printf("\n\n===========VETOR ORDENADO===========");
    OrderVector(vector, lastIndex);
    ShowVector(vector);

    do
    {
        // LIMPA O VETOR
        ClearVector(vector);

        option = ShowMenu();

        if(option != 3)
        {
            if(option == 1)
            {
                // Variaveis para o EX 1
                int indexNum, num = 0;
                int posiNum = 0;

                do
                {
                    num = GetNumber(); // Recebe um numero maior do que 1

                    indexNum = NumberInVector(num, vector, lastIndex + 1); // Caso não exista, retorna -1

                    if(indexNum == -1)
                    {
                        printf("\nNAO EXISTE O NUMERO INFORMADO! %d", num);

                        // Verificar o index onde será adicionado o numero
                        posiNum = GetIndexInsertNumber(num, vector, lastIndex);

                        //printf("\n%d devera ser posicionado no index V[%d]", num, posiNum);

                        // Passar todo o vetor para frente
                        UpdateVector(posiNum, vector, lastIndex);

                        // Inserir o numero no index
                        vector[posiNum] = num;

                        // Vetor Ordenado
                        printf("\n\n===========NOVO VETOR===========");
                        ShowVector(vector);
                    }
                    else
                        printf("\nO NUMERO INFORMADO EXISTE NA POSICAO V[%d]. POR FAVOR DIGITE OUTRO!!!\n", indexNum, vector[indexNum]);
                }while(indexNum != -1);

            }

            printf("\nAPERTE QUALQUER TECLA PARA VOLTAR PARA O MENU ");
            getch();
        }
    }while(option != 3);

    // FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
