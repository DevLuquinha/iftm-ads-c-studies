#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person
{
    int id;
    struct person* parent;
    struct person* left;
    struct person* right;
};
typedef struct person Person;

int GetInt()
{
    int num = 0;
    scanf("%i", &num);

    return num;
}

Person* NewPerson(int id)
{
    Person* person = malloc(sizeof(Person));
    person->id = id;
    person->left = NULL;
    person->right = NULL;
    person->parent = NULL;

    return person;
}

Person* AddPerson(Person* root, int id)
{
    Person* newPerson = NewPerson(id);

    if(root == NULL)
    {
        root = newPerson;
    }
    else
    {
        Person* lastParent = NULL;
        Person* currentPerson = root;

        while(currentPerson != NULL)
        {
            lastParent = currentPerson;
            if(id < currentPerson->id)
            {
                currentPerson = currentPerson->left;
            }
            else
            {
                currentPerson = currentPerson->right;
            }
        }

        // Storage the parent
        newPerson->parent = lastParent;

        // The new people id is smallest 
        if(id < lastParent->id)
        {
            lastParent->left = newPerson;
        }
        else
        {
            lastParent->right = newPerson;
        }
    }

    return root;
}

void FindPerson(Person* root, int targetId, Person** personOut)
{
    if(root != NULL)
    {
        FindPerson(root->left, targetId, personOut);
        
        if(root->id == targetId)
        {
            (*personOut) = root;
        }

        FindPerson(root->right, targetId, personOut);
    }
}

void HasPersonAsAscentral(Person* person, int targetId, int* hasPerson)
{
    if(person != NULL)
    {
        if(person->id == targetId)
        {
            *hasPerson = 0; // True
        }

        HasPersonAsAscentral(person->parent, targetId, hasPerson);
    }
}

void GetAncestralOld(Person* person1, Person* person2, int* ascentralId)
{
    if(*ascentralId != -1)
    {
        return;
    }

    if(person1->parent != NULL)
    {
        if(person1->id == person2->id)
        {
            *ascentralId = person1->id;
        }

        // printf("(%i,%i) ", person1->id, person2->id);
        GetAncestralOld(person1->parent, person2->parent, ascentralId);
    }
    else
    {
        if(person1 != NULL && person2 != NULL)
        {
            if(person1->id == person2->id)
            {
                *ascentralId = person1->id;
            }

            // printf("(%i,%i) ", person1->id, person2->id);
        }
    }
}

void GetAncestral(Person* person1, Person* person2, int* ascentralId)
{
    if(*ascentralId != -1)
    {
        return;
    }

    if(person1->parent != NULL)
    {
        int hasPerson = 1; // False
        HasPersonAsAscentral(person2, person1->id, &hasPerson); 

        if(hasPerson == 0)
        {
            *ascentralId = person1->id;
        }
        else
        {
            HasPersonAsAscentral(person1, person2->id, &hasPerson); 
            if(hasPerson == 0)
            {
                *ascentralId = person2->id;
            }
            else
            {
                // printf("(%i,%i) ", person1->id, person2->id);
                GetAncestral(person1->parent, person2->parent, ascentralId);
            }
        }
    }
    else
    {
        if(person1 != NULL && person2 != NULL)
        {
            if(person1->id == person2->id)
            {
                *ascentralId = person1->id;
            }
            // printf("(%i,%i) ", person1->id, person2->id);
        }
    }
}

void ShowInOrder(Person* root)
{
    if(root != NULL)
    {
        ShowInOrder(root->left);
        printf("%i ", root->id);
        ShowInOrder(root->right);
    }
}

int main()
{
    Person* peopleTree = NULL;
    
    int personId = 0;
    
    int treeLength = GetInt();
    for(int i = 0; i < treeLength; i++)
    {
        personId = GetInt();
        peopleTree = AddPerson(peopleTree, personId);
    }

    int targetId1 = 0;
    int targetId2 = 0;

    Person* person1 = NULL;
    Person* person2 = NULL;

    int queries = GetInt();
    for (int j = 0; j < queries; j++)
    {
        person1 = NULL;
        person2 = NULL;

        targetId1 = GetInt();
        targetId2 = GetInt();

        FindPerson(peopleTree, targetId1, &person1);
        FindPerson(peopleTree, targetId2, &person2);

        int hasPerson = 1; // False
        HasPersonAsAscentral(person1, person2->id, &hasPerson);

        // Is the same ascestral is by it self
        if(hasPerson == 0) // True
        {
            printf("%i\n", person2->id);
        }
        else
        {
            int id = -1;
            GetAncestral(person1, person2, &id);

            if(id != -1)
            {
                printf("%i\n", id);
            }
        }
    }
    
    return 0;
}