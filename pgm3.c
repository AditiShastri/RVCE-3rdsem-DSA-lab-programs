//message queue
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define SIZE 5

struct queue
{
    char messages[SIZE][20];
    int front,rear;
};
typedef struct queue* QUEUE;

void send(QUEUE q, char message[20])
{
  if((q->rear+1)%SIZE==q->front)
  {
    printf("queue full");
  }
  else{
     q->rear=(q->rear+1)%SIZE;
     strcpy(q->messages[q->rear],message);
     if(q->front==-1)
     {
        q->front=0;
     }
  }
}

char* receive(QUEUE q)
{
    static char temp[20];
    if (q->front==-1)
    {
        
        return "no messages";
    }
  
    else
    {
        strcpy(temp, q->messages[q->front]);
        if(q->front==q->rear)
        {
            q->front=-1;
            q->rear=-1;
            return temp;
        }
        
       q->front=(q->front+1)%SIZE;
         
  
        return temp;
        
    }
}

void display(struct queue q)
{   
     if (q.front==-1)
    {
        printf("no messages \n");
        return;
       
    }
    int i;
    for(i=q.front;i!=q.rear;i=(i+1)%SIZE)
    {
        printf("%s\t",q.messages[i]);
    }
    printf("%s\n",q.messages[i]);

  
}

int main()
{
    struct queue q;
    q.front=-1;
    q.rear=-1;

    int choice;
    char message[20];

    while(true)
    {
        printf("\n1.send\n2.recieve\n3.display\n4.exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("whats ur message:\t");
                scanf("%s",message);
                send(&q,message);
                printf("sent successfully\n");
                break;
            case 2:
                strcpy(message,receive(&q));
                printf("%s",message);
                break;
            case 3:
               display(q);
               break;
            default:
                exit(0); 
        }

    }
}