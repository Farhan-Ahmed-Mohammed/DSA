#include <bits/stdc++.h>
using namespace std;

int main() 
{
   long int n;
   cin>>n;
   while(n--)
   {
     long int a;
     cin>>a;
     vector<int> arr(a);
     long int cnt1=0;
     long int cnt2=0;
     for(int i=0;i<a;i++)
     {
         cin>>arr[i];
     }
     
     for(int i=0;i<a;i++)
     {
         if(arr[i]==2)
         {
             cnt1++;
         }
         
         if(arr[i]==1)
         {
             cnt2++;
         }
     }
     int total=2*cnt1+cnt2;
     
     if(total%2==0)
     {
         if(cnt1%2==0 && cnt2%2==0)
         {
             cout<<"Yes"<<endl;
         }
         
         else if(cnt2>=2)
         {
             if(cnt2%2==0)
             {
                 cout<<"Yes"<<endl;
             }
         }
         
         else
         {
             cout<<"No"<<endl;
         }
     }
     
     else
     {
         cout<<"No"<<endl;
     }
    
   }
}