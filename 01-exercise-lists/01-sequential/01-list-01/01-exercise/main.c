/*===============================================================

    Elabore um algoritmo que solicite ao operador as seguintes informações de uma pessoa: nome,
    idade, sexo, altura, profissão, rua, bairro, cidade, estado, CEP.
    Mostre no vídeo o seguinte relatório:
    // ===============================================================
    // JOAO DA SILVA, voce tem 20 anos, sexo MASCULINO
    // tem 1.85 metros de altura
    // sua profissao eh PROFESSOR
    // mora no endereco: AV. SAUDADE, 777
    // bairro CENTRO - CEP: 38.100-000 - UBERABA (MG)
    // ===============================================================

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
    char nome[100], sexo[25], profissao[100], rua[100], bairro[100], cidade[100], estado[75], cep[25];
    int idade;
    float altura;

    //INICIALIZAR VARIAVEIS
    strcpy(nome, "");
    strcpy(sexo, "");
    strcpy(profissao, "");
    strcpy(rua, "");
    strcpy(bairro, "");
    strcpy(cidade, "");
    strcpy(estado, "");
    strcpy(cep, "");
    idade = 0;
    altura = 0;

    //ATRIBUIR VARIAVEIS

    // Nome
    printf("Informe o nome: ");
    fflush(stdin);
    gets(nome);

    // Idade
    printf("Digite a idade: ");
    fflush(stdin);
    scanf("%d", &idade);

    // Sexo
    printf("Digite o sexo (Masculino ou Feminino): ");
    fflush(stdin);
    gets(sexo);

    // Altura
    printf("Digite a altura: ");
    fflush(stdin);
    scanf("%f", &altura);

    // Profissao
    printf("Informe a profissao: ");
    fflush(stdin);
    gets(profissao);

    // Rua
    printf("Digite a rua com o numero da casa: ");
    fflush(stdin);
    gets(rua);

    // Bairro
    printf("Digite o bairro: ");
    fflush(stdin);
    gets(bairro);

    // Cidade
    printf("Informe a cidade: ");
    fflush(stdin);
    gets(cidade);

    // Estado
    printf("Informe as siglas do estado: ");
    fflush(stdin);
    gets(estado);

    // CEP
    printf("Digite o CEP, com os marcadores: ");
    fflush(stdin);
    gets(cep);

    //FINALIZAR PROGRAMA
    printf("\n\n\n================================================================");
    printf("\n %s, vc tem %d anos, sexo %s", nome, idade, sexo);
    printf("\n tem %.2f metros de altura", altura);
    printf("\n sua profissao eh %s", profissao);
    printf("\n mora no endereco: %s", rua);
    printf("\n bairro %s - CEP: %s - %s (%s)", bairro, cep, cidade, estado);
    printf("\n================================================================");
    printf ("\n\n\n FIM DO PROGRAMA, VALEUUUU :) \n\n\n");
    return 0;
}
