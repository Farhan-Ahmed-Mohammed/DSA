#include<algorithm>
#include<limits.h>
int solvemem(int n,int x,int y,int z,vector<int> &dp)
{
	if(n==0)
	{
		return 0;
	}

	if(n<0)
	{
		return INT_MIN;
	}

	if(dp[n]!=-1)
	{
		return dp[n];
	}
	int a=solvemem(n-x,x,y,z,dp)+1;
	int b=solvemem(n-y,x,y,z,dp)+1;
	int c=solvemem(n-z,x,y,z,dp)+1;

	dp[n]=max(a,max(b,c));
	return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	vector<int> dp(n+1,-1);
	int ans=solvemem(n,x,y,z,dp);
	if(ans<0)
	{
		return 0;
	}

	else
	{
		return ans;
	}
}
