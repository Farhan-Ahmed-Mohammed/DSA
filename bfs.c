#include<stdio.h>
#include"queue.h"  // it is user define so we are writing it in double quotes
#define max 100    // if int max we can change it so use #define

void bfs(int start,int vertices,int graph[max][max])
{
    int visited[max]={0};   // means we are marking all the elements in visited as 0 initially
    initQueue();

     visited[start]=1;
    enqueue(start);

    while(!isEmpty())
    {
        int current=dequeue();
        printf("%d\n",current);

        for(int i=0;i<vertices;i++)
        {
            if(graph[current][i]==1 && visited[i]!=1)
            {
                visited[i]=1;
                enqueue(i);
            }
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

    bfs(0,vertices,graph);

    
}
