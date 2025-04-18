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
    float canaKilos, canaTonelada;
    float canaNormal, canaExcedente;

    //INICIALIZAR VARIAVEIS
    cdgTran = cdgMoto = cdgForn = cdgViag = 0;
    canaKilos = canaTonelada = 0;
    canaNormal = canaExcedente = 0;

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

    if(canaTonelada > 20)
        canaExcedente = canaTonelada - 20;
    else
        canaExcedente = 0;

    canaNormal = canaTonelada - canaExcedente;
    // MOSTRAR RELATORIO
    printf("\nRELATORIO:");
    printf("\nForam transporatadas %.2f Toneladas no total.", canaTonelada);
    printf("\n%.2f Toneladas normais e %.2f Toneladas excedentes.", canaNormal, canaExcedente);

    //FINALIZAR PROGRAMA
    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
