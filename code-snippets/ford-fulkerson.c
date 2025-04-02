#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define V 8 // Number of vertices in the graph

bool bfs(int residualGraph[V][V], int source, int sink, int parent[]) {
  bool visited[V];
  memset(visited, 0, sizeof(visited));

  // Create a queue for BFS
  int queue[V], front = 0, rear = 0;
  queue[rear++] = source;
  visited[source] = true;
  parent[source] = -1;

  // Standard BFS loop
  while (front < rear) {
    int u = queue[front++];

    for (int v = 0; v < V; v++) {
      if (!visited[v] && residualGraph[u][v] > 0) {
        queue[rear++] = v;
        parent[v] = u;
        visited[v] = true;

        // If we reached the sink, return true
        if (v == sink) {
          return true;
        }
      }
    }
  }

  // If we didn't reach the sink, return false
  return false;
}

int fordFulkerson(int graph[V][V], int source, int sink) {
  int residualGraph[V][V];
  memcpy(residualGraph, graph, V * V * sizeof(int));

  int parent[V];   // Array to store the augmenting path
  int maxFlow = 0; // Initialize the maximum flow to 0

  // Augment the flow while there is an augmenting path
  while (bfs(residualGraph, source, sink, parent)) {
    // Find the bottleneck capacity of the augmenting path
    int pathFlow = INT_MAX;
    for (int v = sink; v != source; v = parent[v]) {
      int u = parent[v];
      if (pathFlow > residualGraph[u][v]) {
        pathFlow = residualGraph[u][v];
      }
    }

    // Update the residual capacities of the edges and reverse edges
    for (int v = sink; v != source; v = parent[v]) {
      int u = parent[v];
      residualGraph[u][v] -= pathFlow;
      residualGraph[v][u] += pathFlow;
    }

    // Add the path flow to the overall flow
    maxFlow += pathFlow;
  }

  return maxFlow;
}

int main() {
  // Capacity matrix
  int graph[V][V] = {
      {0, 6, 6, 0, 0, 0, 0, 0},  {0, 0, 0, 4, 2, 0, 0, 0},
      {0, 5, 0, 0, 9, 0, 0, 0},  {0, 0, 0, 0, 0, 4, 7, 0},
      {0, 0, 0, 8, 0, 0, 7, 0},  {0, 0, 0, 0, 0, 0, 0, 7},
      {0, 0, 0, 0, 0, 11, 0, 4}, {0, 0, 0, 0, 0, 0, 0, 0},
  };

  int source = 0, sink = 7;

  int maxFlow = fordFulkerson(graph, source, sink);
  printf("The maximum possible flow is %d\n", maxFlow);

  return 0;
}