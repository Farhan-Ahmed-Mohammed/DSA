class Solution {
  public:
  bool solveMem(int index,vector<int> &arr,int n,int target,vector<vector<int>> &dp)
  {
      //base case
      if(index>=n)
      {
          return 0;
      }
      
      if(target<0)
      {
          return 0;
      }
      
      if(target==0)
      {
          return 1;
      }
      
      if(dp[index][target]!=-1)
      {
          return dp[index][target];
      }
      
      bool incl=solveMem(index+1,arr,n,target-arr[index],dp);
      bool excl=solveMem(index+1,arr,n,target-0,dp);
      
      return dp[index][target]=incl or excl;
  }
    bool equalPartition(vector<int>& arr) {
        int n=arr.size();
        int total=0;
        for(int i=0;i<n;i++)
        {
            total+=arr[i];
        }
        
        if(total%2!=0)
        {
            return 0;
        }
        
        int target=total/2;
        
        vector<vector<int>> dp(n,vector<int>(target+1,-1));
        return solveMem(0,arr,n,target,dp);
        
    }
};
