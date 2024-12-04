#include <stdio.h>
#include <limits.h>
#define INF INT_MAX
#define MAX 100

// Function to implement Dijkstra's algorithm
void dijkstra(int graph[MAX][MAX], int n, int src)
{
  int dist[MAX], visited[MAX] = {0}, parent[MAX];

  // Step 1: Initialize distances and parent array
  for (int i = 0; i < n; i++)
  {
    dist[i] = INF;
    parent[i] = -1;
  }
  dist[src] = 0;

  // Step 2: Find the shortest path
  for (int count = 0; count < n - 1; count++)
  {
    int minDist = INF, u = -1;

    // Find the vertex with the smallest distance
    for (int v = 0; v < n; v++)
    {
      if (!visited[v] && dist[v] < minDist)
      {
        minDist = dist[v];
        u = v;
      }
    }

    visited[u] = 1; // Mark the vertex as visited

    // Update the distances for adjacent vertices
    for (int v = 0; v < n; v++)
    {
      if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
      {
        dist[v] = dist[u] + graph[u][v];
        parent[v] = u;
      }
    }
  }

  // Step 3: Print the results
  printf("Vertex\tDistance\tPath\n");
  for (int i = 0; i < n; i++)
  {
    printf("%d\t%d\t\t", i, dist[i]);
    for (int v = i; v != -1; v = parent[v])
    {
      printf("%d ", v);
    }
    printf("\n");
  }
}

void main()
{
  int graph[MAX][MAX], n, src;

  // Input number of vertices
  printf("Enter the number of vertices: ");
  scanf("%d", &n);

  // Input graph as adjacency matrix
  printf("Enter the adjacency matrix:\n");
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      scanf("%d", &graph[i][j]);
    }
  }

  // Input source vertex
  printf("Enter the source vertex: ");
  scanf("%d", &src);

  // Call Dijkstra's algorithm
  dijkstra(graph, n, src);
}
