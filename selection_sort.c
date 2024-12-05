#include<stdio.h>

int main()
{
    int arr[1000];
     int n;
    printf("Enter the size of array :");
    scanf("%d",&n);
    printf("Enter the elements in the array :");
    for(int i=0;i<n;i++)
    {
       scanf("%d",&arr[i]);
    }
    
    for(int i=0;i<n;i++)
    {
        int min=i;
        
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
                int temp=arr[min];
                arr[min]=arr[i];
                arr[i]=temp;
    
    }
     printf("After sorting the array :");
    for(int i=0;i<n;i++)
    {
       printf("%d ",arr[i]);
    }
}