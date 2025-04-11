class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        //subtrack every number with given common difference and check if any number is present before that numbre or not if present 
        unordered_map<int,int> dp;
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            int temp=arr[i]-difference;
            int tempAns=0;
            
            if(dp.count(temp))// check if temp is there in array or not 
            {
                tempAns=dp[temp];
            }
            //current ans update
            dp[arr[i]]=1+tempAns;
            ans=max(ans,dp[arr[i]]);
        }
        return ans;
    }
};
