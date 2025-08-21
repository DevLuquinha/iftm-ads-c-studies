#include <stdio.h>
#include <string.h>
#define LEN_GRADES 3

struct student
{
    char name[50];
    int registry;
    float grades[LEN_GRADES];
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
void OrderByAverage(Student students[], int amountStd);

int GetAmountStudents()
{
    int q;
    scanf("%i", &q);

    return q;
}

float AverageStudent(float grades[])
{
    float sum;

    for(int i = 0; i < LEN_GRADES; i++)
    {
        sum += grades[i];
    }

    return sum / LEN_GRADES;
}

Student GetDataStudent()
{
    Student student;

    getchar();
    scanf("%s", student.name);

    getchar();
    scanf("%i", &student.registry);

    for(int i = 0; i < LEN_GRADES; i++)
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

void OrderByAverage(Student students[], int amountStd)
{
    Student aux;

    for(int i = 0; i < LEN_GRADES; i++)
    {
        for(int j = 0; j < LEN_GRADES - 1; j++)
        {
            if(students[j].average < students[j+1].average)
            {
                aux = students[j+1];
                
                students[j+1] = students[j];
                students[j] = aux;
            }
            else if(students[j].average == students[j+1].average)
            {
                if(students[j].registry < students[j+1].registry)
                {
                    aux = students[j+1];
                
                    students[j+1] = students[j];
                    students[j] = aux;
                }
            }
        }
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

    OrderByAverage(students, amountS);

    // Imprimir no formato posicao. nome (matricula): media
    ShowDataStudents(students, amountS);

    return 0;
}