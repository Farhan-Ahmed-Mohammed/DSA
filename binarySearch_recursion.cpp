#include <stdio.h>

int binarySearch(int arr[],int key,int low,int high)
{
    int mid=(low+high)/2;
    
    if(arr[mid]=key)
    {
        return mid;
    }
    
   if(low>=high)
   {
       return -1;
   }
   
   else if(key>mid)
   {
       return binarySearch(arr,key,mid+1,high);
   }
   
   else
   {
       return binarySearch(arr,key,low,mid-1);
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
   
   
   for(int i=0;i<n;i++)  //sorting the array by selection sort
   {
       int min=i;
       for(int j=i+1;j<n;j++)
       {
           if(arr[j]<arr[min])
           {
               min=j;
           }
           int temp=arr[j];
           arr[j]=arr[i];
           arr[i]=temp;
       }
   }
  int low=0;
  int high=n;
  printf("Enter the element to be searched :");
  scanf("%d",&key);
  
  int ans=binarySearch(arr,key,low,high);
   
  if(ans==-1)
  {
      printf("The element is not found ");
  }
  else
  {
        printf("The element is found at index : %d",ans);
  }
  
}
