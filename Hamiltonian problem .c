#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int graph[MAX][MAX];
int path[MAX];
int vertices;
bool visited[MAX];

void input_graph() {
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);
    int i;
    int j;

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < vertices; i++) {
        printf("Enter adjacency for vertex %d: ", i + 1);
        for (j = 0; j < vertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void print_path() {
    printf("Hamiltonian Cycle: ");
    int i;
    for (i = 0; i < vertices; i++) {
        printf("%d ", path[i] + 1);
    }
    printf("%d\n", path[0] + 1); 
}

bool is_valid(int v, int pos) {
    if (!graph[path[pos - 1]][v]) 
        return false;
        int i;

    for (i = 0; i < pos; i++) {
        if (path[i] == v) 
            return false;
    }
    return true;
}

bool hamiltonian_cycle_util(int pos) {
    if (pos == vertices) {
        
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    int v;
    for (v = 1; v < vertices; v++) {
        if (is_valid(v, pos)) {
            path[pos] = v;
            if (hamiltonian_cycle_util(pos + 1) == true)
                return true;
            path[pos] = -1; 
        }
    }
    return false;
}

bool hamiltonian_cycle() {
	int i;
    for (i = 0; i < vertices; i++)
        path[i] = -1; 

    path[0] = 0; 
    if (hamiltonian_cycle_util(1) == false) {
        printf("No Hamiltonian Cycle exists\n");
        return false;
    }

    print_path();
    return true;
}

int main() {
    input_graph();
    hamiltonian_cycle();
    return 0;
}
