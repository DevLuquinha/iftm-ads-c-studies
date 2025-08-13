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

Account GetAccount()
{
    Account account;

    // Atribui a propriedade num
    fflush(stdin);
    scanf("%i", &account.num);

    // Atribui a propriedade name
    fflush(stdin);
    gets(account.name);

    // Atribui a propriedade balance
    fflush(stdin);
    scanf("%f", &account.balance);

    return account;
}

int main()
{
    // Inicializar contas
    Account account1, account2;

    // Ler os dados de duas contas
    account1 = GetAccount();

    return 0;   
}

// Esse programa deve:
// Mostrar os dados de cada conta
// Permitir que se realize uma transferência de valores de uma conta para a outra
// Mostrar os dados de cada conta novamente

// Sugestões para as funções do programa:
// • uma função para ler os dados de uma conta
// • uma função para mostrar os dados de uma conta
// • uma função para transferir valor de uma conta para outra