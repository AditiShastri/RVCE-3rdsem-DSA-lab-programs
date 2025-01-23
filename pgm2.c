//prefix evaluation -- works for numerals
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define SIZE 20
typedef struct stack
{
    int top;
    float data[SIZE];
}Stack;
typedef struct stack* STACK;


float pop(STACK s)
{
    if(s->top==-1)
    {
        printf("underflow");
        return -1;
    }
    return s->data[(s->top)--];
}

void push(STACK s, float val)
{
    if (s->top>SIZE-1)
    {
        printf("overflow");
        return;
    }
    s->data[++(s->top)]=val;
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


float operate(float a, float b, char operator)
{
      switch(operator)
    {
        case '^': return pow(a,b);
        case '*': return a*b;
        case '/': return a/b;
        case '+': return a+b;
        case'-': return a-b;
        //default: return;
    }
}

float evaluate(char prefix[SIZE],STACK s)
{
    int n=strlen(prefix);
    n--;
    char symbol;
    float a,b;
    for(int i=n; prefix[i]!='\0'; i--)
    {   
        symbol=prefix[i];
        if(isalnum(symbol))
        {
            push(s,symbol-'0');
        }
        else
        {
            if(s->top==-1)
            {
                printf("invalid");
                exit(0);
            }
            else if(is_operator(symbol))
            {
                a=pop(s);
                b=pop(s);
                push(s,operate(a,b,symbol));
            }
            else{
                printf("invalid");
                exit(0);
            }

        }
    }
    return pop(s);
}

int main()
{
 char prefix[SIZE];
 struct stack s;
 s.top=-1;
 printf("\n Read prefix expr\n");
 scanf("%s",prefix);
 printf("%f",evaluate(prefix,&s));

}