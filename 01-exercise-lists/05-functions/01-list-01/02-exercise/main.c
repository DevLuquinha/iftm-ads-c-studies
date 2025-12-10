/*===============================================================
    CURSO: ANALISE E DESENVOLVIMENTO DE SISTEMAS - ADS
    1º PERÍODO - DISCIPLINA DE ALGORITMO E LÓGICA DE PROGRAMAÇÃO
    Nome do aluno(a): Lucas Emmanuel Rodrigues Firmino de Paula
    1 SEMESTRE 2025
    Prof. Ernani Claudio Borges
    data: Maio 2025

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
#include <conio.h>
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================

//===============================================================
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
//===============================================================
int GetNumber(char msg[500])
{
    int num = 0;

    do // Enquanto for negativo
    {
        if(num < 0)
            system("cls");
        printf("%s", msg);  // Printa a mensagem escrita no param
        fflush(stdin);
        scanf("%d", &num);
    }while(num < 0);

    return num;
}
//===============================================================
int TransformToSecond(int hour, int minutes, int seconds)
{
    return (hour * 3600) + (minutes * 60) + seconds;
}
//===============================================================

//===============================================================

//===============================================================

//===============================================================
//==============  CODIGO PRINCIPAL ==============================
//===============================================================
int main()
{
    // CRIAR VARIAVEIS
    int numH = 0;
    int numM = 0;
    int numS = 0;
    int secTot = 0;

    // PEGA OS INPUTS DO USUÁRIO
    numH = GetNumber("Digite a quantidade de HORAS: ");
    numM = GetNumber("Digite a quantidade de MINUTOS: ");
    numS = GetNumber("Digite a quantidade de SEGUNDOS: ");

    // REALIZA A TRANFORMAÇÃO
    secTot = TransformToSecond(numH, numM, numS);
    // FINALIZAR PROGRAMA
    printf("%d Horas, %d Minutos, %d Segundos = %d segundos :)", numH, numM, numS, secTot);
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");
    return 0;
}
