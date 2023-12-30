#include <stdio.h>
#define v 4
#define inf 999999

void printsolution(int dist[][v]) {
    int i, j;
    printf("The resultant adj matrix with all pairs shortest paths is:\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            if (dist[i][j] == inf)
                printf("%5s", "inf");
            else
                printf("%5d", dist[i][j]);
        }
        printf("\n");
    }
}

void floyd(int dist[][v]) {
    int i, j, k;

    for (k = 0; k < v; k++) {
        for (i = 0; i < v; i++) {
            for (j = 0; j < v; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    printsolution(dist);
}

int main() {
    int i, j;
    int graph[v][v];

    printf("Enter the adjacency matrix for the graph (%d x %d):\n", v, v);
    printf("Enter '-1' to represent infinity in the matrix:\n");
    for (i = 0; i < v; i++) {
        for (j = 0; j < v; j++) {
            scanf("%d", &graph[i][j]);
            if (graph[i][j] == -1) {
                graph[i][j] = inf;
            }
        }
    }

    floyd(graph);
    return 0;
}
// int graph[V][V] = { { 0, 5, INF, 10 },
// { INF, 0, 3, INF },
// { INF, INF, 0, 1 },
// { INF, INF, INF, 0 } };
