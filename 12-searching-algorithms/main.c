#include <stdio.h>
#include <stdlib.h>

int linearSearch(int *array, int size, int target)
{
    int i = 0;

    while (i < size && array[i] != target)
    {
        i++;
    }

    if (i < size)
    {
        return i;
    }

    return -1; // Not found :(
}

int sentinelSearch(int *array, int size, int target)
{
    int i = 0;
    array[size] = target;

    while (i < size && array[i] != target)
    {
        i++;
    }

    if (i < size)
    {
        return i;
    }

    return -1; // Parou na sentinela :(
}

int binarySearch(int *array, int size, int target)
{
    int leftIndex = 0;
    int rightIndex = size - 1;

    while (leftIndex <= rightIndex)
    {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;

        if (array[middleIndex] == target)
        {
            return middleIndex;
        }

        if (target < array[middleIndex])
        {
            rightIndex = middleIndex - 1;
        }
        else
        {
            leftIndex = middleIndex + 1;
        }
    }

    return -1; // Not found ;(
}

int main()
{
    int unorderedArray[9] = {7, 2, 9, 1, 5, 8, 3, 6, 0};

    int orderedArray[8] = {1, 2, 3, 5, 6, 7, 8, 9};

    int target = 5;
    int resultIndex;

    // 1. Busca Sequencial Tradicional
    resultIndex = linearSearch(unorderedArray, 8, target);
    printf("Linear Search: Element %i found at index: %i\n", target, resultIndex);

    // 2. Busca com Sentinela
    resultIndex = sentinelSearch(unorderedArray, 8, target);
    printf("Sentinel Search: Element %i found at index: %i\n", target, resultIndex);

    // 3. Busca Binária
    resultIndex = binarySearch(orderedArray, 8, target);
    printf("Binary Search: Element %i found at index: %i\n", target, resultIndex);

    return 0;
}