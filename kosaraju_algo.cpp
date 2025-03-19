#include<unordered_map>
#include<stack>
#include<vector>
#include<list>
void dfs(int node,unordered_map<int,bool> &vis,stack<int> &st,unordered_map<int,list<int>> &adj)
{
	vis[node]=true;
	for(auto nbr:adj[node])
	{
		if(!vis[nbr])
		{
			dfs(nbr,vis,st,adj);
		}
	}
	st.push(node);
}

void revDfs(int node,unordered_map<int,bool> &vis,unordered_map<int,list<int>> &adj)
{
	vis[node]=true;
	for(auto nbr:adj[node])
	{
		if(!vis[nbr])
		{
			revDfs(nbr,vis,adj);
		}
		
	}
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	unordered_map<int,list<int>> adj;
	for(int i=0;i<edges.size();i++)
	{
		int u=edges[i][0];
		int v=edges[i][1];
		
		adj[u].push_back(v);
	}
	
	//topo	sort
	stack<int> st;
	unordered_map<int,bool> vis;
	for(int i=0;i<v;i++)
	{
		if(!vis[i])
		{
			dfs(i,vis,st,adj);
		}
	}

	//transepose graph
	unordered_map<int,list<int>> transepose;
	for(int i=0;i<v;i++)
	{
		vis[i]=0;
		for(auto nbr:adj[i])
		{
			transepose[nbr].push_back(i);
		}
	}

	int count=0;
	while(!st.empty())
	{
		int top=st.top();
		st.pop();
		if(!vis[top])
		{
			count++;
			revDfs(top,vis,transepose);
		}
	}
	return count;
}
