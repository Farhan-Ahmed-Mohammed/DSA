 int solveMem(int dice,int faces,int target,vector<vector<int>> &dp)
    {
        //base case
        if(target<0)
        {
            return 0;
        }
        
        if(dice==0 && target!=0)
        {
            return 0;
        }
        
        if(dice!=0 && target==0)
        {
            return 0;
        }
        
        if(dice==0 && target==0)
        {
            return 1;
        }
        
        if(dp[dice][target]!=-1)
        {
            return dp[dice][target];
        }
        
        int ans=0;
        for(int i=1;i<=faces;i++)
        {
            ans=ans+solveMem(dice-1,faces,target-i,dp);
        }
        
        return dp[dice][target]=ans;
        
        
    }
    int noOfWays(int m, int n, int x) {
       vector<vector<int>> dp(n+1,vector<int>(x+1,-1));
       return solveMem(n,m,x,dp);
    }
