static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.second<b.second;
    }
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n=start.size();
        vector<pair<int,int>> v;//making array of paired elements
        
        for(int i=0;i<n;i++)
        {
            pair<int,int> p=make_pair(start[i],end[i]);
            v.push_back(p);
        }
        
        sort(v.begin(),v.end(),cmp);//,cmp means sort wrt cmp function
        
        int count=1;
        int ansEnd=v[0].second;
        
        for(int i=1;i<n;i++)
        {
            if(v[i].first>ansEnd)
            {
                count++;
                ansEnd=v[i].second;
            }
        }
        return count;
        // Your code here
    }
};
