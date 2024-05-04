#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

void input_graph() {
    printf("Enter the number of cities: ");
    scanf("%d", &n);
    int i;
    int j;

    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++) {
        printf("Enter costs for city %d: ", i + 1);
        for (j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int current_city, int visited_cities) {
    if (visited_cities == ((1 << n) - 1)) {
        return graph[current_city][0];
    }

    int min_cost = 999999;
	int i; 
    for (i = 0; i < n; i++) {
        if (!(visited_cities & (1 << i))) {
            
            visited_cities |= (1 << i);
            int cost = graph[current_city][i] + tsp(i, visited_cities);
            min_cost = min(min_cost, cost);
            visited_cities &= ~(1 << i); 
        }
    }
    return min_cost;
}

int main() {
    input_graph();
    int i;
    for (i = 0; i < MAX; i++) {
        visited[i] = 0;
    }
    visited[0] = 1; 
    int min_path_cost = tsp(0, 1);
    printf("Minimum cost of the Travelling Salesman Problem is: %d\n", min_path_cost);
    return 0;
}
