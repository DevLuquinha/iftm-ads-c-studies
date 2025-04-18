/*===============================================================
    Elaborar um algoritmo que recebe três notas de um aluno, uma de cada
    vez e verificando se é menor que zero ou maior que dez, caso seja, mostrar mensagem
    nota inválida e finalizar o algoritmo. Fazer isso para cada nota durante a entrada.
    Caso contrário, ou seja, as notas estejam entre zero e dez, receber a outra nota e assim
    por diante. No final das três entradas, caso todas as notas seja válidas, calcular a média
    aritmética e mostrar o resultado no vídeo.

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
    float nota1, nota2, nota3, media;

    //INICIALIZAR VARIAVEIS
    nota1, nota2, nota3, media = 0;

    printf("\n Digite a nota 1: ");
    fflush(stdin);
    scanf("%f", &nota1);

    // Verifica se a nota esta fora do range
    if(nota1 <= 0 || nota1 > 10){
        printf("\n Nota invalida, a nota esta fora do limite entao reinicie o programa! ");
        return 0;
    }

    printf("\n Digite a nota 2: ");
    fflush(stdin);
    scanf("%f", &nota2);

    if(nota2 <= 0 || nota2 > 10){
        printf("\n Nota invalida, a nota esta fora do limite entao reinicie o programa! ");
        return 0;
    }

    printf("\n Digite a nota 3: ");
    fflush(stdin);
    scanf("%f", &nota3);

    if(nota3 <= 0 || nota3 > 10){
        printf("\n Nota invalida, a nota esta fora do limite entao reinicie o programa! ");
        return 0;
    }

    media = (nota1 + nota2 + nota3) / 3;

    //FINALIZAR PROGRAMA
    printf("\n A media eh: %.2f", media);
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
