/*===============================================================
    Elaborar um algoritmo que receba um número positivo via teclado,
    Verificar se ele é maior que zero, caso verdadeiro, processar o cálculo do cubo desse
    número e mostrar o resultado, caso contrário dê uma mensagem de número inválido.

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
    float num, area;

    //INICIALIZAR VARIAVEIS
    num  = 0;
    area = 0;

    printf("\n Digite um numero positivo: ");
    fflush(stdin);
    scanf("%f", &num);

    if(num > 0){
        system("cls");
        area = pow(num, 3);
        printf("O cubo de %.1f eh igual a: %.1f", num, area);
    }
    else{
        // Limpa o terminal e mostra a mensagem
        system("cls");
        printf("\n Vc digitou um numero negativo, por favor digite um numero positivo! ");
    }
    //FINALIZAR PROGRAMA

    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}

