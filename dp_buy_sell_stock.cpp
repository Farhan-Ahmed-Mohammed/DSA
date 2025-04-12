class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++)
        {
            int diff=prices[i]-mini; //subtract next values in given array with min that is first element at first and it is updated as we move farward
            profit=max(profit,diff);
            mini=min(mini,prices[i]); //keep updating mini 
        }
        return profit;
        
    }
};
