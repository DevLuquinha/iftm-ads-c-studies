#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#define LEN 24

void InitializeVector(int vec[])
{
    for(int i = 0; i < LEN; i++)
    {
        vec[i] = rand() % 50;
    }
}

void ShowVector(int vec[])
{
    printf("\nTEMPERATURA DAS ULTIMAS 24H");
    printf("\n==================================================================================================");
    printf("\n[");
    for(int i = 0; i < LEN; i++)
    {
        if(i + 1 == LEN)
        {
            printf("%d]", vec[i]);
        }
        else
        {
            printf("%d, ", vec[i]);
        }
    }
    printf("\n==================================================================================================");
}

void AddTemperature(int vec[], int num)
{
    for(int i = 0; i < LEN; i++)
    {
        if(i + 1 == LEN)
        {
            vec[i] = num;
        }
        else
        {
            vec[i] = vec[i+1];
        }
    }
}

int GetNumber()
{
    int num = 0;

    printf("\nDigite o valor da temperatura: ");
    fflush(stdin);
    scanf("%d", &num);

    return num;
}

void ShowAverageTemp(int vec[])
{
    int amount = 0;
    float average = 0.0;
    for(int i = LEN -1; i >= 12; i--)
    {
        amount += vec[i];
    }
    average = amount / 12.0;
    printf("\nMEDIA DE TEMPERATURA DAS ULTIMAS 12 HORAS: %.2f", average);
}

void ShowMaxTemperature(int vec[])
{
    int max, pos = 0;

    for(int i = 0; i < LEN; i++)
    {
        if(i == 0)
        {
            max = vec[i];
            pos = i;
        }
        else
        {
            if(vec[i] > max)
            {
                max = vec[i];
                pos = i;
            }
        }
    }

    printf("\nA MAIOR TEMPERATURA FOI: %d, ENCONTRA-SE EM VEC[%d]", max, pos);
}

int main()
{
    int temperatureVector[LEN];
    int num = 0;

    // Inicializar o vetor
    InitializeVector(temperatureVector);

    // Mostrar vetor Inicial
    ShowVector(temperatureVector);

    do
    {
        num = GetNumber();
        if(num >= 0)
        {
            AddTemperature(temperatureVector, num);
        }
    }while(num >= 0);

    // Mostra o vetor novamente
    ShowVector(temperatureVector);

    // Mostrar Média das Ultimas 12 horas
    ShowAverageTemp(temperatureVector);

    // Exibir a maior temperatura
    ShowMaxTemperature(temperatureVector);

    printf ("\n\n\n FIM DO PROGRAMA - VAI EMBORA DAQUI :/ \n\n\n");

    return 0;
}
