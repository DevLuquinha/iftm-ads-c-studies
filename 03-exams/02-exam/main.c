/*
    Nome Completo: Lucas Emmanuel Rodrigues Firmino de Paula
    Curso: Análise e Desenvolvimento de Sistemas
    CPF: 70.681.836-39
    Data: 04/06/2025
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <conio.h>
#define SIZE 1000


int GetInt(char message[300]) // Pega apenas um numero inteiro
{
    float num = 0;
    int numInt = 0;

    do
    {
        printf("\n%s", message);
        fflush(stdin);
        scanf("%f", &num);

        numInt = num;
        if(num != numInt)
            printf("\nERRO! DIGITE UM NUMERO INTEIRO!");
    }while(num != numInt);

    return numInt;
}

int InputMenu() // Retorna a opção escolhida pelo usuário no menu
{
    int num;

    printf("\n    TRANSACOES BANCARIAS");
    printf("\n\n1) Deposito (entrada)");
    printf("\n2) Retiradas (saida)");
    printf("\n3) Relatorio saldo atual");
    printf("\n4) Relatorio Extrato do periodo do mes");
    printf("\n5) Finalizar");

    do
    {
        num = GetInt("Informe uma das opcoes (1, 2, 3, 4 ou 5)....: ");
        if(num < 1 || num > 5)
            printf("\nERRO! INFORME APENAS AS OPCOES LISTADAS ACIMA!!!");
    }while(num < 1 || num > 5);

    return num;
}

void InputDayVector(int vector[], int lastIndex) // Atribui o dia no vetor de dias
{
    int numDay;
    int isRepeated;

    do
    {
        numDay = 0;
        isRepeated = 0;

        do
        {
            // Pega um numero inteiro
            numDay = GetInt("Informe o dia da data de hoje ...: ");
            if(numDay < 1 || numDay > 31)
                printf("\nDIA INVALIDO ... INFORME OUTRO DIA!!!");
        }while(numDay < 1 || numDay > 31);

        if(lastIndex == 0) // Primeiro dia
        {
            vector[lastIndex] = numDay;
        }
        else
        {
            for(int i = 0; i <= lastIndex; i++)
            {
                if(numDay < vector[i])
                    isRepeated = 1;
            }

            if(isRepeated == 0)
                vector[lastIndex] = numDay;
        }

        if(isRepeated == 1)
            printf("\nDIA INVALIDO ... INFORME OUTRO DIA!!!");
    }while(isRepeated == 1);
}

void InputDeposit(char vector[][100], int lastIndex) // Atribui o tipo de deposito no vetor de strings
{
    char type[100];

    do
    {
        strcpy(type, "");

        printf("\nInforme digite nome do tipo de deposito (dinheiro, pix)...: ");
        fflush(stdin);
        gets(type);

        if(strcmp(type, "dinheiro") != 0 && strcmp(type, "pix") != 0)
        {
            printf("\nERRO!!! TIPO DE DEPOSITO NAO SELECIONADO!!!");
        }
    }while(strcmp(type, "dinheiro") != 0 && strcmp(type, "pix") != 0);

    strcpy(vector[lastIndex], type); // Adiciona no vetor
}

void InputValues(float vector[], int lastIndex) // Atribui os valores para o vetor
{
    float num;

    do
    {
        printf("\nInforme o valor...: ");
        fflush(stdin);
        scanf("%f", &num);

        if(num <= 0)
            printf("\nErro! VALOR INVÁLIDO!");
    }while(num <= 0);

    vector[lastIndex] = num;
}

int InputBalance(float balance[], float value[], int lastIndex, int type) // Atribui o saldo do usuário e retorna se a transação foi bem sucedida
{
    int isSucceful = 0; // Por padrão deu certo!

    if(type == 1)
    {
        if(lastIndex == 0)
        {
            balance[lastIndex] = value[lastIndex];
        }else
        {
            balance[lastIndex] = balance[lastIndex -1] + value[lastIndex];
        }
        isSucceful = 0; // Deu certo :)
    }
    else if(type == 2)
    {
        if(lastIndex == 0)
        {
            printf("\nERRO! Vc nao depositou nada na conta! Como pode sacar a grana?");
            printf("\nO SAQUE NAO FOI EFETUADO!!!");
            isSucceful = 1; // Deu erro!
        }
        else if(balance[lastIndex - 1] - value[lastIndex] < 0)
        {
            printf("\nERRO! VC ESTA TENTANDO SACAR UM VALOR SUPERIOR AO QUE POSSUI NA CONTA :(");
            printf("\nO SAQUE NAO FOI EFETUADO!!!");
            isSucceful = 1; // Deu erro!
        }
        else
        {
            balance[lastIndex] = balance[lastIndex - 1] - value[lastIndex];
            isSucceful = 0; // Deu certo!
        }
    }

    return isSucceful;
}

void InputStatus(char vector[][100], int lastIndex, int type) // Atribui o status para o vetor
{
    if(type == 1)
    {
        strcpy(vector[lastIndex], "C");
    }
    else if(type == 2)
    {
        strcpy(vector[lastIndex], "D");
    }

}
//==================Limpar e Mostrar Vetores==================
void ClearIntVector(int vector[],int len)
{
    for(int i = 0; i < len; i++)
        vector[i] = 0;
}

void ClearStringVector(char vector[][100], int len)
{
    for(int i = 0; i < len; i++)
        strcpy(vector[i], "");
}

void ClearFloatVector(float vector[],int len)
{
    for(int i = 0; i < len; i++)
        vector[i] = 0.0;
}

void ClearValues(int days[], char deposits[][100], char status[][100], float values[], float balance[], int index)
{
    days[index] = 0;
    strcpy(deposits[index], "");
    strcpy(status[index], "");
    values[index] = 0.0;
    balance[index] = 0.0;
}

void ShowResult(int days[], char deposits[][100], char status[][100], float values[], float balance[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("\n%4d - %9s  %8s %15.2f %20.2f", days[i], deposits[i], status[i], values[i], balance[i]);
    }
}

void ShowLoading()
{
    printf("\n\nAguarde ....... atualizando sistema\n\n");
    for(int i = 0; i <= 40; i++)
    {
        Sleep(20);
        printf("%c", 178);
    }

}
int main()
{
    // Declarar as variaveis e os 5 vetores
    int optionMenu = 0;
    int index = 0;

    int dayVec[SIZE];
    char depositVec[SIZE][100];
    char statusVec[SIZE][100];
    float valuesVec[SIZE];
    float balanceVec[SIZE];

    // Limpar vetores
    ClearIntVector(dayVec, SIZE);
    ClearStringVector(depositVec, SIZE);
    ClearStringVector(statusVec, SIZE);
    ClearFloatVector(valuesVec, SIZE);
    ClearFloatVector(balanceVec, SIZE);

    do
    {
        system("cls");
        // Recebe a opção escolhida do menu
        optionMenu = InputMenu();

        if(optionMenu == 1)
        {
            printf("\nOpcao 1 - Deposito (entrada)");

            InputDayVector(dayVec, index); // Adicionar o dia

            InputDeposit(depositVec, index); // Adiciona o tipo no vetor de string

            InputValues(valuesVec, index); // Adiciona o valor

            InputBalance(balanceVec, valuesVec, index, 1);

            InputStatus(statusVec, index, 1);

            index++;
        }
        else if(optionMenu == 2)
        {
            int isSuccess;

            printf("\nOpcao 2 - Saque (saida)");

            InputDayVector(dayVec, index);

            InputDeposit(depositVec, index);

            InputValues(valuesVec, index);

            isSuccess = InputBalance(balanceVec, valuesVec, index, 2);

            InputStatus(statusVec, index, 2);

            index++;

            if(isSuccess == 1) // Caso seja falso
            {
                ClearValues(dayVec, depositVec, statusVec, valuesVec, balanceVec, index);
                index--;
            }
        }
        else if(optionMenu == 3)
        {
            printf("\nOpcao 3 - Saldo do atual");
            if(index != 0)
                printf("\n\nSaldo atual = R$ %.2f", balanceVec[index-1]);
            else if(index == 0)
            {
                printf("\n\nSaldo atual = R$ 0.00");
                printf("\nVC AINDA NAO FEZ NENHUMA TRANSACAO BANCARIA!!!");
            }
        }
        else if(optionMenu == 4)
        {
            printf("\nOpcao 4 - Relatorio Extrato por periodo no mensal");
            printf("\n\n                     EXTRATO COMPLETO");
            printf("\n==================================================================");
            printf("\n dia      descricao    status    valor da transacao    saldo atual");
            printf("\n==================================================================");
            ShowResult(dayVec, depositVec, statusVec, valuesVec, balanceVec, index);

        }
        if(optionMenu != 5)
        {
            printf("\n\nAPERTE QUALQUER TECLA PARA VOLTAR AO MENU ");
            getch();
            ShowLoading();
        }
    }while(optionMenu != 5);

    // Finaliza o programa
    printf("\nFinalizando Programa..:");
    for(int i = 0; i < 24; i++)
    {
        Sleep(20);
        printf("%c", 178);
    }

    printf("\n\nFIM DA AVALIACAO DO LUQUINHAS:)");
    return 0;
}
