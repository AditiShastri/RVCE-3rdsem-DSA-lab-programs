#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

typedef struct node * NODE;

NODE enqueue(NODE last, int value)
{
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->data=value;
    if(last==NULL)
    {
        last=temp;
        last->next=last;
        printf("enqueed successfully.\n");
        return last;
    }
    temp->next=last->next;
    last->next=temp;
    last=temp; //last should be moved eeach time to point to the most recently added element
    printf("enqueed successfully.\n");
    return last;
}

int dequeue(NODE* last)
{
    if ((*last)==NULL)
    {
        printf("khaali\n");
        return -1;
    }
    else if((*last)->next==(*last))
    {
        int data=(*last)->data;
        free((*last));
        (*last)=NULL;
        return data;
    }
    else
    {
        NODE temp=(*last)->next;
        int data=temp->data;
        (*last)->next=temp->next;
        free(temp);
        return data;
    }
}

void display(NODE last)
{
    if(last==NULL)
    {
        printf("empty");
        return;
    }
    if(last->next==last)
    {
        printf("%d\n",last->data);
        return;
    }
    NODE ptr=last->next;
    while(ptr!=last)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
    printf("%d\n",last->data);

}
NODE last=NULL;
int main()
{
    int choice;
    
    while(1)
    {
        printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                int val;
                printf("val\t:");
                scanf("%d",&val);
                last=enqueue(last,val);
                printf("\n");
                break;
            case 2:
                int ans=dequeue(&last);
                
                printf(" dequeud= %d\n",ans);
                printf("\n");
                break;
            case 3:
                display(last);
                printf("\n");
                printf("\n");
                break;
        }
    }
}