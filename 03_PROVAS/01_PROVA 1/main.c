#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include <math.h>
#include <conio.h>

// NOME: Lucas Emmanuel Rodrigues Firmino de Paula
// CURSO: Analise e Desenvolvimento de Sistemas
// CPF: 704.681.836-39
// DATA: 23/04/2025

int main()
{
    // Declaração das variaveis
    int query;
    query = 0;

    // Laço até ser 4
    do
    {
        printf("           MENU PRINCIPAL\n");
        printf("\n1) Fatoracao de um numero inteiro");
        printf("\n2) Pesquisa de filme no cinema");
        printf("\n3) Companhia de teatro");
        printf("\n4) Finalizar Algoritmo");

        // Laço até estar no intervalo de 1-4
        do
        {
            printf("\nInforme uma das opcoes (1, 2, 3 ou 4)...: ");
            fflush(stdin);
            scanf("%d", &query);
            if(query < 1 || query > 4)
                printf("\nErro! O numero digitado nao faz parte das opcoes do menu!");
        }while(query < 1 || query > 4);
        if(query == 1)
        {
            system("cls");

            // Variavel para voltar o menu
            char voltarMenu;
            voltarMenu = ' ';

            // Declaração das variaveis
            float numFloa;
            int num, i;

            // Inicialização
            numFloa = num = 0;
            i = 2;  // Primeiro numero primo :)

            printf("Fatoracao de um numero inteiro");
            do  // Laço até o num ser positivo e inteiro
            {
                printf("\nDigite um numero inteiro: ");
                fflush(stdin);
                scanf("%f", &numFloa);

                num = numFloa;
                if(num != numFloa || num <= 0)
                    printf("\nERRO! DIGITE APENAS NUMEROS INTEIROS E POSITIVOS");
            }while(num != numFloa || num <= 0);

            if(num == 1)
            {
                printf("\nA fatoracao de 1 eh igual a 1. Quando vc voltar aqui, digite um numero maior :)");
            }
            else
            {
               while(num > 1)
                {
                    if(num % i == 0)
                    {
                        printf("\n%d | %i", num, i);
                        num = num / i;
                    }
                    else
                    {
                       i++;
                    }
                    if(num == 1)
                        printf("\n1");
                }
            }

            printf("\n\nAperte qualquer tecla para voltar ao menu! ");
            getch();
            system("cls");
        }
        else if(query == 2)
        {
            system("cls");

            // Variavel para voltar o menu
            char voltarMenu;
            voltarMenu = ' ';

            // Declaração das variaveis
            float idade, somaIdade, media;
            float totEsp;
            float qtdA, qtdB, qtdC, qtdD, qtdE;
            char nota, fimPesquisa;

            // Inicialização das variaveis
            idade = somaIdade = media = 0;
            totEsp = qtdA = qtdB = qtdC = qtdD = qtdE = 0;

            nota = ' ';
            fimPesquisa = ' ';

            do
            {
                printf("Pesquisa de filme no cinema");
                printf("\n-------------------------");
                printf("\nNOTA | SIGNIFICADO");
                printf("\n-------------------------");
                printf("\n  A  | Otimo");
                printf("\n  B  | Bom");
                printf("\n  C  | Regular");
                printf("\n  D  | Ruim");
                printf("\n  E  | Pessimo");
                printf("\n-------------------------\n");

                do
                {
                    printf("\nDigite a sua idade: ");
                    fflush(stdin);
                    scanf("%f", &idade);
                }while(idade < 1);

                // Para o calculo da media
                somaIdade += idade;

                printf("\nAgora, digite a sua nota (A, B, C, D, E): ");
                do  // Laço até ele digitar uma das letras
                {
                    fflush(stdin);
                    scanf("%c", &nota);
                    if(nota != 'A' && nota != 'a' &&
                       nota != 'B' && nota != 'b' &&
                       nota != 'C' && nota != 'c' &&
                       nota != 'D' && nota != 'd' &&
                       nota != 'E' && nota != 'e')
                       {
                           printf("\nERRO! Digite apenas (A, B, C, D ou E): ");
                       }
                }while(nota != 'A' && nota != 'a' &&
                       nota != 'B' && nota != 'b' &&
                       nota != 'C' && nota != 'c' &&
                       nota != 'D' && nota != 'd' &&
                       nota != 'E' && nota != 'e');

                // Mais um espectador respondeu
                totEsp++;

                // Quantidade de cada elemento
                if(nota == 'a' || nota == 'A')
                    qtdA++;
                else if(nota == 'b' || nota == 'B')
                    qtdB++;
                else if(nota == 'c' || nota == 'C')
                    qtdC++;
                else if(nota == 'd' || nota == 'D')
                    qtdD++;
                else if(nota == 'e' || nota == 'E')
                    qtdE++;

                printf("\nAperte qualquer tecla para reiniciar, para finalizar tecle ESC ");
                fimPesquisa = getch();
                system("cls");
            }while(fimPesquisa != 27);

            // Media dos espectadores
            media = somaIdade / totEsp;

            printf("Finalizando pesquisa em: ");

            for(int i = 3; i >= 1; i--)
            {
                Sleep(500);
                printf("%d ", i);
            }

            printf("\n\na)Total de espectadores que responderam: %.0f", totEsp);
            printf("\nb)Quantidade de notas:");
            printf("\n  A: %.0f", qtdA);
            printf("\n  B: %.0f", qtdB);
            printf("\n  C: %.0f", qtdC);
            printf("\n  D: %.0f", qtdD);
            printf("\n  E: %.0f", qtdE);
            printf("\nc)Percentual de cada resposta em relacao aos espectadores:");
            printf("\n  A: %.2f%%", (qtdA / totEsp) * 100);
            printf("\n  B: %.2f%%", (qtdB / totEsp) * 100);
            printf("\n  C: %.2f%%", (qtdC / totEsp) * 100);
            printf("\n  D: %.2f%%", (qtdD / totEsp) * 100);
            printf("\n  E: %.2f%%", (qtdE / totEsp) * 100);
            printf("\nD)Media de idade dos espectadores: %.2f", media);

            printf("\n\nAperte qualquer tecla para voltar ao menu! ");
            getch();
            system("cls");
        }
        else if(query == 3)
        {
            system("cls");

            // Variavel para voltar o menu
            char voltarMenu;
            voltarMenu = ' ';

            printf("Calculo de companhia de teatro");

            // Declaração de variaveis
            float precoIngresso, qtdIngressos;
            float despesas;
            float lucro;

            float lucroMax, preco, numIng;

            // Inicializar null
            lucro = 0;
            lucroMax = preco = numIng = 0;
            // Valores definidos enunciado
            precoIngresso = 5;
            qtdIngressos = 120;
            despesas = 200;

            printf("\nPRECO INGRESSO | INGRESSOS VENDIDOS | LUCRO ESPERADO");
            printf("\n----------------------------------------------------");

            while(precoIngresso >= 1)
            {
                lucro = (precoIngresso * qtdIngressos) - despesas;
                printf("\nR$%.1f          | %.0f                | R$%.1f", precoIngresso, qtdIngressos, lucro);

                if(precoIngresso == 5)
                {
                    lucroMax = lucro;
                    preco = precoIngresso;
                    numIng = qtdIngressos;
                }
                else
                {
                    if(lucro >= lucroMax)
                    {
                        lucroMax = lucro;
                        preco = precoIngresso;
                        numIng = qtdIngressos;
                    }
                }

                precoIngresso -= 0.5;
                qtdIngressos += 26;
            }

            printf("\n\nO lucro maximo esperado: %.1f. Preco: R$%.1f. Numero de ingressos: %.0f", lucroMax, preco, numIng);

            printf("\n\nAperte qualquer tecla para voltar ao menu! ");
            getch();
            system("cls");
        }
    }while(query != 4);

    printf("\nFinalizando o programa:");
    for(int i = 1; i <= 20; i++)
    {
        Sleep(25);
        printf("*");
    }
    printf("\n\nACABEI A PROVAAAAA, TCHAU BRIGADO!");

    return 0;
}
