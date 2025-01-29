#include <bits/stdc++.h> 
class Deque
{
    int arr[1000];
    int f=-1;
    int r=-1;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size=n;// Write your code here.
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
         if ((f - 1 + size) % size == r)
        {
            return false;  // Deque is full
        }
        if(f==-1)
        {
            f=0;
            r=0;
        }
        else{
             f=(f-1+size)%size;
        }
       
        arr[f]=x;
        return true;// Write your code here.
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
         if((r+1)%size==f)
        {
            return false;
        }
         if(f==-1)
        {
            f=0;
            r=0;
        }
        else{
             r=(r+1)%size;
        }
        
       
        arr[r]=x;
        return true;// Write your code here.
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(f==-1)
        {
            return -1;
        }

        int ans=arr[f];
        if (f == r) {
            f = r = -1;
        }
        else{
             f=(f+1)%size;
        }
       
        return ans;
            // Write your code here.
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (r== -1) {
            return -1;  // Queue is empty
        }

        // Get the front element
        int ans = arr[r];

        // If only one element was in the queue, reset both pointers
        if (f == r) {
            f = r = -1;  // Queue becomes empty after dequeue
        } else {
            // Increment the front pointer circularly
            r = (r -1+size) % size;
        }

        return ans;
    }// Write your code here.
    

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(f==-1)
        {
            return -1;
        }
       
        return arr[f];// Write your code here.
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(r==-1)
        {
            return -1;
        }
       
        return arr[r];// Write your code here.
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(f==-1)
        {
            return true;
        }
        
        else
        {
            return false;
        }// Write your code here.
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((r+1)%size==f)
        {
            return true;
        }
        
        else
        {
            return false;
        }
      }  // Write your code here.
    
};
