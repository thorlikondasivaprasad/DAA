#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define inf 9999
int mindist(int dist[],int visited[]){
	int min=inf,mi=0;
	for(int i=0;i<9;i++){
		if(dist[i]<min&&!(visited[i])){
			min=dist[i];
			mi=i;
		}
	}
	return mi;
}
int main()
{
	int graph[10][10]={{0,4,inf,inf,inf,inf,inf,8,inf},
						{4,0,8,inf,inf,inf,inf,11,inf},
						{inf,8,0,7,inf,4,inf,inf,2},
						{inf,inf,7,0,9,14,inf,inf,inf},
						{inf,inf,inf,9,0,10,inf,inf,inf},
						{inf,inf,4,inf,10,0,2,inf,inf},
						{inf,inf,inf,inf,inf,2,0,1,6},
						{8,11,inf,inf,inf,inf,1,0,7},
						{inf,inf,2,inf,inf,inf,6,7,0}};
	int visited[9],dist[9],no_edge;
	memset(visited,0,9*sizeof(int));
	memset(dist,inf,9*sizeof(int));
	visited[0]=1;
	dist[0] = 0;
	while(no_edge<8){
		int u=mindist(dist,visited);
		//printf("\n %d  %d ",u,dist[u]);
		visited[u]=1;
		for (int i = 0; i < 9; i++)
		{
             if (dist[u]+graph[u][i]<dist[i] && !visited[i])
                 dist[i]=dist[u]+graph[u][i];
		}
        no_edge++;
    }
	printf("Vertex Cost\n");
	for(int i=0;i<9;i++)
	printf("%d %d\n",i+1,dist[i]);
	}

Output:

Vertex Cost

1 0

2 4

3 12

4 19

5 21

6 11

7 9

8 8

9 14

