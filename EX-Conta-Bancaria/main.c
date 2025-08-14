#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 100

struct account
{
    int num;
    char name[30];
    float balance;
};
typedef struct account Account;

// Prototipos
int GetNumber();
float GetValue();
void GetName(char nameOut[30]);
float GetBalance();
Account GetAccount();
void ShowAccountData(Account account);
Account RemoveValue(Account account, float value);
Account AddValue(Account account, float value);

int GetNumber()
{
    int num;

    printf("\nDigite um numero: ");
    fflush(stdin);
    scanf("%i", &num);

    return num;
}

float GetValue()
{
    float value = 0;
    printf("\nDigite o valor da transferencia: ");
    fflush(stdin);
    scanf("%f", &value);

    return value;
}

void GetName(char nameOut[30])
{
    char name[30];

    printf("Digite um nome: ");
    fflush(stdin);
    gets(name);

    strcpy(nameOut, name);
}

float GetBalance()
{
    float balance;

    printf("Digite o saldo: ");
    fflush(stdin);
    scanf("%f", &balance);

    return balance;
}

Account GetAccount()
{
    Account account;

    account.num = GetNumber();
    GetName(account.name);
    account.balance = GetBalance();

    return account;
}

void ShowAccountData(Account account)
{
    printf("\n=================================================");
    printf("\nNUMERO DA CONTA: %i", account.num);
    printf("\nNOME DA CONTA:   %s", account.name);
    printf("\nSALDO DA CONTA:  R$%.2f", account.balance);
}

Account RemoveValue(Account account, float value)
{
    account.balance -= value;

    return account;
}

Account AddValue(Account account, float value)
{
    account.balance += value;

    return account;
}

void IniatilizeVector(Account accountVec[])
{
    for(int i = 0; i < LEN; i++)
    {
        accountVec[i].num = 0;
        strcpy(accountVec[i].name, "");
        accountVec[i].balance = 0.0;
    }
}

int main()
{
    // Criar Variaveis
    Account accountVec[LEN];
    Account account1, account2;
    
    // Inicializar Variaveis
    IniatilizeVector(accountVec);

    // Ler os dados de duas contas
    printf("DIGITE OS DADOS DA CONTA 1:");
    account1 = GetAccount();
    
    printf("\nDIGITE OS DADOS DA CONTA 2:");
    account2 = GetAccount();
    
    // Adiciona no vetor de contas
    accountVec[0] = account1;
    accountVec[1] = account2;

    // Mostrar os dados de cada conta
    printf("\n=================================================");
    printf("\nCONTA 1:");
    ShowAccountData(accountVec[0]);

    printf("\n=================================================");
    printf("\nCONTA 2:");
    ShowAccountData(accountVec[1]);

    // Escolher qual conta transferir
    int accountChosen = 1; // Default: 1

    printf("\nESCOLHA QUAL CONTA TRANSFERIR. [1] ou 2: ");
    scanf("%i", &accountChosen);
    
    float valueTransfer = GetValue();

    // Permitir que se realize uma transferência de valores de uma conta para a outra
    if(accountChosen == 1)
    {
        accountVec[0] = RemoveValue(accountVec[0], valueTransfer);
        accountVec[1] = AddValue(accountVec[1], valueTransfer);
    }
    else
    {
        account2 = RemoveValue(accountVec[1], valueTransfer);
        accountVec[0] = AddValue(accountVec[0], valueTransfer);
    }

    // Mostrar os dados de cada conta novamente
    printf("\n=================================================");
    printf("\nCONTA 1:");
    ShowAccountData(accountVec[0]);

    printf("\n=================================================");
    printf("\nCONTA 2:");
    ShowAccountData(accountVec[1]);
    return 0;   
}

// Esse programa deve:

// Sugestões para as funções do programa:
// • uma função para ler os dados de uma conta
// • uma função para mostrar os dados de uma conta
// • uma função para transferir valor de uma conta para outra