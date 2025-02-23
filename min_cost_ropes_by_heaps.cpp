int minCost(vector<int>& arr) {
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>> pq; //make min heap
        for(int i=0;i<n;i++)
        {
            pq.push(arr[i]);
        }
        int cost=0;
        
        while(pq.size()>1)
        {
            int a=pq.top();
            pq.pop();
            
            int b=pq.top();
            pq.pop();
            
            int sum=a+b;
            cost+=sum;
            
            pq.push(sum);
        }
        
        return cost;// code here
    }
