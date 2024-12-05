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
       for(int j=0;j<n-1;j++)
       {
           if(arr[j]>arr[j+1])
           {
               int temp=arr[j];
               arr[j]=arr[j+1];
               arr[j+1]=temp;
           }
       }
   }
   
   printf("The array after sorting is :\n");
   
   for(int i=0;i<n;i++)
   {
       printf("%d ",arr[i]);
   }
}