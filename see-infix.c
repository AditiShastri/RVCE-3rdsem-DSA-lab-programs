#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#define SIZE 20
struct stack
{
    char data[SIZE]; //because infix is string, our stack also should be of type char
    int top;
};
typedef struct stack* STACK;

char pop(STACK s)
{
   if(s->top==-1)
   {
    return -1;
   }
   return s->data[(s->top)--];
}
void push(STACK s, char value)
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
char peek(STACK s)
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

void conversion(STACK s,char infix[SIZE], char postfix[SIZE])
{
    //postfix="";
    //strcpy(s->data,"");
    char symbol;
    int j=0;
    for(int i=0;infix[i]!='\0';i++)
    {
        //printf("\n%s\n",s->data);
        symbol=infix[i];

        if(isalnum(symbol))//operator so append to postfix
        {
            postfix[j++]=symbol;

        }
        else if(symbol=='(')
        {
            push(s,symbol);
        }
        else if(symbol==')')
        {
            while(peek(s)!='(')
            {
                postfix[j++]=pop(s);
            }
            if(peek(s)!='(')
            {
                return;
            }
            pop(s);
        }
        else if(isOperator(symbol))
        {
        
            while((s->top!=-1)&&(peek(s)!='(')&&(preced(peek(s))>=preced(symbol)))
            {
               postfix[j++]=pop(s);
                
            }         
            
            if(peek(s)==')')
            {
                pop(s);
            }
            push(s,symbol);
        }
        else
        {
            printf("invalid symbol");
            return;
           }

    }

    while(s->top!=-1)
    {
        postfix[j++]=pop(s);
    }
    postfix[j++]='\0';

    
}
int main()
{
    struct stack s;
    s.top=-1;
    char postfix[SIZE];
    
    // printf("what is the infix string? \n");
    // scanf("%s",infix);
    char infix[SIZE]="A+(B*C)-D";
    
    conversion(&s,infix,postfix);
    printf("%s\n",postfix);
    return 0;
}