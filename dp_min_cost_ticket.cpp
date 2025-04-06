int solveMem(int n, vector<int> &days, vector<int> &cost,int index,vector<int> &dp)
{
    //base case
    if(index>=n)  //if we go to day more than reqired day that is n
    {
        return 0;
    }

    if(dp[index]!=-1)
    {
        return dp[index];
    }
    //1 day pass
    int option=cost[0]+solveMem(n,days,cost,index+1,dp);// here 1 days we have to move farward

    //7 day pass
    int i;
    for(i=index;i<n && days[i]<days[index]+7;i++);//no body just to move i to 7 days farward we use this for loop
    int option2=cost[1]+solveMem(n,days,cost,i,dp);// here i is day after 7 days as it is increased
     
    //30 days pass
     for(i=index;i<n && days[i]<days[index]+30;i++);
     int option3=cost[2]+solveMem(n,days,cost,i,dp);

     dp[index]=min(option,min(option2,option3));
     return dp[index];

}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{
    vector<int> dp(n+1,-1);
    return solveMem(n,days,cost,0,dp);
}
