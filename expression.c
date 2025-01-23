
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

struct node 
{
    char value;
    struct node* left;
    struct node* right;
};
typedef struct node* NODE;


typedef struct stack
{
    int top;
    NODE data[SIZE];
}Stack;
typedef struct stack* STACK;


NODE pop(STACK s)
{
    if(s->top==-1)
    {
        printf("underflow");
        return NULL;
    }
    return s->data[(s->top)--];
}

void push(STACK s,NODE val)
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

NODE create_node(char value)
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->value=value;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

NODE expression_tree(STACK OS, STACK TS, char infix[20])
{
    int n=strlen(infix)-1;
    
    for(int i=n;infix[i]!='\0';i--) //go ulta
    {
        char symbol=infix[i];
        NODE temp=create_node(symbol);
        if(isalnum(symbol))
        {
            push(TS,temp);
        }
        else
        {
            if(OS->top==-1)
            {
                push(OS,temp);
            }
            else
            {
                while(OS->top!=-1 && ((preced((OS->data[OS->top])->value))>=preced(symbol)))
                {
                    NODE t=pop(OS);
                    t->right=pop(TS);
                    t->left=pop(TS);
                    push(TS,t);
                }
                push(OS,temp);
            }
        }
    }
    while(OS->top!=-1)
    {
        NODE t=pop(OS);
        t->right=pop(TS);
        t->left=pop(TS);
        push(TS,t);
    }
    return pop(TS);
}

void inorder(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%c \t",root->value);
    inorder(root->right);
}
void preorder(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    
    printf("%c \t",root->value);
    preorder(root->left);
    preorder(root->right);
}
void postorder(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    
    
    postorder(root->left);
    postorder(root->right);
    printf("%c \t",root->value);
}
int main()
{
    struct stack OS;
    struct stack TS;
    OS.top=-1;
    TS.top=-1;
    char infix[20]="A+B*C";
    NODE root=expression_tree(&OS,&TS,infix);
    inorder(root);
}