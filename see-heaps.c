#include <stdio.h>
#define SIZE 10
#include <stdlib.h>

void heapify_element(int arr[SIZE],int n,int i)
{
    int largest=i;
    int left=2*i;
    int right=2*i+1;

    if(left<=n && arr[left]>arr[largest])
    {
        largest=left;
    }
     if(right<=n && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;


        heapify_element(arr,n,largest);
    }

}

void heapify(int arr[SIZE], int n)
{
    for(int i=n/2;i>0;i--)
    {
        heapify_element(arr,n,i);
    }
}

int main()
{
    int arr[SIZE];
    int choice,n;
    while(1)
    {
        printf("1.create heap\n2.extratc max\n3. exit");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                
                printf("No of elements:\t");
                scanf("%d",&n);
                arr[0]=-1;
                for(int i=1;i<=n;i++) // 1 to n+1
                {
                    printf("Element %d:\t",i);
                    scanf("%d",&arr[i]);
                }
                printf("Before heapify operation:\n");
                for(int i=1;i<=n;i++)
                {
                    printf("Element %d:\t%d\n",i,arr[i]);
                    
                }
                heapify(arr,n);
                printf("After heapify operation:\n");
                for(int i=1;i<=n;i++)
                {
                    printf("Element %d:\t%d\n",i,arr[i]);
                    
                }
                break;
            case 2:
                if(n<1)
                {
                    printf("empty heap.nothing to extract\n");
                }
                printf("max element is %d\n",arr[1]);
                arr[1]=arr[n];
                n--;
                heapify(arr,n);
                printf("After heapify operation:\n");
                for(int i=1;i<=n;i++)
                {
                    printf("Element %d:\t%d\n",i,arr[i]);
                    
                }
                break;



        }
    }
}