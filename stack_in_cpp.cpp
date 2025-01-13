#include<iostream>
#include<stack>

using namespace std;

class Stack
{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size)
    {
        this->size=size;
        arr=new int[size];
        top=-1;

    }

    void push(int element)
    {
        if(top==size)
        {
            cout<<"Stack overflow"<<endl;
        }

        else
        {
             top++;
            arr[top]=element;
           
        }
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack underflow"<<endl;
        }

        else
        {
            top--;
        }
    }

    void display()
    {
        for(int i=0;i<=top;i++)
        {
            cout<<arr[i]<<endl;
        }
    }
};

int main()
{
    Stack s(5);
    s.push(5);
    s.push(15);
    s.push(25);
    s.push(75);
    s.pop();
    s.display();
    s.pop();
    s.pop();
    s.pop();
    s.pop();
}