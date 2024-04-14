#include <stdio.h>

#define INF 99999
#define MAX_NODES 100

void floydWarshall(int graph[MAX_NODES][MAX_NODES], int nodes) {
    int dist[MAX_NODES][MAX_NODES];
    int i, j, k;

    
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    
    for (k = 0; k < nodes; k++) {
        for (i = 0; i < nodes; i++) {
            for (j = 0; j < nodes; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    
    printf("Shortest distances between every pair of vertices:\n");
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            if (dist[i][j] == INF)
                printf("INF ");
            else
                printf("%d   ", dist[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[MAX_NODES][MAX_NODES];
    int nodes, edges, i, j, u, v, w;

    printf("Enter the number of nodes: ");
    scanf("%d", &nodes);

    
    for (i = 0; i < nodes; i++) {
        for (j = 0; j < nodes; j++) {
            graph[i][j] = INF;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    
    for (i = 0; i < edges; i++) {
        printf("Enter edge %d (source, destination, weight): ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    
    floydWarshall(graph, nodes);

    return 0;
}
