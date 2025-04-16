/*===============================================================

    Sejam os seguintes dados de um funcionário: nome, idade, cargo e o seu salário bruto. Considere:
    a) o salário bruto teve um reajuste de 20%;
    b) o salário bruto total (salário bruto + 20%) é descontado 15% para se obter o salário líquido.
    Elabore um algoritmo que solicite os dados do funcionário processe e mostre no vídeo:
     o nome, a idade e o cargo;
     o salário bruto total;
     o salário líquido.

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
    char nome[100], cargo[100];
    int idade;
    float salarioBruto, salarioLiquido;

    //INICIALIZAR VARIAVEIS
    strcpy(nome, "");
    strcpy(cargo, "");
    idade = 0;
    salarioBruto = 0;
    salarioLiquido = 0;

    printf("\n Digite o nome do funcionario: ");
    fflush(stdin);
    gets(nome);

    printf("\n Digite a idade do funcionario: ");
    fflush(stdin);
    scanf("%d", &idade);

    printf("\n Digite o cargo do funcionario: ");
    fflush(stdin);
    gets(cargo);

    printf("\n Digite o salario bruto do funcionario: ");
    fflush(stdin);
    scanf("%f", &salarioBruto);

    salarioBruto = salarioBruto * 1.20;
    salarioLiquido = salarioBruto * 0.85;

    //FINALIZAR PROGRAMA
    printf("\n\n Pressione qualquer tecla para visualizar o relatorio: ");
    getch(); // Retorna o codigo ASCII

    system("cls");

    printf("\n\n\n O funcionario %s tem %d anos e trabalha como %s", nome, idade, cargo);
    printf("\n O salario bruto foi de %.2f, porem o salario liquido foi de %.2f", salarioBruto, salarioLiquido);
    printf ("\n\n\n FIM DO PROGRAMA, VALEUUUU :) \n\n\n");

    return 0;
}
