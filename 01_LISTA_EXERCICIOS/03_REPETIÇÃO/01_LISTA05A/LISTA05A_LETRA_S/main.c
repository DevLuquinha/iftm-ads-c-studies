/*===============================================================
    S-) 2 , 8 , 4 , 16 , 8 , 32 , 16 , 64 ,32 , ... , N

    CURSO: ANALISE E DESENVOLVIMENTO DE SISTEMAS - ADS
    1º PERÍODO - DISCIPLINA DE ALGORITMO E LÓGICA DE PROGRAMAÇÃO
    Nome do aluno(a): Lucas Emmanuel Rodrigues Firmino de Paula
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: Abril 2025

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
    int i, nInt, resul;
    int resEle1, resEle2;
    float n;

    //INICIALIZAR VARIAVEIS
    i = 1;  // Iterador, ex: 1, 2, 3, 4, 5,...
    resul = resEle1 = resEle2 = 0;
    n = nInt= 0;

    printf("\n Digite um numero inteiro e positivo (N): ");
    fflush(stdin);
    scanf("%f", &n);
    nInt = n;

    while(nInt != n || n <= 0)
    {
        if(n <= 0)
            printf("\n Erro! O valor digitado eh menor ou igual a 0.");
        else if(nInt != n)
            printf("\n Erro! O valor digitado nao eh positivo!");
        printf("\n Digite um numero inteiro e positivo (N): ");
        fflush(stdin);
        scanf("%f", &n);
        nInt = n;
    }

    system("cls");

    resEle1 = pow(2, i);        // 2^1, 2^2, 2^3, 2^4,...
    resEle2 = pow(2, i + 2);    // 2^3, 2^4, 2^5, 2^6,...

    while(resul <= nInt)
    {
        Sleep(50);
        printf("%d, %d", resEle1, resEle2);
        i++;    // Adiciona mais 1 no icremento, ex: 1, 2, 3, 4, 5, ...
        resEle1 = pow(2, i);
        resEle2 = pow(2, i + 2);
        resul = resEle2;    // resultado é sempre o maior
        if(resul <= nInt)   // Caso não va sair do laço, adiciona uma virgula
            printf(", ");
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
