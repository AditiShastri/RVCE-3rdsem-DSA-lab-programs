#include <stdio.h>
#include <stdlib.h>

struct node
{
    int co;
    int po;
    struct node* next;
};

typedef struct node Node;
typedef Node* NODE;

void display(NODE root)
{
    if(root==NULL)
    {
        return;
    }
    NODE cur=root;
    while(cur->next!=NULL)
    {
        printf("%dx^%d+",cur->co,cur->po);
        cur=cur->next;
    }
    printf("%dx^%d\n",cur->co,cur->po);
}

NODE insertend(NODE root, int co, int po)
{   
    NODE temp=(NODE)malloc(sizeof(Node));
    temp->co=co;
    temp->po=po;
    temp->next=NULL;
    if(root==NULL)
    {
        return temp;
    }
    NODE cur=root;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=temp;
    return root;
}

NODE addterm(NODE root, int co, int po)
{
    NODE cur=root;
    NODE temp=(NODE)malloc(sizeof(Node));
    temp->co=co;
    temp->po=po;
    temp->next=NULL;
    if(root==NULL)
    {
        return temp;
    }
    while(cur!=NULL)
    {
        if(cur->po==po)
        {
            cur->co+=co;
        }
        cur=cur->next;
    }
    root=insertend(root,co,po);
    return root;
}

NODE multiply(NODE root1, NODE root2)
{
    NODE r1,r2,result;
    result=NULL;
    for(r1=root1;r1!=NULL;r1=r1->next)
    {
        for(r2=root2;r2!=NULL;r2=r2->next)
        {
            result=addterm(result,r1->co*r2->co,r1->po+r2->po);
        }
    }
    return result;
}

int main()
{
    NODE result,root1,root2;
    root1=NULL;
    root2=NULL;

    int n1,n2,i,co,po;
    printf("Number of terms in poly1:");
    scanf("%d",&n1);

    for(i=0;i<n1;i++)
    {
        printf("\n Read CO and PO of %d term : ",i);
        scanf("%d%d",&co,&po);
        root1=insertend(root1,co,po);
    }
    printf("pol1 is\t");
    display(root1);

    printf("Number of terms in poly2:");
    scanf("%d",&n2);

    for(i=0;i<n2;i++)
    {
        printf("\n Read CO and PO of %d term : ",i);
        scanf("%d%d",&co,&po);
        root2=insertend(root2,co,po);
    }
    printf("pol2 is\t");
    display(root2);

    result=multiply(root1,root2);
    display(result);

}