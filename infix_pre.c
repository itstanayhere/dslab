#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

typedef struct
{
    int top;
    char arr[MAX];
}Stack;
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
void push(Stack *s, char ch)
{
    if(isFull(s))
    {
        printf("Stack Overflow!");
        return;
    }
    s->arr[++(s->top)]=ch;
}
char pop(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow!");
        return '\0';
    }
    return s->arr[(s->top)--];
}
char peek(Stack *s)
{
    if(isEmpty(s))
    {
        printf("Stack Underflow!");
        return '\0';
    }
    return s->arr[s->top];
}
int isOperator(char ch)
{
    return ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^';
}
void revBrackets(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='(')
            str[i]=')';
        else if(str[i]==')')
            str[i]='(';
    }
}
void revString(char *str)
{
    int n=strlen(str);
    for(int i=0;i<n/2;i++)
    {
        char temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
}
int prec(char ch)
{
    switch(ch)
    {
        case '+':
        case '-':
            return 1;
            break;
        case '*':
        case '/':
            return 2;
            break;
        case '^':
            return 3;
            break;
        default:
            return -1;
    }
}
void conv(char *infix,char *prefix)
{
    Stack s;
    initStack(&s);
    int i=0,j=0;
    revString(infix);
    revBrackets(infix);
    while(infix[i]!='\0')
    {
        char ch=infix[i];
        if(isalnum(ch))
        {
            prefix[j++]=ch;
        }
        else
        {
            if(ch=='(')
            {
                push(&s,ch);
            }
            else if(ch==')')
            {
                while(!isEmpty(&s) && peek(&s)!='(')
                {
                    prefix[j++]=pop(&s);
                }
                pop(&s);
            }
            else if(isOperator(ch))
            {
                while(!isEmpty(&s) && prec(peek(&s))>=prec(ch))
                {
                    prefix[j++]=pop(&s);
                }
                push(&s,ch);
            }
        }
        i++;
    }
    while(!isEmpty(&s))
    {
        prefix[j++]=pop(&s);
    }
    prefix[j]='\0';
    revString(prefix);
}
int main()
{
    char in[MAX],pre[MAX];
    printf("Enter an infix expression:");
    scanf("%s",in);
    conv(in,pre);
    printf("Prefix expression:");
    printf("%s",pre);
}