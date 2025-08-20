#include <stdio.h>
#include <string.h>

struct student
{
    char name[50];
    int registry;
    float grades[3];    
};
typedef struct student Student;

int GetAmountStudents()
{
    int q;
    fflush(stdin);
    scanf("%i", &q);

    return q;
}

int main()
{
    int amountS;
    // Vetor de estudantes

    // Quantidade N de estudantes
    amountS = GetAmountStudents();

    printf("\nA quantidade estudantes eh %i", amountS);
    // Pegar as (nome, matricula, n1, n2 e n3) dos N estudantes

    // Imprimir no formato posicao. nome (matricula): media

    return 0;
}