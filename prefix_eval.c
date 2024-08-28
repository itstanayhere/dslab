#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

typedef struct
{
    int top;
    int items[MAX];
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
    return s->top==MAX-1;
}

void push(Stack *s,int value)
{
    if(isFull(s))
    {
        printf("Stack Overflow!\n");
        return;
    }
    s->items[++(s->top)]=value;
}

int pop(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow!\n");
        return -1;
    }
    return s->items[(s->top)--];
}

int isOperator(char ch)
{
    return ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^';
}

int evaluatePrefix(char* prefix)
{
    Stack s;
    initStack(&s);
    int i;
    for(i=strlen(prefix)-1;i>=0;i--)
    {
        char ch=prefix[i];
        if(isdigit(ch))
        {
            push(&s,ch-'0');
        }
        else if(isOperator(ch))
        {
            int op1=pop(&s);
            int op2=pop(&s);
            int result;
            switch(ch)
            {
                case '+':
                    result=op1+op2;
                    break;
                case '-':
                    result=op1-op2;
                    break;
                case '*':
                    result=op1*op2;
                    break;
                case '/':
                    result=op1/op2;
                    break;
                case '^':
                    result=pow(op1,op2);
                    break;
                default:
                    result=0;
            }
            push(&s,result);
        }
    }
    return pop(&s);
}

int main()
{
    char prefix[MAX];
    printf("Enter a prefix expression: ");
    scanf("%s",prefix);
    int result=evaluatePrefix(prefix);
    printf("Result of prefix expression: %d\n",result);
    return 0;
}