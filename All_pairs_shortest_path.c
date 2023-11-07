#include<stdio.h>
#define v 4
#define inf 999999

void printsol(int dist[][v])
{
    for (int i =0 ;i<v ;i++)
    {
        for (int j=0;j<v;j++)
        {
            if (dist[i][j] == inf)
                printf("%5s","INF");
            else
                printf("%5d",dist[i][j]);
        }
        printf("\n");
    }
}

void floydwarshall(int dist[][v])
{
    int i,j,k;
    
    for(k=0;k<v;k++)
    {
        for(j=0;j<v;j++)
        {
            for (i=0;i<v;i++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    
    printsol(dist);
}

int main()
{
    int graph[v][v] = {
                        {0,5,inf,10},
                        {inf,0,3,4},
                        {inf,inf,0,1},
                        {inf,inf,inf,0}
                      };
    floydwarshall(graph);
    return 0;
}

