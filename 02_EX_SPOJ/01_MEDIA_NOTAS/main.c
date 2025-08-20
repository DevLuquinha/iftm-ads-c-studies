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

Student GetDataStudent()
{
    Student student;

    fflush(stdin);
    gets(student.name);

    fflush(stdin);
    scanf("%i", &student.registry);

    for(int i = 0; i < 3; i++)
    {
        fflush(stdin);
        scanf("%f", &student.grades[i]);
    }    

    return student;
}

int main()
{
    // Quantidade N de estudantes
    int amountS;
    
    // Vetor de estudantes
    Student students[1000];
    
    amountS = GetAmountStudents();

    Student student = GetDataStudent(students[0]);

    printf("\nA quantidade estudantes eh %i", amountS);
    printf("\n1. %s (%i): %f", student.name, student.registry);
    // Pegar as (nome, matricula, n1, n2 e n3) dos N estudantes

    // Imprimir no formato posicao. nome (matricula): media

    return 0;
}