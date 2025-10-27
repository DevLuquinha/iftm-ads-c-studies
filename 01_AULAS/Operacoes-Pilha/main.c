#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int value;
    struct stack* next;
};
typedef struct stack Stack;

Stack* NewNode(int value)
{
    Stack* stack = malloc(sizeof(Stack));
    stack->value = value;
    stack->next = NULL;

    return stack;
}

Stack* Push(Stack* stack, int value)
{
    Stack* newStack = NewNode(value);
    newStack->next = stack;
    return newStack;
}

void ShowStack(Stack* stack)
{
    printf("[");
    while(stack != NULL)
    {
        printf("%i", stack->value);

        stack = stack->next;
        if(stack != NULL)
        {
            printf(", ");
        }
    }
    printf("]");
}

int main()
{
    // Create stack
    Stack* stack = NULL;

    // Add value in stack
    stack = Push(stack, 1);
    stack = Push(stack, 2);
    stack = Push(stack, 3);
    
    // Show Stack
    printf("PILHA INICIAL: ");
    ShowStack(stack);

    return 0;
}