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
    int cdgTran, cdgMoto, cdgForn, cdgViag;
    int qtdForms, qtdNormais, qtdExcedentes;
    float canaKilos, canaTonelada;
    float canaNormal, canaExcedente;
    float totalCanaNormal, totalCanaExcedente, totalCanaTonelada;
    float percentualExcedente, percentualNormal;
    char query;

    //INICIALIZAR VARIAVEIS
    qtdForms = qtdNormais = qtdExcedentes = 0;
    totalCanaNormal = totalCanaExcedente = 0;
    percentualExcedente = percentualNormal = 0;

    do
    {
        // Variaveis que sao 0 a cada laço
        canaKilos = cdgTran = cdgMoto = cdgForn = cdgViag = 0;
        query = ' ';
        canaNormal = canaExcedente = canaTonelada = 0;
        printf("========================AVALIACAO DE TRANSPORTADORES USINA========================");
        // CODIGO TRANSPORTADOR
        printf("\nDigite o codigo do transportador [1-99]: ");
        do
        {
            fflush(stdin);
            scanf("%d", &cdgTran);
            if(cdgTran < 1 || cdgTran > 99)
                printf("\nErro! Digite o codigo no intervalo 1 a 99: ");
        }while(cdgTran < 1 || cdgTran > 99);

        // CODIGO MOTORISTA
        printf("\nDigite o codigo do motorista [1-99]: ");
        do
        {
            fflush(stdin);
            scanf("%d", &cdgMoto);
            if(cdgMoto < 1 || cdgMoto > 99)
                printf("\nErro! Digite o codigo no intervalo 1 a 99: ");
        }while(cdgMoto < 1 || cdgMoto > 99);

        // CODIGO FORNECEDOR
        printf("\nDigite o codigo do fornecedor [1-99]: ");
        do
        {
            fflush(stdin);
            scanf("%d", &cdgForn);
            if(cdgForn < 1 || cdgForn > 99)
                printf("\nErro! Digite o codigo no intervalo 1 a 99: ");
        }while(cdgForn < 1 || cdgForn > 99);

        // CODIGO VIAGEM
        printf("\nDigite o codigo do viagem [1-99]: ");
        do
        {
            fflush(stdin);
            scanf("%d", &cdgViag);
            if(cdgViag < 1 || cdgViag > 99)
                printf("\nErro! Digite o codigo no intervalo 1 a 99: ");
        }while(cdgViag < 1 || cdgViag > 99);

        // QUANTIDADE DE CANA EM KG
        printf("\nInforme a quantidade de cana transportada(kg): ");
        do
        {
            fflush(stdin);
            scanf("%f", &canaKilos);
            if(canaKilos <= 0)
                printf("\nErro! Informe uma quantidade valida!: ");
        }while(canaKilos <= 0);

        canaTonelada += canaKilos / 1000.0;

        // Quantidade de cana normal e excedente
        if(canaTonelada > 20)
        {
            canaExcedente = canaTonelada - 20;
            qtdExcedentes++;
        }
        else
        {
            canaExcedente = 0;
            qtdNormais++;
        }

        canaNormal = canaTonelada - canaExcedente;
        qtdForms++;

        // Quantidade total de cana normal, cana excedente e cana tonelada
        totalCanaNormal += canaNormal;
        totalCanaExcedente += canaExcedente;
        totalCanaTonelada += canaTonelada;

        system("cls");

        // MOSTRAR RELATORIO
        printf("RELATORIO DE VIAGEM (%d):", qtdForms);
        printf("\nCodigo do Transportador: %d", cdgTran);
        printf("\nCodigo do Motorista....: %d", cdgMoto);
        printf("\nCodigo do Fornecedor...: %d", cdgForn);
        printf("\nCodigo da Viagem.......: %d", cdgViag);
        printf("\nQuantidade de Cana Transportada(KG): %.2f Kilos", canaKilos);

        printf("\n\nPara realizar mais um relatorio aperte a tecla ENTER");
        printf("\nCaso deseje finalizar, aperte a tecla ESC: ");
        do
        {
            query = getch();
            if(query != 27 && query != 13)
                printf("\nTecle apenas ENTER ou ESC: ");
        }while(query != 27 && query != 13);

        system("cls");
    }while(query != 27);

    // Percentual de canas excedente
    percentualExcedente = 100 * (totalCanaExcedente / totalCanaTonelada);
    percentualNormal = 100 * (totalCanaNormal / totalCanaTonelada);
    printf("RELATORIO FINAL");
    printf("\nA) Foram transportadas %.2f Toneladas no total.", totalCanaTonelada);
    printf("\nB) %.2f Toneladas normais e %.2f Toneladas excedentes.", totalCanaNormal, totalCanaExcedente);
    printf("\nC) Ocorreram %d viagens no total.", qtdForms);
    printf("\nD) Ocorreram %d viagens normais e %d viagens excedentes.", qtdNormais, qtdExcedentes);
    printf("\nE) %.2f%% de cana excedente.", percentualExcedente);
    printf("\nF) %.2f%% de cana normal.", percentualNormal);

    //FINALIZAR PROGRAMA
    printf ("\n\n\nFIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
