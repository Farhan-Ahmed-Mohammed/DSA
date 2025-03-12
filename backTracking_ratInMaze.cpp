#include <bits/stdc++.h> 

bool isSafe(int newX,int newY,vector<vector<bool>> &vis,vector<vector<int>> &arr,int n)
{
    if((newX>=0 && newX<n) && (newY>=0 && newY<n) && (vis[newX][newY]!=1 && arr[newX][newY]==1))
    {
        return true;
    }

    else
    {
        return false;
    }
}


void solve(int x,int y,vector<vector< int >> & arr,int n,vector<string> &ans, vector<vector<bool>> &vis,string path)
{
    //base case
    if(x==n-1 && y==n-1)
    {
        ans.push_back(path);
        return ;
    }
    // move down
    if(isSafe(x+1,y,vis,arr,n))
    {
        vis[x][y]=1;
        solve(x+1,y,arr,n,ans,vis,path+'D');
        vis[x][y]=0;
    }

    // move left
    if(isSafe(x,y-1,vis,arr,n))
    {
        vis[x][y]=1;
        solve(x,y-1,arr,n,ans,vis,path+'L');
        vis[x][y]=0;
    }

    // move right
    if(isSafe(x,y+1,vis,arr,n))
    {
        vis[x][y]=1;
        solve(x,y+1,arr,n,ans,vis,path+'R');
        vis[x][y]=0;
    }

    // move up
    if(isSafe(x-1,y,vis,arr,n))
    {
        vis[x][y]=1;
        solve(x-1,y,arr,n,ans,vis,path+'U');
        vis[x][y]=0;
    }
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
   vector<string> ans;
   vector<vector<bool>> visited(n,vector<bool> (n,0));
   string path="";
   if(arr[0][0]==0)
   {
       return ans;
   }
   solve(0,0,arr,n,ans,visited,path);
   return ans;
    // Write your code here.
}
