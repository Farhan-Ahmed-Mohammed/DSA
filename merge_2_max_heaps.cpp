 vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        priority_queue<int> pq;
        for(int i=0;i<a.size();i++)
        {
            pq.push(a[i]);
        }
        
        for(int i=0;i<b.size();i++)
        {
            pq.push(b[i]);
        }
        
       vector<int> ans;
       for(int i=0;i<n+m;i++)
       {
           ans.push_back(pq.top());
           pq.pop();
       }
       return ans;
        // your code here
    }
