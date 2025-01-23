#include <stdio.h>
#define SIZE 10
#define PRIME 7

int hash_table[SIZE]={0};

int hash1(int key) //primary hash
{
    return key%SIZE;
}

int hash2(int key)
{
    return PRIME-key%PRIME;
}

void insert(int key)
{
    int i1=hash1(key);
    int i2=hash2(key);

    if(hash_table[i1]==0)
    {
        hash_table[i1]=key;
        printf("inserted successfully at position %d\n",i1);
        return;
    }
    int k=1;

    while(hash_table[i1+k*i2]!=0)
    {
        k++;
        if((i1+k*i2)>SIZE)
        {
            printf("cant insert! hash table filled\n");
            return;
        }
    }
    hash_table[i1+k*i2]=key;
    printf("inserted successfully at position %d\n",i1+k*i2);
    return;
}

void delete(int key)
{
    int i1=hash1(key);
    int i2=hash2(key);
    int k=0;
    int index=i1+k*i2;
    while(hash_table[index]!=key)
    {
        k++;
        index=i1+k*i2;
        if (index>SIZE)
        {
            printf("cant delete! value not found\n");
            return;
        }
    }
    hash_table[index]=0;
    printf("deleted key %d at pos %d\n",key,index);
    return;
}

void display()
{
    for (int i=0;i<SIZE;i++)
    printf("%d\n",hash_table[i]);
}

int main()
{
    int choice,key;
    while(1)
    {
        printf("1.insert\n2.delete\n3.display\n4.exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("what u wanna insert ma\t");
                scanf("%d",&key);
                insert(key);
                break;
            case 2:
                printf("what u wanna delete ma\t");
                scanf("%d",&key);
                delete(key);
                break;
            case 3:
                printf("\n");
                display();
        }
    }
}