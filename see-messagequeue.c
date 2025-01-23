
#include <stdlib.h>
#include <string.h>
#define SIZE 20
#define MAX 5

struct queue
{
    int f;
    int r;
    char messages[MAX][SIZE];
};

typedef struct queue * QUEUE;

void enqueue(QUEUE q, char message[SIZE])
{
 if(q->f==-1)
 {
    strcpy(q->messages[0],message);
    q->f=0;
    q->r=0;
 }
 else if (((q->r+1)%SIZE)==q->f)
 {
    printf("Queue is full \n");
 }
 else
 {
    strcpy(q->messages[(((q->r)+1)%SIZE)],message);
 }

}

void dequeue(QUEUE q)
{
    if(q->f==-1)
    {
        printf("queue is empty, cant dequeu.\n");
    }
    else if(q->f==q->r)
    {
        printf("%s", q->messages[q->f]);
        q->r=-1;
        q->f=-1;
    }
    else
    {
        printf("%s", q->messages[q->f]);
        q->f=((q->f)+1)%SIZE;

    }

}
void display(QUEUE q)
{
    if(q->f==-1)
    {
        printf("queue is empty, cant print.\n");
    }
    else if(q->f==q->r)
    {
        printf("%s\n",q->messages[q->f]);
    }
    else
    {
        int i=q->f;
        while(i!=q->r)
        {
            printf("%s\n",q->messages[i]);
            i++;
        }
        printf("%s\n",q->messages[i]);
    }
}

int main()
{
    int choice;
    struct queue q;
    q.f=-1;
    q.r=-1;
    while(1)
    {
        printf("1.sned\n2.receive\n3.display\n4.exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter ur msg:\t");
                char message[SIZE];
                scanf("%s",message);
                enqueue(&q,message);
                printf("sent successfully\n");
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                exit(0);
        }

    }
    return 0;
}
   