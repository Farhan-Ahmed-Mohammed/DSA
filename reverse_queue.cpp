class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {
        int size=q.size();
        int arr[size];
        for(int i=0;i<size;i++)
        {
            arr[i]=q.front();
            q.pop();
        }
        
        for(int i=size-1;i>=0;i--)
        {
            q.push(arr[i]);
        }
        return q;// code here.
    }
};
