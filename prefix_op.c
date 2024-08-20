#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct 
{
    int data[MAX];
    int top;
} Stack;
void init(Stack *s) 
{
    s->top=-1;
}
int isEmpty(Stack *s) 
{
    return s->top==-1;
}
void push(Stack *s, int value) 
{
    if (s->top==MAX-1) 
    {
        printf("Stack overflow!\n");
        return;
    }
    s->data[++(s->top)] = value;
}
int pop(Stack *s) 
{
    if (isEmpty(s)) 
    {
        printf("Stack underflow!\n");
        return -1;
    }
    return s->data[(s->top)--];
}
int evaluatePostfix(char *exp) 
{
    Stack s;
    init(&s);
    for (int i=0;exp[i]!='\0';i++) 
    {
        if (isdigit(exp[i])) 
        {
            push(&s,exp[i]-'0');
        }
        else 
        {
            int op2=pop(&s);
            int op1=pop(&s);

            switch(exp[i]) 
            {
                case '+':
                    push(&s,op1+op2);
                    break;
                case '-':
                    push(&s,op1-op2);
                    break;
                case '*':
                    push(&s,op1*op2);
                    break;
                case '/':
                    push(&s,op1/op2);
                    break;
                default:
                    printf("Invalid operator: %c\n", exp[i]);
                    return -1;
            }
        }
    }
    return pop(&s);
}
int main() 
{
    char exp[MAX];
    printf("Enter postfix expression: ");
    scanf("%s",exp);
    int result=evaluatePostfix(exp);
    printf("Result of the postfix expression is: %d\n", result);
    return 0;
}
