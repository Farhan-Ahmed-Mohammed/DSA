#include<stdio.h>

int f=-1;
int r=-1;
int n=5;

void qinsert(int arr[],int element)
{
    if((r+1)%n==f)
    {
        printf("over flow");
        return;
    }

    if(f==-1)
    {
        f=r=0;
    }

    else
    {
        r=(r+1)%n;
    }
    arr[r]=element;
    printf("%d is inserted into the queue\n",element);
}

void qdelete(int arr[])
{
    if(f==-1)
    {
        printf("The queue is empty");
        return; 
    }

    int deleteElement=arr[f];

    if(f==r)
    {
        f=r=-1;
    }

    else
    {
        f=(f+1)%n;
    }
    printf("\n%d is deleted from the circular queue \n",deleteElement);
}

void print(int arr[])
{
    if(f==-1)
    {
        printf("The array is empty");
        return;
    }
    int i=f;
    while(1)
    {
        printf("%d ",arr[i]);
        if(i==r)
        {
            break;
        }
        i=(i+1)%n;
    }
}

int main()
{
    int arr[100];
    qinsert(arr,5);
    qinsert(arr,6);
    qinsert(arr,7);
    qinsert(arr,8);
    qinsert(arr,9);
    printf("\nThe elements of queue are :");
    print(arr);
    qdelete(arr);
    printf("\nThe elements of array after deleting :");
    print(arr);
}