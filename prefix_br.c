#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    int top;
    char *items[MAX];
} Stack;

void initStack(Stack *s)
{
    s->top=-1;
}

int isEmpty(Stack *s)
{
    return s->top==-1;
}

int isFull(Stack *s)
{
    return s->top==MAX - 1;
}

void push(Stack *s, char *value)
{
    if(isFull(s))
    {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)]=value;
}

char *pop(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow!\n");
        return NULL;
    }
    return s->items[(s->top)--];
}

int isOperator(char ch)
{
    return ch=='+' || ch=='-' || ch=='*' || ch=='/';
}

void convertPrefixToInfix(char *prefix)
{
    Stack s;
    initStack(&s);
    int i;

    for(i=strlen(prefix)-1;i>=0;i--)
    {
        char ch=prefix[i];

        if(isOperator(ch))
        {
            char *op1=pop(&s);
            char *op2=pop(&s);

            int size=strlen(op1) + strlen(op2) + 4;
            char *expr=(char *)malloc(size * sizeof(char));

            expr[0]='(';
            strcpy(expr + 1, op1);
            expr[strlen(op1) + 1]=' ';
            expr[strlen(op1) + 2]=ch;
            expr[strlen(op1) + 3]=' ';
            strcpy(expr + strlen(op1) + 4, op2);
            expr[size - 2]=')';
            expr[size - 1]='\0';

            push(&s, expr);

            free(op1);
            free(op2);
        }
        else if(isalnum(ch))
        {
            char *op=(char *)malloc(2 * sizeof(char));
            op[0]=ch;
            op[1]='\0';
            push(&s, op);
        }
    }

    char *result=pop(&s);
    printf("Fully parenthesized infix expression: %s\n", result);
    free(result);
}

int main()
{
    char prefix[MAX];
    printf("Enter a prefix expression: ");
    scanf("%s", prefix);
    convertPrefixToInfix(prefix);
    return 0;
}
