class Solution {
  public:
  int solveMem(vector<int> &arr,int curr,int prev,vector<vector<int>> &dp)
  {
      if(curr==arr.size())
      {
          return 0;
      }
      
      if(dp[curr][prev+1]!=-1)
      {
          return dp[curr][prev+1];
      }
      int include=0;
      if(prev==-1||arr[curr]>arr[prev])
      {
          include=1+solveMem(arr,curr+1,curr,dp);//curr move farward and prev bcms curr
      }
      
      int exclude=0+solveMem(arr,curr+1,prev,dp);//here prev bcms same
      return dp[curr][prev+1]=max(include,exclude);
      
  }

// int solveTab(int n,int arr[])
// {
//   vector<int> currRow(n+1,0);
//   vector<int> nextRow(n+1,0);

//   for(int curr=n-1;curr>=0;curr--)
//     {
//       for(int prev=curr-1;prev>=-1;prev--)
//         {
//            int include=0;
//            if(prev==-1 || arr[curr]>arr[prev])
//            {
//               include=1+nextRow[curr+1];
//            }

//           int exclude=0+nextRow[prev+1];
//           currRow[prev+1]=max(include,exclude);
//         }
//         nextRow=currRow;
//     }
//   return nextRow[0];
// }
     
    int lis(vector<int>& arr) {
        int n=arr.size();
       vector<vector<int>> dp(n,vector<int> (n+1,-1));
       return solveMem(arr,0,-1,dp);
        
    }
};
