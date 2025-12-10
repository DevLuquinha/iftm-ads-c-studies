/*===============================================================


    CURSO: ANALISE E DESENVOLVIMENTO DE SISTEMAS - ADS
    1º PERÍODO - DISCIPLINA DE ALGORITMO E LÓGICA DE PROGRAMAÇÃO
    Nome do aluno(a): Lucas Emmanuel Rodrigues Firmino de Paula
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: Março 2025

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

//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    //CRIAR VARIAVEIS
    float salarioBase, salarioLiquido, gratificacao, deducao;

    //INICIALIZAR VARIAVEIS
    salarioBase = salarioLiquido = gratificacao = deducao = 0;

    printf("\n Digite o valor do salario base: ");
    fflush(stdin);
    scanf("%f", &salarioBase);

    if(salarioBase < 0)
        printf("\n Valor invalido, vc digitou um salario menor do que 0.");
    else if (salarioBase == 0)
        printf("\n Nao houve salario recebido");
    else
    {
        // Gratificações
        if(salarioBase <= 300)
            gratificacao = 100;
        else if(salarioBase > 300 && salarioBase <= 500)
            gratificacao = 75;
        else if(salarioBase > 500 && salarioBase <= 1000)
            gratificacao = 50;
        else
            gratificacao = 30;

        // Deduções
        if(salarioBase <= 200)
            deducao = 0;
        else if(salarioBase > 200 && salarioBase <= 500)
            deducao = salarioBase * 0.03;
        else if(salarioBase > 500 && salarioBase <= 700)
            deducao = salarioBase * 0.05;
        else if(salarioBase > 700 && salarioBase <= 1000)
            deducao = salarioBase * 0.08;
        else
            deducao = salarioBase * 0.1;

        salarioLiquido = salarioBase + gratificacao - deducao;

        printf("\n\n O valor do Salario Base..........: R$ %8.2f", salarioBase);
        printf("\n O valor das Gratificacoes........: R$ %8.2f", gratificacao);
        printf("\n O valor das Deducoes.............: R$ %8.2f", deducao);
        printf("\n O valor do Salario Liquido.......: R$ %8.2f", salarioLiquido);

    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
