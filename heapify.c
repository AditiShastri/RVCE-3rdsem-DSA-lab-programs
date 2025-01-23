#include <stdio.h>
#define SIZE 10
void heapify(int arr[], int n, int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

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
        arr[largest]=temp; //swap largest and root
        heapify(arr, n, largest);
    }
}

void heapify_wrapper(int arr[], int n)
{
    for(int j=n/2;j>=1;j--)
    {
        heapify(arr,n,j);
    }
}

int main()
{
    int arr[SIZE];
    while(1)
    {
        printf("1.insert \n2.extartc max\n3.exit\n");
    }
}