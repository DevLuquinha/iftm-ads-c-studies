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
void ClearStudents(Student students[], int amountStd);

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

    for(int i = 0; i < lenGrades; i++)
    {
        sum += grades[i];
    }

    return sum / lenGrades;
}

Student GetDataStudent()
{
    Student student;

    fflush(stdin);
    gets(student.name);

    fflush(stdin);
    scanf("%i", &student.registry);

    for(int i = 0; i < lenGrades; i++)
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
    printf("%i. %s (%i): %.2f\n", index, student.name, student.registry, student.average);
}

void ShowDataStudents(Student students[], int amountStd)
{
    for(int i = 0; i < amountStd; i++)
    {
        ShowDataStudent(students[i], i + 1);
    }
}

void ClearStudents(Student students[], int amountStd)
{
    for(int i = 0; i < amountStd; i++)
    {
        fflush(stdin);
        strcpy(students[i].name, "");
        students[i].registry = 0;
        students[i].grades[0] = 0.0;
        students[i].grades[1] = 0.0;
        students[i].grades[2] = 0.0;
        students[i].average = 0;
    }
}

int main()
{
    Student students[1000];
    
    // Quantidade N de estudantes
    int amountS;
    amountS = GetAmountStudents();    
    
    ClearStudents(students, amountS); // OPCIONAL
    
    // Pegar as (nome, matricula, n1, n2 e n3) dos N estudantes
    GetDataStudents(students, amountS);

    // Imprimir no formato posicao. nome (matricula): media
    ShowDataStudents(students, amountS);

    return 0;
}