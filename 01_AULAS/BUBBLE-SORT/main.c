#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void SortByAlph(char vecNames[][20], int vecLen)
{
    char aux[20];

    // Repetir o vecLen vezes
    for(int i = 0; i < 5; i++)
    {
        for (int j = i; j < vecLen - 1; j++)
        {
            if (strcmp(vecNames[i], vecNames[j+1]) > 0)
            {
                strcpy(aux, vecNames[j+1]);
                strcpy(vecNames[j+1], vecNames[i]);
                strcpy(vecNames[i], aux);
            }
        }
    }
}

void ShowVector(char vecNames[][20], int vecLen)
{
    for(int i = 0; i < vecLen; i++)
    {
        printf("%s\n", vecNames[i]);
    }
}

int main()
{
    char names[5][20] = {"Charlie", "Bob", "Alice", "Eve", "Diana"};
    
    printf("================ NOMES ================\n");
    ShowVector(names, 5);

    SortByAlph(names, 5);

    printf("================ NOMES ORDENADOS ================\n");
    ShowVector(names, 5);

    return 0;
}