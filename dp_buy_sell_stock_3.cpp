class Solution {
public:
     int solve(int index,int buy,vector<int> &prices,int limit,
     vector<vector<vector<int>>> &dp)
    {
        if(index==prices.size())
        {
            return 0;
        }

        if(limit==0)
        {
            return 0;
        }

        if(dp[index][buy][limit]!=-1)
        {
            return dp[index][buy][limit];
        }

       

        int profit=0;
        if(buy==1)
        {
            int buykaro=-prices[index]+solve(index+1,0,prices,limit,dp);
            int skipkaro=0+solve(index+1,1,prices,limit,dp);
            profit=max(skipkaro,buykaro);
        }

        else
        {
            int sellkaro=prices[index]+solve(index+1,1,prices,limit-1,dp);
            int skipkaro=0+solve(index+1,0,prices,limit,dp);
            profit=max(skipkaro,sellkaro);
        }
        return dp[index][buy][limit]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int> (3,-1)));
        return solve(0,1,prices,2,dp);
        
    }
};
