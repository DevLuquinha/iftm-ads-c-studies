/*===============================================================
    Receber o sexo e altura de uma pessoa, sendo << m>> para o sexo masculino
    ou << f >> para o sexo feminino, caso inválido finalizar o programa, senão fazer o cálculo do
    peso ideal através da fórmula:


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
    char sexo;
    float altura, peso;

    //INICIALIZAR VARIAVEIS
    sexo = ' ';
    altura = peso = 0;

    printf("\nDigite o sexo: \n<<m>> Masculino \n<<f>> Feminino \n");
    fflush(stdin);
    scanf("%c", &sexo);

    if(sexo != 'm' && sexo != 'f' && sexo != 'M' && sexo != 'F')
        printf("\n Erro! Sexo digitado invalido, reinicie o programa! ");
    else{
        printf("\nDigite a sua altura: ");
        fflush(stdin);
        scanf("%f", &altura);

        if(sexo == 'm' || sexo == 'M')
            peso = (72.7 * altura) - 58;
        else
            peso = (62.1 * altura) - 44.77;

        printf("\n O seu peso ideal eh: %.2f", peso);
    }
    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA, VALEUUUU :) \n\n\n");

    return 0;
}
