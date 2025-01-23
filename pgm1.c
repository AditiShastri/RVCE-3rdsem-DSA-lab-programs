//infix to postfix

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#define SIZE 20
typedef struct stack
{
    int top;
    char data[SIZE];
}Stack;
typedef struct stack* STACK;


char pop(STACK s)
{
    if(s->top==-1)
    {
        printf("underflow");
        return -1;
    }
    return s->data[(s->top)--];
}

void push(STACK s, char val)
{
    if (s->top>SIZE-1)
    {
        printf("overflow");
        return;
    }
    s->data[++(s->top)]=val;
}

int preced(char operator)
{
    switch(operator)
    {
        case '^': return 5;
        case '*':
        case '/': return 2;
        case '+':
        case'-': return 1;
        default: return 0;
    }
}

bool is_operator(char operator)
{
    switch(operator)
    {
        case '^':
        case '*':
        case '/': 
        case '+':
        case'-': return true;
        default: return false;
    }
}

void conversion(char infix[SIZE], STACK s)
{
    char postfix[SIZE]="";
    int j=0;
    for(int i=0;infix[i]!='\0';i++)
    {
        char symbol=infix[i];
        if(isalnum(symbol))
        {
            postfix[j++]=symbol;
            
        }
        else
        {
            if(symbol=='(')
            {
                push(s,symbol);
            }
            else
            {
                switch(symbol)
                {
                    case '(':
                        push(s, symbol);
                        break;

                    case ')':
                        char temp=pop(s);
                        while(temp!='(')
                        {
                            postfix[j++]=temp;
                            temp=pop(s);
                        }
                        break;

                    case '+':
                    case '-':
                    case '/':
                    case '*':
                    case '^':
                        if(s->data[s->top]=='(' || s->top==-1)
                        {
                            push(s, symbol);
                           
                        }
                        else
                        {
                            while((preced(s->data[s->top])>=preced(symbol)) && s->top!=-1 && s->data[s->top]!='(')
                            {
                                postfix[j++] = pop(s);
                            }
                            push(s,symbol);
                        }
                        break;

                }
            }
        }
    }

   
    

    while(s->top!=-1)
    {
        postfix[j++]=pop(s);
    }
    postfix[j]='\0';
    printf("%s\n",postfix);
    }

int main()
{
    Stack s;
    s.top=-1;
    char infix[SIZE]="(A+B)*(C-D)";
    conversion(infix,&s);
    return 0;
   
}