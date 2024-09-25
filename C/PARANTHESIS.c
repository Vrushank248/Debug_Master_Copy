

// /*
// Given an expression string x. Examine whether the pairs and the orders of {,},(,),[,] are correct in exp.
// For example, the function should return 'true' for exp = [()]{}{[()()]()} and 'false' for exp = [(]).

// Note: The driver code prints "balanced" if function return true, otherwise it prints "not balanced".
// *




#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100


char stack[MAX];
int top = -1;


void push(char x)
{
    if (top == MAX - 1)
        return;
    stack[++top] = x;
}


char pop()
{
    if (top == -1)
        return '\0';
    return stack[top--];
}


bool isBalanced(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            char popped = pop();
            if ((exp[i] == ')' && popped != '(') ||
                (exp[i] == '}' && popped != '{') ||
                (exp[i] == ']' && popped != '['))
            {
                return false;
            }
        }
    }
    return top == -1;
}


int main()
{
    char exp[] = "[()]{}{[()()]()}";
    if (isBalanced(exp))
        printf("balanced\n");
    else
        printf("not balanced\n");
    return 0;
}
