/*===============================================================
    Receber 2 valores inteiros (VLA e VLB), efetuar a soma e armazenar na variável
    VLX. Verificar o valor de VLX, caso o seu conteúdo seja maior que 10 mostrar uma
    mensagem que o resultado é maior que 10, senão se ele for menor que 10 ou senão uma
    mensagem que é igual a 10.

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
    int vlA, vlB, vlX;

    //INICIALIZAR VARIAVEIS
    vlA = vlB = vlX = 0;

    printf("\n Digite o primeiro numero: ");
    fflush(stdin);
    scanf("%d", &vlA);

    printf("\n Digite o segundo numero: ");
    fflush(stdin);
    scanf("%d", &vlB);

    vlX = vlA + vlB;

    // Verificar se ele eh menor, maior ou igual
    if(vlX > 10){
        printf("\n (%d + %d = %d), %d eh maior que 10",vlA, vlB, vlX, vlX);
    }
    else if(vlX < 10){
        printf("\n (%d + %d = %d), %d eh menor que 10",vlA, vlB, vlX, vlX);
    }
    else{
        printf("\n (%d + %d = %d), %d eh igual a 10",vlA, vlB, vlX, vlX);
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
