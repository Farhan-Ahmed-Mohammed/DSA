#include <stdio.h>

int linearSearch(int arr[],int key,int n)
{
    if(n==0)
    {
        return -1;
    }
    
    else if(key==arr[n-1])
    {
        return n-1;
    }
    else
    {
        return linearSearch(arr,key,--n);
    }
}

int main()
{
   int arr[100];
   int n;
   int key;
   printf("Enter the size of array :");
   scanf("%d",&n);
   printf("Enter the elements of array :");
   
   for(int i=0;i<n;i++)
   {
       scanf("%d",&arr[i]);
   }
   
   printf("Enter the element to be searched :");
   scanf("%d",&key);
   int ans=linearSearch(arr,key,n);
   
   if(ans==-1)
   {
       printf("The element is not found ");
   }
   else
   {
        printf("The element is found at index : %d",ans);
   }
  
}
