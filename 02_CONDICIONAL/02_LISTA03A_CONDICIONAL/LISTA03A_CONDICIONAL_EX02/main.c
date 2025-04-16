/*===============================================================
     Receber 2 valores, verificar se formam os lados de um retângulo, caso
    verdadeiro calcular a área e mostrar no vídeo, senão, mostrar uma mensagem “Estes valores
    não formam os lados e um retângulo”.
    OBS.: Verificar para não ter valores de entrada menor ou igual a zero durante cada entrada,
    só receber o próximo valor caso o primeiro seja válido.

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
    float length, width, resul;

    //INICIALIZAR VARIAVEIS
    length = width = resul = 0.0;

    // Comprimento
    printf("\n Digite o comprimento do retangulo: ");
    fflush(stdin);
    scanf("%f", &length);

    if(length <= 0){
        printf("\n Este valor nao forma um lado de um retangulo");
    }
    else{
        // Altura
        printf("\n Digite a altura do retangulo: ");
        fflush(stdin);
        scanf("%f", &width);

        if(width <= 0){
            printf("\n Este valor nao forma um lado de um retangulo");
        }
        else{
            resul = length * width;
            printf("\n A area do retangulo eh: %.2f", resul);
        }
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
