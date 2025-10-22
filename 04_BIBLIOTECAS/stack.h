#ifndef stacklib
#define stacklib

struct stack
{
    int value;
    struct stack* next;
};
typedef struct stack Stack;

#endif
