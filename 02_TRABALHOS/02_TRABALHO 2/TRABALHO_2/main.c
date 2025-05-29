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
#define size 300

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
        printf("\nDigite um numero INTEIRO entre (1-9). OBS: 0 FINALIZA A ENTRADA...: ");
        fflush(stdin);
        scanf("%f", &num);

        numInt = num;

        if(numInt != num || numInt < 0 || numInt > 9)
        {
            printf("\n================================================================");
            printf("\nErro! Vc digitou um numero invalido! NUMERO NAO CONTABILIZADO!!!");
            printf("\n================================================================");
        }

    }while(numInt != num || numInt < 0 || numInt > 9);

    return numInt;
}
//===============================================================
int GetSingleIntNumber(int vector[])
{
    float num;
    int numInt;
    int hasNumber;
    do
    {
        hasNumber = 0;

        printf("\nDigite um numero INTEIRO positivo. OBS: 0 FINALIZA A ENTRADA...: ");
        fflush(stdin);
        scanf("%f", &num);

        numInt = num;

        if(numInt != num || numInt < 0)
        {
            printf("\n================================================================");
            printf("\nErro! Vc digitou um numero invalido! NUMERO NAO CONTABILIZADO!!!");
            printf("\n================================================================");
        }

        for(int i = 0; i < size; i++)
        {
            if(vector[i] != 0)
            {
                if(vector[i] == numInt)
                {
                    hasNumber = 1;
                }
            }
        }

        if(hasNumber == 1)
        {
            printf("\n========================================================================");
            printf("\nErro! Vc digitou um numero %d que ja EXISTE! NUMERO NAO CONTABILIZADO!!!", numInt);
            printf("\n========================================================================");
        }
    }while(numInt != num || numInt < 0 || hasNumber == 1);

    return numInt;
}
//===============================================================
void GetSequenceNumbers(int vector[], int lastIndex)
{
    int biggestSequence = 0;
    int indexStartSequence = 0;
    int sequenceLen = 0;
    int auxI, auxJ = 0;
    int isFirst = 1;

    for(int i = 0; i < lastIndex - 1; i++)
    {
        if(vector[i] == vector[i+1]) // Caso sejam iguais e seja a primeira
        {
            if(isFirst == 1)
            {
                isFirst = 0; // Sim ele eh o primeiro então desmarca

                // Copia as propriedades das posições
                auxI = i;
                auxJ = i+1;

                // Laço para contabilizar o tamanho da sequencia
                while(vector[auxI] == vector[auxJ])
                {
                    sequenceLen++;
                    auxJ++;
                }

                biggestSequence = sequenceLen + 1;
                indexStartSequence = i;
            }
            else
            {
                auxI = i;
                auxJ = i+1;
                sequenceLen = 1;

                // Laço para contabilizar o tamanho da sequencia
                while(vector[auxI] == vector[auxJ])
                {
                    sequenceLen++;
                    auxJ++;
                }

                if(sequenceLen > biggestSequence)
                {
                    biggestSequence = sequenceLen;
                    indexStartSequence = i;
                }
            }
        }
    }

    // Mostragem da sequencia repetida
    printf("\n=================================================");
    if(biggestSequence == 0)
        printf("\nNao foi digitado nenhuma sequencia numerica consecutiva! ");
    else
    {
        printf("\nA maior sequencia foi: ");
        for(int i = 0; i < biggestSequence; i++)
        {
            if(i + 1 == biggestSequence)
            {
                Sleep(100);
                printf("%d. ", vector[i+indexStartSequence]);
            }
            else
            {
                Sleep(100);
                printf("%d, ", vector[i+indexStartSequence]);
            }
        }
    }
}
//===============================================================
int GetDifference(int num1, int num2)
{
    int module = 0;

    if(num1 - num2 < 0)
        module = (num1 - num2) * -1;
    else if(num1 - num2 > 0)
        module = num1 - num2;

    return module;
}
//===============================================================
void DifferenceNumbersByVector(int vector[], int lastIndex)
{
    int mostDifference = 0;
    int difference;

    for(int i = 0; i < lastIndex -1; i++)
    {
        difference = 0;

        if(i == 0)
            mostDifference = GetDifference(vector[i], vector[i+1]);
        else
        {
            difference = GetDifference(vector[i], vector[i+1]);
            if(difference > mostDifference)
                mostDifference = difference;
        }
    }

    // Mostragem da maior diferença
    printf("\n=================================================");

    if(mostDifference == 0)
        printf("\nNAO EXISTE DIFERENCA! DIGITE PELO MENOS DOIS NUMEROS!!!");
    else
        printf("\n\nA MAIOR DIFERENCA EH: %d", mostDifference);
}
//===============================================================
void InputVector(int vector[], int opt)
{
    system("cls");

    if(opt == 1)
    {
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
    else if(opt == 2)
    {
        printf("2 - Maior diferenca entre dois numeros consecutivos");
        int num = 0;
        int i = 0;

        do
        {
            num = GetSingleIntNumber(vector);
            if(num != 0)
            {
                vector[i] = num;
                i++;
            }
        }while(num != 0);
    }
}
//===============================================================
void ShowVector(int vector[], int opt)
{
    int endI = 0;

    printf("\n========== VETOR EM FORMA DE ENTRADA ============\n");

    int col = 1;

    for(int i = 0; i < size; i++)
    {
        if(endI == 0 && vector[i] == 0)
            endI = i;

        if(vector[i] != 0)
        {
            Sleep(50);
            printf("     %3d ", vector[i]);

            if(col % 5 == 0)
            {
                printf("\n");
                col = 0;
            }
            col++;
        }
    }


    if(opt == 1) // Pegar qual a maior sequencia de numeros
        GetSequenceNumbers(vector, endI);
    else if(opt == 2) // Pegar maior diferenca entre dois numeros
        DifferenceNumbersByVector(vector, endI);
}
//===============================================================
void EndProgram()
{
    Sleep(500);
    printf("\nFIM?\n");
    Sleep(1000);

    printf("\nOU SERA QUE NAO ^-^\n");
    Sleep(2500);

    printf("\nVC AINDA TA AQUI (0_0)?\n");
    Sleep(2500);

    printf("\nTA BOM... CANSEI :-( \n");
    Sleep(2500);
}
//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // OBSERVAÇÕES EX 1:
    // A) Criar pelo menos duas funções
    // B) Usar somente 1 vetor
    // C) Mostrar somente as posições que tiveram entradas via teclado
    // D) Dar uma mensagem caso não tenha sequencia de numeros iguais consecutivos

    // OBSERVAÇÕES EX 2:
    // A) Mostrar o vetor em sua forma de entrada
    // B) No mínimo 2 funções
    // C) Usar somente vetor
    // D) Mostrar somente as posições que tiverem entradas via teclado
    // E) Validar Corretivamente na entrada.

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
            InputVector(vector, optMenu);

            ShowVector(vector, optMenu);

            printf("\n\nPARA VOLTAR AO MENU, APERTE QUALQUER TECLA ");
            getch();
        }
    }while(optMenu != 3);

    //FINALIZAR PROGRAMA
    printf("\nFINALIZANDO PROGRAMA..........: ");
    for(int i = 5; i >= 1; i--)
    {
        Sleep(500);
        printf("%d", i);

        if(i == 1)
            printf(".");
        else
            printf(", ");
    }

    // Mostra a tela de carregamento
    printf("\n");
    for(int i = 0; i <= 45; i++)
    {
        Sleep(25);
        printf("%c", 220);
    }

    printf("\n");
    EndProgram();

    printf ("\n\nFIM DO PROGRAMA - OBRIGADO POR USAR O PROGRAMA :) \n\n\n");

    return 0;
}
