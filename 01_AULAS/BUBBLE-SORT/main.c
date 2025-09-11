#include <stdio.h>
#include <stdlib.h>

void SortByAlph(char vecNames[][20], int vecLen)
{
    int vec[5] = {3, 1, 8, 2, 5};
    int aux;

    // Repetir o vecLen vezes
    for(int i = 0; i < 5; i++)
    {
        for (int j = i; j < vecLen - 1; j++)
        {
            if (vec[i] < vec[j+1])
            {
                aux = vec[j+1];
                vec[j+1] = vec[i];
                vec[i] = aux;
            }
        }
    }

    for(int i = 0; i < 5; i++)
    {
        printf("%i, ", vec[i]);
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
    char names[5][20] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
    
    // printf("================ NOMES ================\n");
    // ShowVector(names, 5);

    SortByAlph(names, 5);

    // printf("================ NOMES ORDENADOS ================\n");
    // ShowVector(names, 5);

    return 0;
}