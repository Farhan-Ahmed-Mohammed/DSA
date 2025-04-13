 int findMinDiff(vector<int>& a, int m) {
        sort(a.begin(),a.end());
        int i=0;
        int j=m-1; //we hame m children so till m-1 bcoz zero index
        
        int mini=INT_MAX;
        while(j<a.size())
        {
            int diff=a[j]-a[i]; //in case of 3 first 3 next increase i and j 
            mini=min(mini,diff);//calculate min of all 5 5 groups
            i++;
            j++;
        }
        return mini;
    }
