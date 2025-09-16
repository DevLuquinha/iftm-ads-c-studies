#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define LEN_AUTOR 50

struct book
{
    int id;
    char title[31];
    char category[16];
    int numAuthors;
    char vectAuthors[3][LEN_AUTOR];
    int currentExemplares;
    int totalExemplares;
};
typedef struct book Book;

struct query
{
    char queryType[50];
    char queryStr[100];
    int queryInt;
};
typedef struct query Query;

void GetInt(int *var)
{
    scanf("%i", &*var);
}

void GetChar(char var[])
{
    getchar();
    scanf("%s", var);
}

void GetAuthors(int quantAuth, char vectAuthors[3][LEN_AUTOR])
{
    for(int i = 0; i < quantAuth; i++)
    {
        GetChar(vectAuthors[i]);
    }    
}

void ShowAuthors(int quantAuth, char vectAuthors[3][LEN_AUTOR])
{
    for(int i = 0; i < quantAuth; i++)
    {
        printf("\nAUTOR %i: %s", i+1, vectAuthors[i]);
    }    
}

void DoOperation(char operation[], int id, Book vectBooks[])
{
    int i = 0;
    if(strcmp(operation, "EMPRESTAR") == 0)
    {
        i = 0;
        while(vectBooks[i].id != id)
        {
            i++;
        }

        vectBooks[i].currentExemplares -= 1;
    }
    if(strcmp(operation, "DEVOLVER") == 0)
    {
        i = 0;
        while(vectBooks[i].id != id)
        {
            i++;
        }

        vectBooks[i].currentExemplares += 1;
    }
}

void SortByTitle(Book vectBooks[], int lenVec)
{
    Book auxBook;

    for(int i = 0; i < lenVec; i++)
    {
        for(int j = i; j < lenVec - 1; j++)
        {
            if(strcmp(vectBooks[i].title, vectBooks[j+1].title) > 0)
            {
                auxBook = vectBooks[j+1];
                vectBooks[j+1] = vectBooks[i];
                vectBooks[i] = auxBook;
            }
        }
    }
}

void ShowByCategory(char category[], Book vectBooks[], int booksLens)
{
    printf("Categoria: %s", category);
    for(int i = 0; i < booksLens; i++)
    {
        if(strcmp(vectBooks[i].category, category) == 0 && vectBooks[i].currentExemplares != 0)
        {
            printf("\n- %s (%i): %i/%i exemplares", vectBooks[i].title, vectBooks[i].id, vectBooks[i].currentExemplares, vectBooks[i].totalExemplares);
        }
    }
}

void ShowByAuthor(char author[], Book vectBooks[], int booksAmount)
{
    int i = 0;
    int nAuth = 0;
    
    while(strcmp(vectBooks[i].vectAuthors[nAuth], author) != 0 && i < booksAmount)
    {
        if(nAuth == vectBooks[i].numAuthors)
        {
            i++;
            nAuth = 0;
        }
        else
        {
            nAuth++;
        }
    }
    printf("Autor: %s", author);
    printf("\n- %s (%s): %i/%i exemplares", vectBooks[i].title, vectBooks[i].category, vectBooks[i].currentExemplares, vectBooks[i].totalExemplares);
}

void ShowById(int id, Book vectBooks[])
{
    int i = 0;
    while(vectBooks[i].id != id)
    {
        i++;
    }

    printf("Livro: %s", vectBooks[i].title);
    printf("\nCategoria: %s", vectBooks[i].category);
    printf("\nAutores: ");
    for(int j = 0; j < vectBooks[i].numAuthors; j++)
    {
        printf("%s", vectBooks[i].vectAuthors[j]);
        if(j+1 == vectBooks[i].numAuthors)
            printf("");
        else
            printf(", ");
    }
    float percent = (vectBooks[i].currentExemplares / (vectBooks[i].totalExemplares * 1.0)) * 100.0;
    printf("\nExemplares: %i/%i (%.0f%% disponibilidade)", vectBooks[i].currentExemplares, vectBooks[i].totalExemplares, percent);
}

int main()
{
    int booksAmount; // N
    int opeAmount;   // M
    int queryAmount; // Q

    Book vectBooks[501];
    Query vectQuery[101];

    // Receber N, M e Q
    GetInt(&booksAmount);
    GetInt(&opeAmount);
    GetInt(&queryAmount);

    // // Recebe os valores de N
    for(int i = 0; i < booksAmount; i++)
    {
        // id, titulo, categoria, num_autores, autor1, autor2, autor3, exemplares
        GetInt(&vectBooks[i].id);
        GetChar(vectBooks[i].title);
        GetChar(vectBooks[i].category);
        GetInt(&vectBooks[i].numAuthors);
        GetAuthors(vectBooks[i].numAuthors, vectBooks[i].vectAuthors);
        GetInt(&vectBooks[i].totalExemplares);
        vectBooks[i].currentExemplares = vectBooks[i].totalExemplares;
    }

    // Recebe a quantidade M de operações
    char operation[30];
    int bookId;
    for(int i = 0; i < opeAmount; i++)
    {   
        // operacao, id_livro
        GetChar(operation);
        GetInt(&bookId);
        DoOperation(operation, bookId, vectBooks);
    }    

    // Recebe a quantidade Q de Consultas
    char queryType[50];
    char queryString[100];
    int queryInt;
    for (int i = 0; i < queryAmount; i++)
    {
        // Limpar variaveis
        strcpy(queryType, "");
        strcpy(queryString, "");
        queryInt = -1;

        // Pegar o tipo de query
        GetChar(queryType);
        if(strcmp(queryType, "DISPONIVEL") == 0)
        {
            strcpy(vectQuery[i].queryType, queryType);
            GetChar(queryString);
            strcpy(vectQuery[i].queryStr, queryString);
            vectQuery[i].queryInt = -1;
        }
        if(strcmp(queryType, "AUTOR") == 0)
        {
            strcpy(vectQuery[i].queryType, queryType);
            GetChar(queryString);
            strcpy(vectQuery[i].queryStr, queryString);
            vectQuery[i].queryInt = -1;
        }
        if(strcmp(queryType, "STATUS") == 0)
        {
            strcpy(vectQuery[i].queryType, queryType);
            strcpy(vectQuery[i].queryStr, "");
            GetInt(&queryInt);
            vectQuery[i].queryInt = queryInt;
        }
    }

    SortByTitle(vectBooks, booksAmount);

    // Fazer a saída    
    for(int i = 0; i < queryAmount; i++)
    {
        if(strcmp(vectQuery[i].queryType, "DISPONIVEL") == 0)
        {
            ShowByCategory(vectQuery[i].queryStr, vectBooks, booksAmount);
            printf("\n\n");
        }
        if(strcmp(vectQuery[i].queryType, "AUTOR") == 0)
        {
            ShowByAuthor(vectQuery[i].queryStr, vectBooks, booksAmount);
            printf("\n\n");
        }
        if(strcmp(vectQuery[i].queryType, "STATUS") == 0)
        {
            ShowById(vectQuery[i].queryInt, vectBooks);
            printf("\n\n");
        }
    }
    
    return 0;
}