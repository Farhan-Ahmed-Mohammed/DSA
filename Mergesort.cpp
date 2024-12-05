#include<iostream>
using namespace std;
void merge(int arr[],int low,int mid,int high)
{
    int b[high-low+1];
    int temp=low;//low values is changing so store it 
    int j=mid+1;
    int i=0;
    while(low<=mid && j<=high)
    { 
        if(arr[low]<arr[j])// two arrays send the small value from both arrays first
     {
        b[i]=arr[low];
        low++;// after sending the smaller array in first array increment the array
     }
    else
     {
        b[i]=arr[j];// sending value from the other array in a temporary array
        j++;
     }
     i++;//increment the temporary array pointer ever time if we insert something 
    }
     while(low<=mid)// if some elements are left then send them into temporary array
     {
        b[i]=arr[low];
        i++;
        low++;
     }
      while(j<=high)
     {
        b[i]=arr[j];
        i++;
        j++;
     }
      for (int k = 0; k < i; k++) // copy to original array
      {
        arr[temp + k] = b[k];
      }
    
}
void mergeSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);//dividing the original array into two parts
         mergeSort(arr,mid+1,high);
         merge(arr,low,mid,high);// sending the divided array values into the function
    }
}

int main()
{
    int arr[]={23,34,45,56,67,78,32,12,41,59,99,7,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,n-1);
    cout<<"sorted array :";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}