class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        int n=q.size();  //q.size() keep changing when we pop elements so store size in n
        int arr[n];
         for(int i=0;i<n;i++)
        {
            arr[i]=q.front();
            q.pop();
        }
        
         for(int i=k-1;i>=0;i--)
        {
            q.push(arr[i]);
        }
        
        for(int i=k;i<n;i++)
        {
            q.push(arr[i]);
        }
        
       
        
        return q;// add code here.
    }
};
