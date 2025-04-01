#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define V 6 // Number of vertices in the graph
#define E 8 // Number of edges in the graph

struct Edge {
  int src, dest, weight;
};

bool bellmanFord(struct Edge edges[], int numEdges, int numVertices, int source,
                 int dist[]) {
  // Initialize distances from source to all vertices as infinite
  for (int i = 0; i < numVertices; i++) {
    dist[i] = INT_MAX;
  }
  dist[source] = 0;

  // Relax all edges |V| - 1 times
  for (int i = 1; i <= numVertices - 1; i++) {
    for (int j = 0; j < numEdges; j++) {
      int u = edges[j].src;
      int v = edges[j].dest;
      int weight = edges[j].weight;

      if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
      }
    }
  }

  // Check for negative-weight cycles
  for (int j = 0; j < numEdges; j++) {
    int u = edges[j].src;
    int v = edges[j].dest;
    int weight = edges[j].weight;

    if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
      printf("Graph contains a negative-weight cycle\n");
      return false;
    }
  }

  return true;
}

void printDistances(int dist[], int size) {
  printf("Vertex\tDistance from Source\n");
  for (int i = 0; i < size; i++) {
    printf("%d\t%d\n", i, dist[i]);
  }
}

int main() {
  struct Edge edges[E] = {{0, 1, 10}, {0, 5, 8},  {1, 3, 2},  {2, 1, 1},
                          {3, 2, -2}, {4, 1, -4}, {4, 3, -2}, {5, 4, 1}};
  int source = 0;
  int dist[V];

  if (bellmanFord(edges, E, V, source, dist)) {
    printDistances(dist, V);
  } else {
    printf("Negative-weight cycle detected!\n");
  }

  return 0;
}