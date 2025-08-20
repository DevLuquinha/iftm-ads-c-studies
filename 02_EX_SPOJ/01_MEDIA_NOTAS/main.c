#include <stdio.h>
#include <string.h>

struct student
{
    char name[50];
    int registry;
    float grades[3];
    float average;    
};
typedef struct student Student;

int GetAmountStudents()
{
    int q;
    fflush(stdin);
    scanf("%i", &q);

    return q;
}

float AverageStudent(float grades[])
{
    float sum;

    for(int i = 0; i < 3; i++)
    {
        sum += grades[i];
    }

    return sum / 3;
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

    student.average = AverageStudent(student.grades);

    return student;
}

void GetDataStudents(Student students[], int amountStd)
{
    for(int i = 0; i < amountStd; i++)
    {
        students[i] = GetDataStudent();
    }
}

void ShowDataStudent(Student student, int index)
{
    printf("\n%i. %s (%i): %.2f\n", index, student.name, student.registry, student.average);
}

void ShowDataStudents(Student students[], int amountStd)
{
    for(int i = 0; i < amountStd; i++)
    {
        ShowDataStudent(students[i], i + 1);
    }
}

int main()
{
    // Vetor de estudantes
    Student students[1000];

    // Quantidade N de estudantes
    int amountS;
    amountS = GetAmountStudents();    
    
    // Pegar as (nome, matricula, n1, n2 e n3) dos N estudantes
    GetDataStudents(students, amountS);

    // Imprimir no formato posicao. nome (matricula): media
    ShowDataStudents(students, amountS);

    return 0;
}