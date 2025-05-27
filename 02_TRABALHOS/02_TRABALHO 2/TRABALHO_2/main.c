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
void GetSequenceNumbers(int vector[])
{
    int biggestSequence = 0;
    int indexStartSequence = 0;
    int sequenceLen = 0;
    int auxI, auxJ = 0;

    // Calcular a maior sequencia
    for(int i = 0; i < size; i++)
    {
        for(int j = i + 1; j < size; j++)
        {
            if(vector[i] != 0)
            {
                // Pega a primeira sequencia repetida e atribui como maior
                if(vector[i] == vector[j] && biggestSequence == 0)
                {
                    // Copia as propriedades de i e j
                    auxI = i;
                    auxJ = j;

                    // Laço para contabilizar o tamanho da sequencia
                    while(vector[auxI] == vector[auxJ])
                    {
                        sequenceLen++;
                        auxI++;
                        auxJ++;
                    }

                    biggestSequence = sequenceLen + 1;
                    indexStartSequence = i;
                }
                else if(vector[i] == vector[j])
                {
                    auxI = i;
                    auxJ = j;
                    sequenceLen = 1;

                    while(vector[auxI] == vector[auxJ])
                    {
                        sequenceLen++;
                        auxI++;
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
    }

    // Mostragem da sequencia repetida
    printf("\n=================================================");
    if(biggestSequence == 0)
    {
        printf("\nNao foi digitado nenhuma sequencia numerica consecutiva! ");
    }
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
}
//===============================================================
void ShowVector(int vector[], int opt)
{

    if(opt == 1)
    {
        printf("\n========== VETOR EM FORMA DE ENTRADA ============\n");

        int col = 1;

        for(int i = 0; i < size; i++)
        {
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

        // Pegar qual a maior sequencia de numeros
        GetSequenceNumbers(vector);
    }
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
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
