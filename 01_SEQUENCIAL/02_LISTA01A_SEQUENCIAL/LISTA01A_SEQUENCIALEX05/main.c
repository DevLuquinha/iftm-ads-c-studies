/*===============================================================

    Elabore um algoritmo que calcule mostre o valor da área de um triângulo.
    Sabe-se que: área = (base * altura) / 2

    CURSO: ANALISE E DESENVOLVIMENTO DE SISTEMAS - ADS
    1º PERÍODO - DISCIPLINA DE ALGORITMO E LÓGICA DE PROGRAMAÇÃO
    Nome do aluno(a):
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: Fevereiro 2025

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
    float base, altura, area;

    //INICIALIZAR VARIAVEIS
    base = 0;
    altura = 0;
    area = 0;

    printf("\n Digite a base do triangulo: ");
    fflush(stdin);
    scanf("%f", &base);

    printf("\n Digite a altura do triangulo: ");
    fflush(stdin);
    scanf("%f", &altura);

    area = (base * altura) / 2.0;


    //FINALIZAR PROGRAMA
    printf("\n A area do triangulo eh %.2f", area);
    printf("\n\n\n Acabou ... Tchau ... obrigado ... \n\n\n");
}
