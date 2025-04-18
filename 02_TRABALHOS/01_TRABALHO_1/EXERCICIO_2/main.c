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
    char nome1[50], nome2[50], nome3[50], nome4[50];
    char query, vencedor[50];
    int voto;
    int candidatoVencedor;
    int totalNome1, totalNome2, totalNome3, totalNome4;
    int totalNulo, totalBranco;
    float percentual, totalVotos;

    //INICIALIZAR VARIAVEIS
    strcpy(nome1, "");
    strcpy(nome2, "");
    strcpy(nome3, "");
    strcpy(nome4, "");
    strcpy(vencedor, "");
    voto = candidatoVencedor = 0;
    totalNome1 = totalNome2 = totalNome3 = totalNome4 = 0;
    totalNulo = totalBranco = 0;
    percentual = 0;

    // BOAS VINDAS PARA O USUARIO
    printf("\n==================ELEICAO DE REPRESENTANTE(S)==================");
    printf("\nBem-vindo a eleicao de representantes da turma de graduacao!");

    // RECEBE OS NOMES DOS CANDIDATOS
    printf("\nDigite o nome do candidato 1: ");
    gets(nome1);

    printf("Digite o nome do candidato 2: ");
    gets(nome2);

    printf("Digite o nome do candidato 3: ");
    gets(nome3);

    printf("Digite o nome do candidato 4: ");
    gets(nome4);

    system("cls");

    // EXIBE OS DADOS PARA VOTACAO
    printf("DADOS PARA VOTACAO");
    printf("\n========================================");
    printf("\n(1) => %s", nome1);
    printf("\n(2) => %s", nome2);
    printf("\n(3) => %s", nome3);
    printf("\n(4) => %s", nome4);
    printf("\n(5) => VOTO NULO");
    printf("\n(6) => VOTO EM BRANCO");
    printf("\n(0) => ENCERRAR VOTACAO");
    printf("\n========================================");

    do
    {
        // RECEBE O VOTO
        do
        {
            printf("\nInforme o seu voto (0, 1, 2, 3, 4, 5, 6): ");
            fflush(stdin);
            scanf("%d", &voto);
            if(voto < 0 || voto > 6)
                printf("\nErro! Informe APENAS os numeros que estao no intervalo. VOTO NAO CONTABILIZADO!");
        }while(voto < 0 || voto > 6);

        // Caso o usuario nao queira encerrar
        if(voto != 0)
        {
            if(voto == 1)
                totalNome1++;
            else if(voto == 2)
                totalNome2++;
            else if(voto == 3)
                totalNome3++;
            else if(voto == 4)
                totalNome4++;
            else if(voto == 5)
                totalNulo++;
            else if(voto == 6)
                totalBranco++;

            if(totalVotos == 0)
            {
                candidatoVencedor = totalNome1 = totalNome2 = totalNome3 = totalNome4;
            }
            else
            {
                // VERIFICAR QUEM EH O VENCEDOR
                if(totalNome1 > candidatoVencedor)
                {
                    candidatoVencedor = totalNome1;
                    strcpy(vencedor, nome1);
                }
                if(totalNome2 > candidatoVencedor)
                {
                    candidatoVencedor = totalNome2;
                    strcpy(vencedor, nome2);
                }
                if(totalNome3 > candidatoVencedor)
                {
                    candidatoVencedor = totalNome3;
                    strcpy(vencedor, nome3);
                }
                if(totalNome4 > candidatoVencedor)
                {
                    candidatoVencedor = totalNome4;
                    strcpy(vencedor, nome4);
                }
            }
            totalVotos++;
        }
    }while(voto != 0);

    percentual = 100 * ((totalBranco + totalNulo) / totalVotos);

    // MOSTRAR QUANTIDADE DE VOTOS CANDIDATOS
    printf("\nQUANTIDADE DE VOTOS");
    printf("\n===================================");
    printf("\n(1)%s possui %d votos", nome1, totalNome1);
    printf("\n(2)%s possui %d votos", nome2, totalNome2);
    printf("\n(3)%s possui %d votos", nome3, totalNome3);
    printf("\n(4)%s possui %d votos", nome4, totalNome4);
    printf("\n===================================");

    // MOSTRAR QUANTIDADE DE NULOS E BRANCOS
    printf("\nTOTAL DE NULOS:   %d", totalNulo);
    printf("\nTOTAL DE BRANCOS: %d", totalBranco);
    printf("\n===================================");

    // MOSTRAR PERCENTUAL DE NULOS E BRANCOS
    printf("\nPERCENTUAL NULOS E BRANCOS: %.1f%%", percentual);
    printf("\n===================================");

    // MOSTRAR CANDIDATO VENCEDOR
    printf("\nDESEJA SABER O CANDIDATO VENCEDOR?");
    printf("\nSe sim, aperte a tecla ENTER: ");
    do
    {
        query = getch();
        if(query != 13)
            printf("\nNao de uma de espertinho, eu programei esse trem direito, aperte ENTER para finalizar! ");
    }while(query != 13);

    system("cls");

    printf("O CANDIDATO(S) VENCEDOR(ES) EM: ");
    for(int i = 5; i >= 1; i--)
    {
        if(i == 1)
        {
            Sleep(800);
            printf("%d...: ", i);
        }
        else
        {
            Sleep(800);
            printf("%d ", i);
        }
    }

    if(candidatoVencedor == 0)
    {
        printf("\nINFELIZMENTE NINGUEM GANHOU :(");
    }
    else
    {
        if(candidatoVencedor == totalNome1)
            printf("\n%s", nome1);
        if(candidatoVencedor == totalNome2)
            printf("\n%s", nome2);
        if(candidatoVencedor == totalNome3)
            printf("\n%s", nome3);
        if(candidatoVencedor == totalNome4)
            printf("\n%s", nome4);
    }


    //FINALIZAR PROGRAMA
    printf ("\n\n\nFIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
