/*===============================================================

    Elabore um algoritmo que leia (receba) dois valores correspondentes à largura (lado1) e ao
    comprimento (lado2) de um quadrado (desprezar valores diferentes). Calcule e mostre no vídeo a área
    deste quadrado sabendo-se que a fórmula é:


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
    float lado1, lado2, area;

    //INICIALIZAR VARIAVEIS
    lado1 = 0;
    lado2 = 0;
    area  = 0;

    printf("\nDigite a largura do quadrado: ");
    fflush(stdin);
    scanf("%f", &lado1);

    printf("\nDigite o comprimento do quadrado: ");
    fflush(stdin);
    scanf("%f", &lado2);

    area = lado1 * lado2;
    //FINALIZAR PROGRAMA
    printf("\nA area do quadrado eh %.2f", area);
    printf ("\n\n\n FIM DO PROGRAMA, VALEUUUU :) \n\n\n");

    return 0;
}
