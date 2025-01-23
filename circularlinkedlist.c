//Queue--therefor u want a result of popping of Integers using Circular List
#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node * next;
};

typedef struct node * NODE;

void display(NODE last)
{
    NODE cur=last;
    if(cur==NULL)
    {
        printf("empty");
        return;
    }
    cur=cur->next;
    
    while(cur!=last)
    {
        printf("%d\t",cur->data);
        cur=cur->next;
    }
    printf("%d\t",cur->data);
    printf("\n");
}

NODE insert_end(NODE last, int value)
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->data=value;
    if(last==NULL)
    {
        temp->next=temp;
        return temp;
    }
    temp->next=last->next;
    last->next=temp;
    return last;
}

int delete_begin(NODE last)
{
    if(last==NULL)
    {
        return -1;
    }
    if(last->next==last)
    {
        int data=last->data;
        free(last);
        return data;
    }
    NODE temp=last->next;
    last->next=temp->next;
    int data=temp->data;
    free(temp);
    return data;
}

int main()
{
    NODE last=NULL;
    int choice,data;
    while(1)
    {
        printf("1.insert\n2.delete\n3.display\n4.exit\n\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("what do u wanna isnert\n");
                scanf("%d",&data);
                last=insert_end(last,data);
                break;
            case 2:
                data=delete_begin(last);
                if(data==-1)
                {
                    printf("khaali\n");
                }
                printf("%d",data);
                break;
            case 3:
                display(last);
                break;
            default:exit(0);
                


        }
    }
}
