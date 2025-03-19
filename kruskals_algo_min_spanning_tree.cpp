#include<list>
#include<unordered_map>
#include<vector>
#include<algorithm>
void makeSet(vector<int> &parent,vector<int> &rank,int n)
{
  for(int i=0;i<n;i++)
  {
    parent[i]=i;
    rank[i]=0;
  }
}

int findParent(vector<int> &parent,int node)
{
  if(parent[node]==node)
  {
    return node;
  }
  return parent[node]=findParent(parent,parent[node]); //recursive call tillwe reach top node i.e parent node where parent is it self
}

void unionSet(int u,int v,vector<int> &parent,vector<int> &rank)
{
  u=findParent(parent,u);
  v=findParent(parent,v);

  if(rank[v]<rank[u])
  {
    parent[v]=u;
  }

  else if(rank[v]>rank[u])
    {
      parent[u]=v;
    }

    else
    {
      parent[v]=u;
      rank[u]++;
    }
  }

bool cmp(vector<int> &a,vector<int> &b)
{
  return a[2]<b[2];
}


int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  sort(edges.begin(),edges.end(),cmp);
  vector<int> parent(n);
  vector<int> rank(n);
  makeSet(parent,rank,n);
  int minwt=0;
  for(int i=0;i<edges.size();i++)
  {
    int u=findParent(parent,edges[i][0]);
    int v=findParent(parent,edges[i][1]);
    int weight=edges[i][2];
    if(u!=v)
    {
      minwt+=weight;
      unionSet(u,v,parent,rank);
    }
  }
  return minwt;
}
