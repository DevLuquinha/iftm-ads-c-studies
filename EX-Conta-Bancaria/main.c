#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("\n=================================================");
    printf("\nVALOR CONTA 1: %.2f", account.balance);
    printf("\n=================================================");
    account.balance -= value;

    return account;
}

Account AddValue(Account account, float value)
{
    printf("\n=================================================");
    printf("\nVALOR CONTA 2: %.2f", account.balance);
    printf("\n=================================================");

    account.balance += value;

    return account;
}

int main()
{
    // Inicializar contas
    Account account1, account2;

    // Ler os dados de duas contas
    printf("DIGITE OS DADOS DA CONTA 1:");
    account1 = GetAccount();
    
    printf("\nDIGITE OS DADOS DA CONTA 2:");
    account2 = GetAccount();
    
    // Mostrar os dados de cada conta
    printf("\n=================================================");
    printf("\nCONTA 1:");
    ShowAccountData(account1);

    printf("\n=================================================");
    printf("\nCONTA 2:");
    ShowAccountData(account2);

    // Permitir que se realize uma transferência de valores de uma conta para a outra
    float valueTransfer = GetValue();
    account1 = RemoveValue(account1, valueTransfer);
    account2 = AddValue(account2, valueTransfer);

    // Mostrar os dados de cada conta novamente
    // Mostrar os dados de cada conta
    printf("\n=================================================");
    printf("\nCONTA 1:");
    ShowAccountData(account1);

    printf("\n=================================================");
    printf("\nCONTA 2:");
    ShowAccountData(account2);
    return 0;   
}

// Esse programa deve:

// Sugestões para as funções do programa:
// • uma função para ler os dados de uma conta
// • uma função para mostrar os dados de uma conta
// • uma função para transferir valor de uma conta para outra