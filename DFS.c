#include <stdio.h>

void DFS(int);

int G[10][10], visited[10], n;

void main() {
    int i, j;
    
    // Input the number of vertices
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Read the adjacency matrix
    printf("\nEnter adjacency matrix of the graph:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &G[i][j]);

    // Initialize visited array to 0 (not visited)
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Start DFS traversal from vertex 0
    DFS(0);
}

void DFS(int i) {
    int j;

    // Print the current vertex
    printf("\n%d", i);
    
    // Mark the vertex as visited
    visited[i] = 1;

    // Explore all the adjacent vertices
    for (j = 0; j < n; j++) {
        if (!visited[j] && G[i][j] == 1) {
            DFS(j);  // Recursively visit the unvisited adjacent vertices
        }
    }
}
/*
Enter number of vertices: 4

Enter adjacency matrix of the graph:
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0


0
1
2
3

*/
