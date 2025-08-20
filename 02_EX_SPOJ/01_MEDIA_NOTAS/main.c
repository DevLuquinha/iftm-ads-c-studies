#include <stdio.h>
#include <string.h>
#define lenGrades 3

struct student
{
    char name[50];
    int registry;
    float grades[lenGrades];
    float average;    
};
typedef struct student Student;

// Protótipos
int GetAmountStudents();
float AverageStudent(float grades[]);
Student GetDataStudent();
void GetDataStudents(Student students[], int amountStd);
void ShowDataStudent(Student student, int index);
void ShowDataStudents(Student students[], int amountStd);

int GetAmountStudents()
{
    int q;
    scanf("%i", &q);

    return q;
}

float AverageStudent(float grades[])
{
    float sum;

    for(int i = 0; i < lenGrades; i++)
    {
        sum += grades[i];
    }

    return sum / lenGrades;
}

Student GetDataStudent()
{
    Student student;

    getchar();
    scanf("%s", student.name);

    getchar();
    scanf("%i", &student.registry);

    for(int i = 0; i < lenGrades; i++)
    {
        getchar();
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
    printf("%i. %s (%i): %.2f\n", index, student.name, student.registry, student.average);
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