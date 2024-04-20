#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 5

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
    int v;

    for (v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex \t Distance from Source\n");
    int i;
    for (i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];
    bool sptSet[V];
    int i;

    for (i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    dist[src] = 0;
    int count;

    for (count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;
        int v;

        for (v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    printSolution(dist);
}

int main() {
    int graph[V][V];
    int i;
    int j;

    printf("Enter the adjacency matrix of the graph (%d x %d):\n", V, V);
    for ( i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the source vertex: ");
    int source;
    scanf("%d", &source);

    dijkstra(graph, source);

    return 0;
}
