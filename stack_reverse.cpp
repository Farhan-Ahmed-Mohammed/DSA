#include<iostream>
#include<stack>

using namespace std;

int main()
{ 
    string str;
    cout<<"Enter a string to be reversed :";
    cin>>str;

    stack<char> s;
    for(int i=0;i<str.length();i++)
    {
        char c=str[i];
        s.push(c);
    }
    
    string ans;
    while(!s.empty())
    {
       char ch=s.top();
       ans.push_back(ch);
       s.pop();
    }

    cout<<"The reverse of string using stack is :"<<ans<<endl;
}
