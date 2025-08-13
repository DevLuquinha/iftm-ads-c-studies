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

int main()
{
    return 0;   
}

// Esse programa deve:
// Ler os dados de duas contas
// Mostrar os dados de cada conta
// Permitir que se realize uma transferência de valores de uma conta para a outra
// Mostrar os dados de cada conta novamente

// Sugestões para as funções do programa:
// • uma função para ler os dados de uma conta
// • uma função para mostrar os dados de uma conta
// • uma função para transferir valor de uma conta para outra