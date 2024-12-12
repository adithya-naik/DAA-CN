#include <stdio.h>

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void bfs(int v) {
    // Mark the starting node as visited
    visited[v] = 1;
    q[++r] = v; // Add the starting node to the queue

    while (f <= r) {
        int current = q[f++];  // Dequeue the front element from the queue

        // Explore all adjacent vertices
        for (i = 1; i <= n; i++) {
            if (a[current][i] && !visited[i]) {
                q[++r] = i;  // Enqueue the unvisited adjacent node
                visited[i] = 1; // Mark it as visited
            }
        }
    }
}

int main() {
    int v;

    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

    // Initialize the queue and visited array
    for (i = 1; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }

    // Input the graph as an adjacency matrix
    printf("\nEnter graph data in matrix form (0 or 1 for each pair of vertices):\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input the starting vertex for BFS
    printf("\nEnter the starting vertex: ");
    scanf("%d", &v);

    // Perform BFS starting from vertex v
    bfs(v);

    // Output the nodes that are reachable from the starting vertex
    printf("\nThe nodes that are reachable from vertex %d are:\n", v);
    for (i = 1; i <= n; i++) {
        if (visited[i]) {
            printf("%d\t", i);  // Print the reachable nodes
        }
    }

    return 0;
}


/*
Enter the number of vertices: 4

Enter graph data in matrix form (0 or 1 for each pair of vertices):
0 1 0 0
1 0 1 0
0 1 0 1
0 0 1 0

Enter the starting vertex: 1
The nodes that are reachable from vertex 1 are:
1    2    3    4
*/
