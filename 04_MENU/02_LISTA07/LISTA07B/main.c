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
        printf("\n 1-) Numero perfeito");
        printf("\n 2-) Orcamento vidracaria");
        printf("\n 3-) Sequencia com variacao de sinal");
        printf("\n 4-) Numeros divisiveis por 4");
        printf("\n 5-) SAIR");

        do
        {
            fflush(stdin);
            printf("\n Escolha o numero de uma das opcoes acima...: ");
            scanf("%d", &query);
        }while(query < 1 || query > 5);

        if(query == 1)
        {
            system("cls");
            printf("1-) Numero perfeito\n");

            int nLimite, somaN;
            nLimite = somaN = 0;

            // Recebe valor do numero limite
            printf("\nDigite um numero [N] limite para analisar os numeros perfeitos entre [2-N]: ");
            do
            {
                fflush(stdin);
                scanf("%d", &nLimite);
                if(nLimite <= 2)
                    printf("\nErro! Digite um numero (N) maior que 2:");
            }while(nLimite <= 2);

            printf("\n Os numeros perfeitos entre [2-%d]: \n", nLimite);

            // num é cada numero até o limite
            for(int num = 3; num <= nLimite; num++)
            {
                somaN = 1;

                // Se for positivo
                if(num % 2 == 0)
                    somaN += 2;

                // i é cada numero até o numero do limite
                // ex: num = 8 então i = 3, 4, 5, 6, 7
                for(int i = 3; i < num; i++)
                {
                    if(num % i == 0)    // Se ele for multiplo, ira somar ele
                        somaN += i;
                }
                if(somaN == num)    // Caso a soma seja igual ao numero, ele é perfeito
                    printf("%d, ", num);
            }

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
            printf("2-) Orcamento vidracaria\n");

            int largUsua, compUsua;
            int larg5, comp5;
            largUsua = compUsua = 0;
            larg5 = comp5 = 0;

            // Atribui largura usuario
            do
            {
                printf("\nDigite a largura do vidro: ");
                fflush(stdin);
                scanf("%d", &largUsua);
            }while(largUsua <= 0);

            // Atribui comprimento usuario
            do
            {
                printf("\nDigite o comprimento do vidro: ");
                fflush(stdin);
                scanf("%d", &compUsua);
            }while(compUsua <= 0);



            printf("O vidro tem comp x largura: %d x %d", compUsua, largUsua);

            // So sai quando clicar ESC
            char teclaUsuario;
            do
            {
                printf("\nDigite a tecla ESC para voltar ao menu: ");
                teclaUsuario = getch();
            }while(teclaUsuario != 27);
            system("cls");
        }
        else if(query == 3)
        {
            system("cls");
            printf("3-) Sequencia com variacao de sinal\n");

            // So sai quando clicar ESC
            char teclaUsuario;
            do
            {
                printf("\nDigite a tecla ESC para voltar ao menu: ");
                teclaUsuario = getch();
            }while(teclaUsuario != 27);
            system("cls");
        }
        else if(query == 4)
        {
            system("cls");
            printf("4-) Numeros divisiveis por 4\n");

            // So sai quando clicar ESC
            char teclaUsuario;
            do
            {
                printf("\nDigite a tecla ESC para voltar ao menu: ");
                teclaUsuario = getch();
            }while(teclaUsuario != 27);
            system("cls");
        }
    }while(query != 5);

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
