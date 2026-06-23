#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

void printArray(int array[], int size)
{
    printf("[ ");
    for (int i = 0; i < size; i++)
    {
        printf("%i ", array[i]);
    }
    printf("]\n");
}

void bubbleSort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int *array, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = array[i]; // Guarda o elemento atual a ser inserido
        int j = i - 1;

        // Desloca os elementos maiores que a chave para a direita
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j]; // Move o elemento para frente
            j--;                     // Retrocede o ponteiro esquerdo
        }

        array[j + 1] = key; // Insere a chave na posição correta
    }
}

void selectionSort(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        // Varre o restante do array procurando um valor menor
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[minIndex])
            {
                minIndex = j; // Atualiza o índice do menor elemento encontrado
            }
        }

        // Se encontrou um menor novo, faz uma única troca
        if (minIndex != i)
        {
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
        }
    }
}

void quickSortPartition(int *array, int left, int right, int *i, int *j)
{
    int pivot = array[(left + right) / 2]; // Escolha do pivô central
    *i = left;
    *j = right;

    do
    {
        while (array[*i] < pivot)
        {
            (*i)++; // Avança o ponteiro da esquerda
        }

        while (array[*j] > pivot)
        {
            (*j)--; // Recua o ponteiro da direita
        }

        if (*i <= *j) // Se os ponteiros não se cruzaram, troca os elementos de lado
        {
            int temp = array[*i];
            array[*i] = array[*j];
            array[*j] = temp; //
            (*i)++;
            (*j)--; // Move ambos os ponteiros após a troca
        }
    } while (*i <= *j); // Repete até os ponteiros se cruzarem
}

void quickSortOrder(int *array, int left, int right)
{
    int i, j;
    quickSortPartition(array, left, right, &i, &j); // Particiona o vetor

    if (left < j)
    {
        quickSortOrder(array, left, j); // Ordena a metade esquerda
    }

    if (i < right)
    {
        quickSortOrder(array, i, right); // Ordena a metade direita
    }
}

void quickSort(int *array, int size)
{
    quickSortOrder(array, 0, size - 1);
}

int main()
{
    int numbers[SIZE] = {7, 2, 9, 1, 5, 8, 3, 6};

    printf("Original Array: ");
    printArray(numbers, SIZE);

    bubbleSort(numbers, SIZE);

    // insertionSort(numbers, SIZE);

    // selectionSort(numbers, SIZE);

    // quickSort(numbers, SIZE);

    printf("Sorted Array:   ");
    printArray(numbers, SIZE);

    return 0;
}