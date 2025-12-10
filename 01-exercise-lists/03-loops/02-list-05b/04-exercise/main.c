/*===============================================================


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
    char sexo;
    float qtdMul, qtdHom;
    float mediaMul, mediaHom, altura;

    //INICIALIZAR VARIAVEIS
    sexo = ' ';
    qtdMul = qtdHom = mediaMul = mediaHom = 0;

    while(sexo != 'x' && sexo != 'X')
    {
        altura = 0;

        printf("\nDigite o sexo:\n<<m>> Masculino ou <<f>> Feminino: ");
        fflush(stdin);
        scanf("%c", &sexo);

        while(sexo != 'm' && sexo != 'M' && sexo != 'f' && sexo != 'F' && sexo != 'x' && sexo != 'X')
        {
            printf("\nDigite o sexo:\n<<m>> Masculino ou <<f>> Feminino: ");
            fflush(stdin);
            scanf("%c", &sexo);
        }

        // Caso seja X não perguntar
        if(sexo != 'x' && sexo !='X')
        {
            printf("\nDigite a altura: ");
            fflush(stdin);
            scanf("%f", &altura);

            while(altura <= 0)
            {
                printf("\nDigite a altura: ");
                fflush(stdin);
                scanf("%f", &altura);
            }

            if(sexo == 'm' || sexo == 'M')
            {
                mediaHom += altura;
                qtdHom++;
            }

            if(sexo == 'f' || sexo == 'F')
            {
                mediaMul += altura;
                qtdMul++;
            }
        }
        system("cls");
    }

    mediaHom = mediaHom / qtdHom;
    mediaMul = mediaMul / qtdMul;

    if(qtdHom == 0 || qtdMul == 0)
    {
        if(qtdHom == 0)
            mediaHom = 0;
        if(qtdMul == 0)
            mediaMul = 0;
    }

    //FINALIZAR PROGRAMA
    printf("\n A media de altura masculina: %.2f", mediaHom);
    printf("\n A media de altura feminina:  %.2f", mediaMul);
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
