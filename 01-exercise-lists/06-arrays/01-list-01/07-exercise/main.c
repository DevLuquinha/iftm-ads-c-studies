/*===============================================================
<<<<<<< HEAD

    CURSO: ANALISE E DESENVOLVIMENTO DE SISTEMAS - ADS
    1º PERÍODO - DISCIPLINA DE ALGORITMO E LÓGICA DE PROGRAMAÇÃO
=======
    CURSO: ANALISE E DESENVOLVIMENTO DE SISTEMAS - ADS
    1� PER�ODO - DISCIPLINA DE ALGORITMO E L�GICA DE PROGRAMA��O
>>>>>>> 8be56a4d224877ca55979506e8573deef8e94748
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
<<<<<<< HEAD
#define size 3
=======
#define size 2
>>>>>>> 8be56a4d224877ca55979506e8573deef8e94748
//===============================================================
//============== LOCAL PARA DECLARAR OS PROTOTIPOS ==============
//===============================================================

//===============================================================
<<<<<<< HEAD
//============== LOCAL PARA CRIAR OS MÓDULOS DE FUNÇÕES =========
=======
//============== LOCAL PARA CRIAR OS M�DULOS DE FUN��ES =========
>>>>>>> 8be56a4d224877ca55979506e8573deef8e94748
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
    // CRIAR VARIAVEIS
    float score1[size], score2[size], score3[size], score4[size], score;
    float average[size], higherAverage;
    char studentsName[size][100], name[100];
    int i, higherPosition;

    // INICIALIZAR VETORES
    for(i = 0; i < size; i++)
    {
        score1[i] = 0;
        score2[i] = 0;
        score3[i] = 0;
        score4[i] = 0;
        average[i] = 0;
        strcpy(studentsName[i], "");
    }

    // Recebe os nomes e as notas
    for(i = 0; i < size; i++)
    {
        printf("CALCULAR MEDIA ALUNOS");
        do
        {
            strcpy(name, "");
            printf("\nDigite o nome do aluno %d: ", i + 1);
            fflush(stdin);
            gets(name);
        }while(strcmp(name, "") == 0);

        strcpy(studentsName[i], name);

        // Nota 1
        do
        {
            score = 0;
            printf("\nNota 1 de %s [0-10]: ", name);
            fflush(stdin);
            scanf("%f", &score);
        }while(score < 0 || score > 10);

        score1[i] = score;

        // Nota 2
        do
        {
            score = 0;
            printf("\nNota 2 de %s [0-10]: ", name);
            fflush(stdin);
            scanf("%f", &score);
        }while(score < 0 || score > 10);

        score2[i] = score;

        // Nota 3
        do
        {
            score = 0;
            printf("\nNota 3 de %s [0-10]: ", name);
            fflush(stdin);
            scanf("%f", &score);
        }while(score < 0 || score > 10);

        score3[i] = score;

        // Nota 4
        do
        {
            score = 0;
            printf("\nNota 4 de %s [0-10]: ", name);
            fflush(stdin);
            scanf("%f", &score);
        }while(score < 0 || score > 10);

        score4[i] = score;

        system("cls");
    }

    // Limpar as variaveis
    higherPosition = 0;
    higherAverage  = 0;

    // Atribuir valores para o vetor de media e encontrar quem tem a maior media
    for(i = 0; i < size; i++)
    {
        average[i] = (score1[i] + score2[i] + score3[i] + score4[i]) / 4.0;
        if(i == 0)
        {
            higherAverage = average[0];
        }
        else
        {
            if(average[i] >= higherAverage)
            {
                higherAverage = average[i];
                higherPosition = i;
            }
        }
    }

    printf("=============MEDIA DOS ALUNOS===============");
    for(i = 0; i < size; i++)
    {
        printf("\nO Aluno %s tem as notas: ", studentsName[i]);
        printf("\nNota 1: %.2f", score1[i]);
        printf("\nNota 2: %.2f", score2[i]);
        printf("\nNota 3: %.2f", score3[i]);
        printf("\nNota 4: %.2f", score4[i]);
        printf("\nA media de %s foi de %.2f", studentsName[i], average[i]);
        printf("\n============================================");
    }

    printf("\nQuem tirou a maior media foi %s, com o valor de %.2f", studentsName[higherPosition], average[higherPosition]);
    // FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
