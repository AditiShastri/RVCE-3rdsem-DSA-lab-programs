#include <stdio.h>
#define SIZE 20
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
struct stack
{
    float data[SIZE]; //because infix is string, our stack also should be of type char
    int top;
};
typedef struct stack* STACK;

float pop(STACK s)
{
   if(s->top==-1)
   {
    return -1;
   }
   return s->data[(s->top)--];
}
void push(STACK s, float value)
{
    if (s->top==SIZE-1)
    {
        ;
    }
    else
    {
        s->data[++(s->top)]=value;
    }

}
float peek(STACK s)
{
    return s->data[s->top];

}
int preced(char operator)
{
    if (operator=='+'||operator=='-')
    {
        return 1;
    }
    else if (operator=='*'||operator=='/')
    {
        return 2;
    }
    else if (operator=='^')
    {
        return 3;
    }
    else{
        return 0;
    }
}
bool isOperator(char operator)
{
    if(preced(operator)>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


float operateSubpart(float a,float b, char operator)
{
    switch(operator)
    {
        case '+':
            return a+b;
            break;
         case '-':
            return a-b;
            break;
         case '*':
            return a*b;
            break;
         case '/':
            return a/b;
            break;
         case '^':
            return pow(a,b);
            break;

    }

}

float operate(STACK s, char prefix[SIZE])
{
    char symbol;
    float a,b;
    for (int i=strlen(prefix)-1;i!=-1;i--)
    {
        symbol=prefix[i];
        if(isdigit(symbol))
        {
            push(s,symbol-'0');
        }
        else if(isOperator(symbol))
        {
            if(s->top==-1)
            {
                printf("inalid");
                return -1;
            }
            a=pop(s);
            b=pop(s);
            push(s,operateSubpart(a,b,symbol));
            
        }
        else
        {
            printf("inalid");
            return -1;
        }
    }
    return pop(s);
}

int main()
{
    struct stack s;
    s.top=-1;
    char prefix[SIZE]="-*23+45";
    printf("%f\n",operate(&s,prefix));
    return 0;
}