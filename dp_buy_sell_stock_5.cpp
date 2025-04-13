class Solution {
public:
     int solve(int index,int buy,vector<int> &prices,vector<vector<int>> &dp,int fee)
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
            int buykaro=-prices[index]+solve(index+1,0,prices,dp,fee);
            int skipkaro=0+solve(index+1,1,prices,dp,fee);
            profit=max(skipkaro,buykaro);
        }

        else
        {
            int sellkaro=-fee+prices[index]+solve(index+1,1,prices,dp,fee);
            int skipkaro=0+solve(index+1,0,prices,dp,fee);
            profit=max(skipkaro,sellkaro);
        }
        return dp[index][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        return solve(0,1,prices,dp,fee);
        
    }
};
