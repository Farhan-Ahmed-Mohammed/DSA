class Solution {
public:
    int solve(int index,int buy,vector<int> &prices,vector<vector<int>> &dp)
    {
        if(index==prices.size())
        {
            return 0;
        }

        if(dp[index][buy]!=-1)
        {
            return dp[index][buy];
        }

        int profit=0;
        if(buy==1)
        {
            int buykaro=-prices[index]+solve(index+1,0,prices,dp);
            int skipkaro=0+solve(index+1,1,prices,dp);
            profit=max(skipkaro,buykaro);
        }

        else
        {
            int sellkaro=prices[index]+solve(index+1,1,prices,dp);
            int skipkaro=0+solve(index+1,0,prices,dp);
            profit=max(skipkaro,sellkaro);
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return solve(0,1,prices,dp);
        
    }
};
