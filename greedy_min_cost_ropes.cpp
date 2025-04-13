int minCost(vector<int>& arr) {
       
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(int i=0;i< arr.size();i++)
        {
            pq.push(arr[i]);
        }
        
        int cost=0;
        while(pq.size()>1)
        {
            int first=pq.top();
            pq.pop();
            
            int second=pq.top();
            pq.pop();
            
            int mergedLen=first+second;
            cost+=mergedLen;
            
            pq.push(mergedLen);
        }
        
        return cost;
    }
