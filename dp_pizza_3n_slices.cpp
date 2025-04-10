class Solution {
public:
    int solveMem(int index,int endIndex,vector<int> &slices,int n,vector<vector<int>> &dp)
    {
        if(n==0||index>endIndex)
        {
            return 0;
        }

        if(dp[index][n]!=-1)
        {
            return dp[index][n];
        }

        int include=slices[index]+solveMem(index+2,endIndex,slices,n-1,dp);//here we took first one so move to index+2 bcoz we cannot take index+1 and n-1 bcoz we took one so reduce it 
        int exclude=0+solveMem(index+1,endIndex,slices,n,dp);
        return dp[index][n]=max(include,exclude);

    }
    int maxSizeSlices(vector<int>& slices) {
        int k=slices.size();
        vector<vector<int>> dp1(k,vector<int> (k,-1));
        int case1=solveMem(0,k-2,slices,k/3,dp1);//here first we take so no need last so move till k-2 only
        vector<vector<int>> dp2(k,vector<int> (k,-1));
        int case2=solveMem(1,k-1,slices,k/3,dp2);
        return max(case1,case2);
        
    }
};
