#include<stdio.h>
#include<stdbool.h>

#define INF 9999999
#define V 5

// Graph represented as an adjacency matrix
int G[V][V] = {
    { 0, 4, 0, 8, 0 },
    { 4, 0, 3, 1, 0 },
    { 0, 3, 0, 7, 8 },
    { 8, 1, 7, 0, 3 },
    { 0, 0, 8, 3, 0 }
};

// Function to initialize the selected array
void initialize_selected(bool selected[], int n) {
    for (int i = 0; i < n; i++) {
        selected[i] = false;
    }
}

int main() {
    int edge_count = 0;  // Number of edges in the MST
    bool selected[V];    // Array to track selected vertices

    // Initialize the selected array to false
    initialize_selected(selected, V);

    // Start with the first vertex (vertex 0)
    selected[0] = true;

    // Print the header for the output
    printf("Edge : Weight\n");

    // Repeat until we have V-1 edges in the MST
    while (edge_count < V - 1) {
        int min_weight = INF;
        int u = 0, v = 0;

        // Find the minimum weight edge from the set of selected vertices
        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && G[i][j] && G[i][j] < min_weight) {
                        min_weight = G[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        // Print the edge and its weight
        printf("%d - %d : %d\n", u, v, G[u][v]);

        // Include vertex v in the set of selected vertices
        selected[v] = true;

        // Increment the number of edges in the MST
        edge_count++;
    }

    return 0;
}
