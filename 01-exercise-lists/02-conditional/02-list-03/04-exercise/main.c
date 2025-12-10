/*===============================================================
    Receber quatro notas de um aluno (verificar durante a entrada de cada valor,
    ou seja, só receber a próxima entrada se a anterior atender os requisitos. senão, cancelar o
    processamento quando a nota for inferior a 0 ou superior a 10).
    CASO, todas as entradas atendam as especificações, calcular a média, verificar e apresentar
    uma das mensagens a seguir: “APROVADO” para média superior ou igual a 6,0;
    “RECUPERAÇÃO” para média inferior a 6 e maior ou igual a 4 e “REPROVADO” para média
    inferior a 4.

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
    float n1, n2, n3, n4, media;

    //INICIALIZAR VARIAVEIS
    n1 = n2 = n3 = n4 = media = 0;

    // Nota 1
    printf("\n Digite a nota da primeira prova (0-10): ");
    fflush(stdin);
    scanf("%f", &n1);

    if(n1 < 0 || n1 > 10){
        printf("\n O numero esta fora do intervalo da nota (0-10)");
    }
    else{
        // Nota 2
        printf("\n Digite a nota da sugunda prova (0-10): ");
        fflush(stdin);
        scanf("%f", &n2);
        if(n2 < 0 || n2 > 10){
            printf("\n O numero esta fora do intervalo da nota (0-10)");
        }
        else{
            // Nota 3
            printf("\n Digite a nota da terceira prova (0-10): ");
            fflush(stdin);
            scanf("%f", &n3);
            if(n3 < 0 || n3 > 10){
                printf("\n O numero esta fora do intervalo da nota (0-10)");
            }
            else{
                // Nota 4
                printf("\n Digite a nota da quarta prova (0-10): ");
                fflush(stdin);
                scanf("%f", &n4);
                if(n4 < 0 || n4 > 10){
                    printf("\n O numero esta fora do intervalo da nota (0-10)");
                }
                else{
                    media = (n1 + n2 + n3 + n4) / 4.0;
                    printf("\n A media das notas (%.1f, %.1f, %.1f, %.1f) eh igual a %.2f", n1, n2, n3, n4, media);
                }
            }
        }
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
