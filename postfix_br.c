#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct 
{
    char* data[MAX];
    int top;
} Stack;

void init(Stack* s)
{
    s->top = -1;
}

int isEmpty(Stack* s)
{
    return s->top == -1;
}

void push(Stack* s, char* value)
{
    if (s->top == MAX - 1)
    {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++(s->top)] = value;
}

char* pop(Stack* s)
{
    if (isEmpty(s))
    {
        printf("Stack underflow!\n");
        return NULL;
    }
    return s->data[(s->top)--];
}

void conv(char* exp, const char* op1, char operator, const char* op2)
{
    int index = 0;
    exp[index++] = '(';
    for (int i = 0; op1[i] != '\0'; i++)
    {
        exp[index++] = op1[i];
    }
    exp[index++] = operator;
    for (int i = 0; op2[i] != '\0'; i++)
    {
        exp[index++] = op2[i];
    }
    exp[index++] = ')';
    exp[index] = '\0';
}

void convert(char* exp)
{
    Stack s;
    init(&s);
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isalnum(exp[i]))
        {
            char* operand = (char*)malloc(2 * sizeof(char));
            operand[0] = exp[i];
            operand[1] = '\0';
            push(&s, operand);
        }
        else
        {
            char* op2 = pop(&s);
            char* op1 = pop(&s);
            char* exp = (char*)malloc(strlen(op1) + strlen(op2) + 4);
            conv(exp, op1, exp[i], op2);
            free(op1);
            free(op2);
            push(&s, exp);
        }
    }
    char* result = pop(&s);
    printf("Fully parenthesized infix exp is: %s\n", result);
    free(result);
}

int main()
{
    char exp[MAX];
    printf("Enter postfix exp: ");
    scanf("%s", exp);
    convert(exp);
    return 0;
}
