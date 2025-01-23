#include <stdio.h>
#include <stdlib.h>

struct node
{
    int co;
    int po;
    struct node * next;
};
typedef struct node * NODE;


NODE addterm(NODE root, int co, int po)
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->co=co;
    temp->po=po;
    temp->next=NULL;
    if(root==NULL)
    {
        root=temp;
        return root;
    }
    NODE ptr=root;
    while(ptr->next!=NULL)
    {
        if(ptr->po==po)
        {
            ptr->co+=co;
            return root;
        }
        ptr=ptr->next;
    }
    ptr->next=temp;
    return root;
}

NODE multiply(NODE poly1,NODE poly2)
{
    NODE result=NULL;
    NODE ptr1,ptr2;
    for(ptr1=poly1;ptr1!=NULL;ptr1=ptr1->next)
    {
        for(ptr2=poly2;ptr2!=NULL;ptr2=ptr2->next)
        {
            result=addterm(result,ptr1->co*ptr2->co,ptr2->po+ptr2->po);
        }
    }
    return result;
}

void display(NODE root)
{
    NODE ptr=root;
    while(ptr->next!=NULL)
    {
        printf("%dx^%d+ ",ptr->co,ptr->po);
        ptr=ptr->next;
    }
    printf("%dx^%d\n ",ptr->co,ptr->po);
}

int main()
{
    NODE poly1,poly2;
    poly1=NULL;
    poly2=NULL;
    int n1,n2,co,po;
    printf("\nPoly1:\n");
    printf("n1:\t");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        printf("Co\t and po\t");
        scanf("%d%d",&co,&po);
        poly1=addterm(poly1,co,po);
    }
    printf("\nPoly2:\n");
    printf("n2:\t");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        printf("Co\t and po\t");
        scanf("%d%d",&co,&po);
        poly2=addterm(poly2,co,po);
    }
    NODE result=multiply(poly1,poly2);
    display(poly1);
    display(poly2);
    display(result);
}