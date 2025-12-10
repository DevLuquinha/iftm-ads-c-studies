#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORD_LEN 101

struct stack
{
    char word[WORD_LEN];
    struct stack* next;
};
typedef struct stack Stack;

int GetInt()
{
    int value = 0;
    scanf("%i", &value);
    return value;
}

Stack* NewNode()
{
    Stack* stack = malloc(sizeof(Stack));
    stack->next = NULL;
    strcpy(stack->word, "");

    return stack;
}

Stack* AddWord(Stack* wordStack, char word[WORD_LEN])
{
    Stack* newWord = NewNode();
    newWord->next = wordStack;
    if(word != NULL)
    {
        strcpy(newWord->word, word);
    }

    return newWord;
}

Stack* RemoveWord(Stack* wordStack)
{
    Stack* stackRemoved = NULL;
    if(wordStack != NULL)
    {
        stackRemoved = wordStack->next;
    }

    return stackRemoved;
}

Stack* RemoveCommand(Stack* commandStack)
{
    Stack* stackRemoved = NULL;
    if(commandStack != NULL)
    {
        while(strcmp(commandStack->word, "UNDO") == 0 || strcmp(commandStack->word, "PRINT") == 0)
        {
            commandStack = commandStack->next;
        }

        stackRemoved = commandStack->next;
    }

    return stackRemoved;
}

void ShowStack(Stack* stack)
{
    Stack* stackAux = NULL;

    while(stack != NULL)
    {
        stackAux = AddWord(stackAux, stack->word);
        stack = stack->next;
    }

    while(stackAux != NULL)
    {
        printf("%s", stackAux->word);
        stackAux = stackAux->next;
        if(stackAux != NULL)
        {
            printf("\n");
        }
    }
}

int main()
{
    Stack* wordStack = NULL;
    Stack* commandStack = NULL;
    Stack* stackOut = NULL;

    char command[WORD_LEN];
    char word[WORD_LEN];
    char auxWord[WORD_LEN];

    strcpy(command, "");
    strcpy(word, "");

    int commandsAmount = GetInt();
    int wordLength = 0;
    int removeLen = 0;
    getchar();

    for(int i = 0; i < commandsAmount; i++)
    {
        // Get the Command
        scanf("%s", command);
        if(strcmp(command, "PRINT") == 1 && strcmp(command, "UNDO"))
        {
            commandStack = AddWord(commandStack, command);
        }

        if(strcmp(command, "TYPE") == 0) // To type somenthing
        {
            // Get the word
            scanf("%s", word);
            if(wordStack != NULL)
            {
                strcpy(auxWord, wordStack->word);
                strcat(auxWord, word);
                strcpy(word, auxWord);
            }

            // Add the concatened word in stack
            wordStack = AddWord(wordStack, word);
        }
        else if(strcmp(command, "DELETE") == 0) // Remove chars by length
        {
            removeLen = GetInt();
            getchar();

            wordLength = strlen(wordStack->word);
            strcpy(word, wordStack->word);

            for(int c = 0; c < removeLen; c++)
            {
                if(wordLength-1 >= 0)
                {
                    word[wordLength-1] = '\0';
                    wordLength--;
                }
            }

            // Add the modified word in stack
            wordStack = AddWord(wordStack, word);
        }
        else if(strcmp(command, "PRINT") == 0) // Add to stackOut
        {
            stackOut = AddWord(stackOut, wordStack->word);
        }
        else if(strcmp(command, "UNDO") == 0) // Undo command
        {
            wordStack = RemoveWord(wordStack);
            if(commandStack != NULL)
            {
                commandStack = RemoveCommand(commandStack);
            }
        }

        // Clear inputs and aux vars
        command[0] = '\0';
        word[0] = '\0';
        auxWord[0] = '\0';
        removeLen = 0;
        wordLength = 0;
    }    

    ShowStack(stackOut);

    return 0;
}