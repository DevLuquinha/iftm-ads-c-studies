/*===============================================================
    Elaborar um algoritmo que receba um número inteiro via teclado, verificar
    se é menor que zero, dar uma mensagem e finalizar o programa, caso contrário,
    processar e mostrar o valor do resto (MOD) deste número por 2 e por 3.

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
    int num;

    //INICIALIZAR VARIAVEIS
    num = 0;

    printf("Digite um numero inteiro positivo: ");
    fflush(stdin);
    scanf("%d", &num);

    if(num < 0)
        printf("Erro! Vc digitou um numero negativo! ");
    else{
        printf("\nO resto de %d / 2: %d", num, num % 2);
        printf("\nO resto de %d / 3: %d", num, num % 3);
    }
    //FINALIZAR PROGRAMA

    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
