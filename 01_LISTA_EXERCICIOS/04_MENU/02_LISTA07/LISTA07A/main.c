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
    int query;

    //INICIALIZAR VARIAVEIS


    // Verificação se for 4
    do
    {
        query = 0;
        printf("\n            MENU DE OPCOES");
        printf("\n            ===============");
        printf("\n 1-) Sequencia com variacao de sinal duplicado");
        printf("\n 2-) Sequencia de numero por linhas");
        printf("\n 3-) SAIR");

        do
        {
            fflush(stdin);
            printf("\n Escolha o numero de uma das opcoes acima...: ");
            scanf("%d", &query);
        }while(query < 1 || query > 3);

        if(query == 1)
        {
            system("cls");
            printf("1-) Sequencia com variacao de sinal duplicado\n");
            float soma, poten;
            int exp, base, qtd, sinal;

            soma = exp = qtd = poten = sinal = 0;

            do
            {
                printf("\nDigite a quantidade de termos: ");
                fflush(stdin);
                scanf("%d", &qtd);
            }while(qtd <= 0);


            for(int i = 1; i <= qtd; i++)
            {
                if(i == 1)
                    exp = base = sinal = 1;
                else
                {
                    exp += 2;
                    base = base * 3;

                    if(i == 2)
                       sinal = -1;
                    else if(i % 2 == 0) // Caso vire positivo, inverte
                        sinal = sinal * -1;
                }
                // Calcula a potência de cima, 2^3, 3^5, 4^7.
                for(int j = exp; j >= 1; j--)// Variavel j é quantidade de vezes que ira rodar, ex: 3, 2, 1. OU 5, 4, 3, 2, 1.
                {
                    if(j == exp) // Se for a primeira passagem
                        poten = i;
                    else
                        poten = poten * i;
                }

                if(sinal == 1)
                {
                    soma = soma + (poten / base);
                }
                else if(sinal == -1 && i == 2)
                {
                    soma = soma + (poten / base);
                }
                else if(sinal == -1)
                {
                    soma = soma - (poten / base);
                }
            }
            printf("\nO resultado S: %.2f", soma);

            // So sai quando clicar ESC
            char teclaUsuario;
            do
            {
                printf("\n\nDigite a tecla ESC para voltar ao menu: ");
                teclaUsuario = getch();
            }while(teclaUsuario != 27);
            system("cls");
        }
        else if(query == 2)
        {
            system("cls");
            printf("2-) Sequencia de numero por linhas\n");
            int qtdLinhas, colunas;
            qtdLinhas = colunas = 0;

            // Verificação se vai digitar menor que 0
            do
            {
                printf("\nDigite a quantidade de linhas: ");
                fflush(stdin);
                scanf("%d", &qtdLinhas);
            }while(qtdLinhas <= 0);

            printf("\n============================\n");

            // Quantidade de linhas, ex: 1, 2, 3, 4, 5.
            for(int linha = 1; linha <= qtdLinhas; linha++)
            {
                colunas = 1;    // Coluna sempre começa com 1
                while(colunas <= linha)
                {
                    Sleep(100);
                    printf("%d ", linha * colunas); // 1*1 | 2*1, 2*2 | 3*1, 3*2, 3*3 | 4*1, 4*2, 4*3, 4*4
                    colunas++;
                }
                Sleep(100);
                printf("\n"); // Caso a qtd de colunas seja a mesma que a de linhas
            }
            printf("============================\n");
            // So sai quando clicar ESC
            char teclaUsuario;
            do
            {
                printf("\nDigite a tecla ESC para voltar ao menu: ");
                teclaUsuario = getch();
            }while(teclaUsuario != 27);
            system("cls");
        }
    }while(query != 3);

    Sleep(50);
    printf("\n Finalizando programa...:");
    for(int fim = 1; fim <= 22; fim++)
    {
        Sleep(50);
        printf("%c", 178);
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
