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
        printf("\n            ==============P");
        printf("\n 1-Estatistica com intervalo de numeros");
        printf("\n 2-Estatistica com varios numeros");
        printf("\n 3-Calculo fatorial de um numero");
        printf("\n 4-Finalizar programa");

        do
        {
            fflush(stdin);
            printf("\n Escolha o numero de uma das opcoes acima...: ");
            scanf("%d", &query);
        }while(query < 1 || query > 4);

        if(query == 1)
        {
            system("cls");
            printf("1-) Estatistica com intervalo de numeros\n");
            // Declaração das variaveis opção 1
            float num, qtdInte1, qtdInte4;
            float percentInte2, qtdInte2, qtdInte3, mediaInte3, somaInte3;
            percentInte2 = qtdInte2 = qtdInte3 = mediaInte3 = 0;
            num = qtdInte1 = qtdInte4 = somaInte3 = 0;

            do  // Fazer enquanto for diferente de -1
            {
                do  // Fazer enquanto não for -1 ou estiver no range
                {
                    printf("\nDigite um numero no intervalo de [0-100], caso deseje encerrar digite -1: ");
                    fflush(stdin);
                    scanf("%f", &num);
                    if(num != -1 && (num < 0 || num > 100))
                        printf("\nErro! O numero digitado esta fora do intervalo :(");
                    else if(num >= 0 && num <= 25)
                        qtdInte1++;
                    else if(num >= 26 && num <=  50)
                        qtdInte2++;
                    else if(num >= 51 && num <= 75)
                    {
                        qtdInte3++;
                        somaInte3 += num;
                    }
                    else if(num >= 76 && num <= 100)
                        qtdInte4++;
                }while(num != -1 && (num < 0 || num > 100));
            }while(num != -1);

            printf("\n=================Estatistica com intervalo de numeros=======================");
            // Mostra a letra A
            printf("\nA quantidade de numeros dos intervalos:");
            printf("\nIntervalo 1 [0-25]  : %.0f", qtdInte1);
            printf("\nIntervalo 2 [26-50] : %.0f", qtdInte2);
            printf("\nIntervalo 3 [51-75] : %.0f", qtdInte3);
            printf("\nIntervalo 4 [75-100]: %.0f", qtdInte4);

            // Mostra a letra B
            percentInte2 =  (qtdInte2 / (qtdInte1 + qtdInte2 + qtdInte3 + qtdInte4)) * 100;
            printf("\n\nO percentual de numeros que estao no intervalo 2: %.1f%%", percentInte2);

            // Mostra a letra C
            if(somaInte3 == 0|| qtdInte3 == 0)
                printf("\n\nA media dos numeros que estao no intervalo 3: 0 ");
            else
            {
                mediaInte3 = somaInte3 / qtdInte3;
                printf("\n\nA media dos numeros que estao no intervalo 3: %.2f", mediaInte3);
            }
            printf("\n============================================================================\n");
            // So sai quando clicar ESC
            char teclaUsuario;
            do
            {
                printf("\nDigite a tecla ESC para voltar ao menu: ");
                teclaUsuario = getch();
            }while(teclaUsuario != 27);
            system("cls");
        }
        else if(query == 2)
        {
            system("cls");
            printf("2-) Estatistica com varios numeros\n");

            // Inicializar variaveis para a opção 2
            float num, soma, media, qtdNum;
            float qtdPar, qtdImp, percPar, percImp;
            float maior, menor, maiorPar, menorImp;
            int numInt;
            num = numInt = soma = media = qtdNum = 0;
            qtdPar = qtdImp = percPar = percImp = 0;
            maior = menor = maiorPar = menorImp = 0;

            do
            {
                // Verifica se é positivo
                do
                {
                    printf("\nDigite um numero positivo, para encerrar digite 0: ");
                    fflush(stdin);
                    scanf("%f", &num);
                    if(num < 0)
                        printf("\nErro! Digite apenas numeros inteiros!");
                }while(num < 0);

                // Caso não seja 0
                if(num > 0)
                {
                    soma += num;
                    qtdNum++;
                    numInt = num;

                    // Caso seja o primeiro loop
                    if(qtdNum == 1)
                        maior = menor = num;
                    else
                    {
                        if(num > maior)
                            maior = num;
                        if(num < menor)
                            menor = num;
                    }

                    // Caso ele seja par
                    if(numInt % 2 == 0)
                    {
                        qtdPar++;
                        if(qtdPar == 1)
                            maiorPar = numInt;
                        else
                        {
                            if(numInt > maiorPar)
                                maiorPar = numInt;
                        }
                    }
                    else
                    {
                        qtdImp++;
                        if(qtdImp == 1)
                            menorImp = numInt;
                        else
                        {
                            if(numInt < menorImp)
                                menorImp = numInt;
                        }
                    }
                }
            }while(num > 0);

            // Operações Fora do Laço
            media = soma / qtdNum;
            percPar = (qtdPar / qtdNum) * 100;
            percImp = (qtdImp / qtdNum) * 100;

            // Mostrar Resultado
            printf("\n=====================================================================");
            printf("\nA soma de todos os numeros  informados: %.0f", soma);
            printf("\nA media de todos os numeros informados: %.1f", media);
            printf("\nA quantidade de numeros informados: %.0f", qtdNum);
            printf("\nA quantidade de numeros pares: %.0f", qtdPar);
            printf("\nA quantidade de numeros impares: %.0f", qtdImp);
            printf("\nO percentual de numeros pares e impares: %.2f%% e %.2f%%", percPar, percImp);
            printf("\nO maior e o menor numero informado: %.0f e %.0f", maior, menor);
            printf("\nO maior numero par: %.0f", maiorPar);
            printf("\nO menor numero impar: %.0f", menorImp);
            printf("\n=====================================================================\n");

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
            printf("3-) Calculo fatorial de um numero\n");

            // Declaração das variaveis opção 3
            int num, resul, i;
            resul = i = 0;

            do
            {
               printf("\nDigite um numero que deseje fazer o fatorial: ");
               fflush(stdin);
               scanf("%d", &num);
               if(num < 0)
                printf("\nErro! Nao existe fatorial de numeros negativos.");
            }while(num < 0);

            // Começa no valor digitado
            i = num;
            resul = 1;

            // Faz o calculo do fatorial
            while((i-1) >= 1)
            {
                resul = resul * i;
                i--;
            }

            printf("\nO valor de %d! = %d\n", num, resul);

            // Mostra o estilo do fatorial
            for(num; num >= 1; num--)
            {
                if(num == 1)
                {
                    Sleep(150);
                    printf("%d = ", num);
                }
                else
                {
                    Sleep(150);
                    printf("%d * ", num);
                }
            }

            printf("%d\n", resul);

            // Só sai quando clicar ESC
            char teclaUsuario;
            do
            {
                printf("\nDigite a tecla ESC para voltar ao menu: ");
                teclaUsuario = getch();
            }while(teclaUsuario != 27);
            system("cls");

        }
    }while(query != 4);

    printf("\n FINALIZANDO PROGRAMA...: ");
    for(int f = 0; f <= 20; f++)
    {
        Sleep(100);
        printf("%c", 178);
    }

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
