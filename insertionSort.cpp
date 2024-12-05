#include<iostream>
using namespace std;
int main()
{
    int arr[]={23,34,45,56,67,78,32,12,41,59,99,7,4};
    int n=sizeof(arr)/sizeof(arr[0]);
   
    cout<<"sorted array :";
    for(int i=0;i<n;i++)
    {   int temp=arr[i];//store in temp as i value changes
        int j=i-1;
        for(;j>=0;j--)
        {
         if(arr[j]>temp)
            {
            arr[j+1]=arr[j];
            }
            else
            {
                break;
            }
        }
    arr[j+1]=temp;
}
for(int i=0;i<n;i++)
{
    cout<<arr[i]<<" ";
}
}