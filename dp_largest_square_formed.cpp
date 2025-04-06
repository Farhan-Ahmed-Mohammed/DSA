class Solution {
  public:
  int solveMem(vector<vector<int>>& mat,int i,int j,int &maxi,vector<vector<int>> &dp)
  {
      //base case
      if(i>=mat.size()||j>=mat[i].size())
      {
          return 0;
      }
      
      if(dp[i][j]!=-1)
      {
          return dp[i][j];
      }
      
      int right=solveMem(mat,i,j+1,maxi,dp);
      int diagonal=solveMem(mat,i+1,j+1,maxi,dp);
      int down=solveMem(mat,i+1,j,maxi,dp);
      
      if(mat[i][j]==1)
      {
          dp[i][j]=1+min(right,min(diagonal,down));
          maxi=max(dp[i][j],maxi);
          return dp[i][j];
      }
      
      else
      {
          return dp[i][j]=0;
      }
  }
    int maxSquare(vector<vector<int>>& mat) {
        int maxi=0;
        vector<vector<int>> dp(mat.size(),vector<int> (mat[0].size(),-1));
         solveMem(mat,0,0,maxi,dp);
         return maxi;
    }
};
