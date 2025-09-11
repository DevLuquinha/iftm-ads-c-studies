#include <stdio.h>
#include <stdlib.h>

void SortByAlph(char vecNames[][20], int vecLen)
{
    for(int i = 0; i < vecLen; i++)
    {
        printf("%s\n", vecNames[i]);
    }
}

int main()
{
    char names[5][20] = {"Alice", "Bob", "Charlie", "Diana", "Eve"};
    SortByAlph(names, 5);

    return 0;
}