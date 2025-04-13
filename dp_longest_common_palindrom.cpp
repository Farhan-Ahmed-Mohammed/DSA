class Solution {
public:
    int solve(string& s,int i,int j,vector<vector<int>> &dp)
    {
        if(i>j)
        {
            return 0;
        }

        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }



        if(s.length()==1)
        {
            return 1;
        }

      
        int ans=0;

        if(i==j && s[i]==s[j])
        {
           
           return ans+1;
        }

        if(s[i]==s[j])
        {
            ans=2+solve(s,i+1,j-1,dp);
        }

        else
        {
            ans=max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
        }
        return dp[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
         int n=s.length();
        vector<vector<int>> dp(n,vector<int> (n,-1));
       
        return solve(s,0,n-1,dp);
        
    }
};
