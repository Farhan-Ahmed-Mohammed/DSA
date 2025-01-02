#include<stdio.h>
#define max 100

void dfs(int current,int visited[],int graph[max][max],int vertices)
{
    printf("%d\n",current);
    visited[current]=1;

    for(int i=0;i<vertices;i++)
    {
        if(graph[current][i]==1 && visited[i]!=1)
        {
            dfs(i,visited,graph,vertices);
        }
    }
}

int main()
{
    int vertices=8;
    int graph[max][max]={
    {0,1,1,0,0,0,0,0},
    {1,0,0,1,1,0,0,0},
    {1,0,0,0,0,1,1,0},
    {0,1,0,0,0,0,0,1},
    {0,1,0,0,0,0,0,1},
    {0,0,1,0,0,0,0,1},
    {0,0,1,0,0,0,0,1},
    {0,0,0,1,1,1,1,0},
    };
    int visited[max]={0};
    dfs(0,visited,graph,vertices);

    
}
