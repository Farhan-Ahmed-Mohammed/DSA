#include<stdio.h>

void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int i=low;
        int j=high;
        int pivot=low;
        
        while(i<j)
        {
            while(arr[pivot]>=arr[i] && i<high)
            {
                i++;
            }
            
            while(arr[pivot]<arr[j] && j>low)
            {
                j--;
            }
            
            if(i<j)
            {
               int temp=arr[i];
               arr[i]=arr[j];
               arr[j]=temp;
            }
        }
        int temp=arr[pivot];
        arr[pivot]=arr[j];
        arr[j]=temp;
        
        quicksort(arr,low,j-1);
        quicksort(arr,j+1,high);
    }
}

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
    
   quicksort(arr,0,n-1);
   for(int i=0;i<n;i++)
   {
       printf("%d ",arr[i]);
   }
}