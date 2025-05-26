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
#define size 49

//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
int InputMenu()
{
    float num;
    int numInt;

    printf("                  MENU DE OPCOES");
    printf("\n====================================================");
    printf("\n1 - Maior sequencia de numeros iguais consecutivos");
    printf("\n2 - Maior diferenca entre dois numeros consecutivos");
    printf("\n3 - Sair");

    do
    {
        printf("\nEscolha o numero de uma das opcoes acima...: ");
        fflush(stdin);
        scanf("%f", &num);

        numInt = num;

        if(numInt != num || numInt < 1 || numInt > 3)
            printf("\nErro! Vc digitou uma opcao incorreta. Digite apenas as opcoes contidas no menu!");
    }while(numInt != num || numInt < 1 || numInt > 3);

    return numInt;
}
//===============================================================
void ClearVector(int vector[])
{
    for(int i = 0; i < size; i++)
        vector[i] = 0;
}
//===============================================================
int GetIntNumber()
{
    float num;
    int numInt;

    do
    {
        printf("\nDigite um numero inteiro entre (1-9). OBS: 0 FINALIZA A ENTRADA...: ");
        fflush(stdin);
        scanf("%f", &num);

        numInt = num;

        if(numInt != num || numInt < 0 || numInt > 9)
            printf("\nErro! Vc digitou um numero invalido!");
    }while(numInt != num || numInt < 0 || numInt > 9);

    return numInt;
}
//===============================================================
void GetSequenceNumbers(int vector[])
{
    int biggestSequence = 0;
    int indexEndSequence = 0;
    int sequenceLen = 0;
    int i = 0;

    for(int i = 0; i < size; i++)
    {
        if(vector[i] != 0)
        {
            // Verificar se [i] é igual a [i + 1]
            if(vector[i] == vector[i+1])
            {
                biggestSequence++;
                indexEndSequence = i + 1;
            }
        }
    }
    printf("\n O index Final eh %d", indexEndSequence);
}
//===============================================================
void InputVector(int vector[])
{
    system("cls");
    printf("1 - Maior sequencia de numeros iguais consecutivos");
    int num = 0;
    int i = 0;

    do
    {
        num = GetIntNumber();
        if(num != 0)
        {
            vector[i] = num;
            i++;
        }
    }while(num != 0);
}
//===============================================================
void ShowVector(int vector[])
{

    printf("\n========== VETOR EM FORMA DE ENTRADA ============\n");
    int col = 1;

    for(int i = 0; i < size; i++)
    {
        if(vector[i] != 0)
        {
            printf("     %3d ", vector[i]);

            if(col % 5 == 0)
            {
                printf("\n");
                col = 0;
            }
            col++;
        }
    }

    // Pegar qual a maior sequencia de numeros
    GetSequenceNumbers(vector);
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // OBSERVAÇÕES Exercicio 1:
    // A) Criar pelo menos duas funções
    // B) Usar somente 1 vetor
    // C) Mostrar somente as posições que tiveram entradas via teclado
    // D) Dar uma mensagem caso não tenha sequencia de numeros iguais consecutivos

    // CRIAR VARIAVEIS
    int vector[size], optMenu;

    do
    {
        // INICIALIZAR VETOR
        ClearVector(vector);

        system("cls");

        optMenu = InputMenu(); // Index do menu

        if(optMenu != 3)
        {
            InputVector(vector);

            ShowVector(vector);

            printf("\nPARA VOLTAR AO MENU, APERTE QUALQUER TECLA ");
            getch();
        }
    }while(optMenu != 3);

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
