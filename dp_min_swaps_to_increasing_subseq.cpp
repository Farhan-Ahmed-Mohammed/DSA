class Solution {
public:
    int solveMem(vector<int>& nums1,vector<int>& nums2,int index,bool swapped,vector<vector<int>> &dp)
    {
        if(index==nums1.size())
        {
            return 0;
        }

        if(dp[index][swapped]!=-1)
        {
            return dp[index][swapped];
        }
        int ans=INT_MAX;

        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        if(swapped==1)
        {
            swap(prev1,prev2);//we are not swapping in main vectors to save space and time we just increase count if swap condition is met and we swap variables prev1&2
        }
        //if not swapped
        if(nums1[index]>prev1 && nums2[index]>prev2)
        {
            ans=solveMem(nums1,nums2,index+1,0,dp);//0 bcoz not swapped here
        }
        //swapping
        if(nums1[index]>prev2 && nums2[index]>prev1)
        {
            ans=min(ans,1+solveMem(nums1,nums2,index+1,1,dp));
        }

        return dp[index][swapped]=ans;

    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);
        bool swapped=0;
        bool swap=0;
        int n=nums1.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));//here 2 for 0 or 1 so 2 columns for bool swapped 0 or 1
        return solveMem(nums1,nums2,1,swapped,dp);
        
    }
};
