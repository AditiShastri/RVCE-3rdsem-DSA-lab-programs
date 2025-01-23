#include <stdio.h>
#define SIZE 10
#define PRIME 7
#include <stdlib.h>
int table[SIZE]={0};

int hash1(int key)
{
    return key%SIZE;
}

int hash2(int key)
{
    return PRIME-(key%PRIME);
}

void insert(int key)
{
    int index;
    int i1=hash1(key);
    int i2=hash2(key);
    int k=0;
    index=i1+k*i2;
    while(table[index]!=0){
        k++;
        index=i1+k*i2;
        if(index>SIZE)
        {
            printf("FULL\n cant insert\n");
            return;
        }
    }
    table[index]=key;
    printf("successfully inserted %d at %d\n\n",key,index);
}
void delete(int key)
{
    int index;
    int i1=hash1(key);
    int i2=hash2(key);
    int k=0;
    index=i1+k*i2;
    while(table[index]!=key)
    {
        
        k++;
        index=i1+k*i2;
        if(index>SIZE)
        {
            printf("not present \n");
            return;
        }
    }
    table[index]=0;
    printf("successfully deleted %d at %d\n\n",key,index);
    
}
void display()
{   
    printf("hash table is\n");
    for(int i=0;i<SIZE;i++)
    {
        printf("%d: %d\n",i,table[i]);
    }
    printf("\n");
}

int main()
{
    while(1)
    {
        printf("1.insert\n2.delete\n3.display\n4.exit\n");
        int choice;
        int key;
        printf("whats ur choice \t");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("what do u wanna isnert \t");
                scanf("%d",&key);
                insert(key);
                break;
            case 2:
                printf("what do u wanna delete \t");
                scanf("%d",&key);
                delete(key);
                break;
            case 3:
                display();
                break;
            default:exit(0);


        }
    }
}