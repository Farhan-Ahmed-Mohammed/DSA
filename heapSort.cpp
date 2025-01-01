#include<iostream>
using namespace std;
void heapify(int arr[],int n,int i)   //actually its array only but to understand it we write it as heap
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest])
    {
        largest=left;
    }
      if(right<n && arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(arr[i],arr[largest]);// take largest at top of heap if it is not at top
        heapify(arr,n,largest);
    }
}
    
void heapsort(int arr[],int n)
{
  for(int i= n/2-1;i>=0;i--)
  {
    heapify(arr,n,i);
  }
  for(int i= n-1;i>=0;i--)
  {
    swap(arr[0],arr[i]);
    heapify(arr,i,0);
  }
}

int main()
{
    int arr[]={23,34,45,56,67,78,32,12,41,59,99,7,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    heapsort(arr,n);
    cout<<"sorted array :";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}