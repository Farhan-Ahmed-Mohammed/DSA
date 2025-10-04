#include <bits/stdc++.h>
int solveMem(vector<int> &weight,vector<int> &value,int index,int capacity,vector<vector<int>> &dp)
{
	if(index==0)
	{
		if(weight[0]<=capacity)
		{
			return value[0];
		}

		else
		{
			return 0;
		}
	}

	if(dp[index][capacity]!=-1)
	{
		return dp[index][capacity];
	}

	int include=0;
	if(weight[index]<=capacity)
	{
		include=value[index]+solveMem(weight,value,index-1,capacity-weight[index],dp);
	}

		int exclude=0+solveMem(weight,value,index-1,capacity,dp);
		dp[index][capacity]=max(include,exclude);
	
	
		return dp[index][capacity];
	
} 

int solve(vector<int> &wt,vector<int> &val,int n,int capacity)  // this is botto up approach tabulation
{
	vector<vector<int>> dp(n+1,vector<int>(capacity+1,0));
	
	for(int i=1;i<=n;i++)
	{
		for(int w=0;w<=capacity;w++)
		{
			if(w>=wt[i-1])
			{			
				dp[i][w]=max(dp[i-1][w],val[i-1]+dp[i-1][w-wt[i-1]]);
			}

			else
			{
				dp[i][w]=dp[i-1][w];
			}
		}
	}
	return dp[n][capacity];
}



	
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int> (maxWeight+1,-1));
	return solveMem(weight,value,n-1,maxWeight,dp);// Write your code here
}
