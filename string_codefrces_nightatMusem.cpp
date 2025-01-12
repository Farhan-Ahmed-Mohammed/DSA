#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string input;
    cin >> input; // Read the input string
   
   char current='a';
   int cnt=0;
   for(char target:input)
   {
       int clockwise=abs(target-current);
       int  anticlock=26-clockwise;
       
       cnt=cnt+min(clockwise,anticlock);
       current=target;
   }
   
   cout<<cnt<<endl;
}