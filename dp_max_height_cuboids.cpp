class Solution {
public:
bool check(vector<int> base,vector<int> newBox)
{
    if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<=base[2])
    {
        return true;
    }//here 0 means width 1 means length and 2 is height

    else
    {
        return false;
    }
}
int solveTab(int n,vector<vector<int>>& arr)
{
  vector<int> currRow(n+1,0);
  vector<int> nextRow(n+1,0);

  for(int curr=n-1;curr>=0;curr--)
    {
      for(int prev=curr-1;prev>=-1;prev--)
        {
           int include=0;
           if(prev==-1 || check(arr[curr],arr[prev]))
           {
              include=arr[curr][2]+nextRow[curr+1];
           }

          int exclude=0+nextRow[prev+1];
          currRow[prev+1]=max(include,exclude);
        }
        nextRow=currRow;
    }
  return nextRow[0];
}
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
    int maxHeight(vector<vector<int>>& cuboids) {
        //step 1 sort all cuboids 
        for(auto &a:cuboids)
        {
            sort(a.begin(),a.end());
        }

        //step 2: sort all cuboids basis of width or lenght
        sort(cuboids.begin(),cuboids.end());

        return solveTab(cuboids.size(),cuboids);


        
    }
};
