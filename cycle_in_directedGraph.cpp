#include<unordered_map>
#include<list>
#include<queue>
#include<vector>

bool checkCyclicDFS(int node, unordered_map<int,bool> &visited, unordered_map<int,bool> &dfsvisited, unordered_map<int,list<int>> &adj)
{
   visited[node]=true;
   dfsvisited[node]=true;

    for(auto neighbour:adj[node])
    {
        if(!visited[neighbour])
        {
            bool cycleDetect=checkCyclicDFS(neighbour,visited,dfsvisited,adj);
            if(cycleDetect)
            {
                return true;
            }
        }

        else if(dfsvisited[neighbour])
        {
          return true;
        }
    }

        dfsvisited[node]=false;
        return false;

}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  
  unordered_map<int,list<int>> adj;
    for(int i=0;i<edges.size();i++)
    {
       int u=edges[i].first;
       int v=edges[i].second;
       
       adj[u].push_back(v);
       
    }  // Write your code here.

    
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            bool ans=checkCyclicDFS(i,visited,dfsvisited,adj);

            if(ans==1)
            {
                return true;
            }
        }
    }
    return false;
  // Write your code here.
}


