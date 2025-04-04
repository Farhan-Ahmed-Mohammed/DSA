#define MOD 1000000007
#include<vector>
long long int solvemem(int n,vector<long long int> &dp)
{
    if(n==1)
    {
        return 0;
    }

    if(n==2)
    {
        return 1;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    dp[n]=(((n-1)%MOD) * ((solvemem(n-1,dp)%MOD)+(solvemem(n-2,dp)%MOD))%MOD);
    return dp[n];
}
long long int countDerangements(int n) {
   vector<long long int> dp(n+1,-1);
   return solvemem(n,dp);

}
