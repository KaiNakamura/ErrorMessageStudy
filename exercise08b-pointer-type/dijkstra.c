#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 9 // Number of vertices in the graph

int minDistance(int dist[], bool sptSet[]) {
  int min = INT_MAX, min_index;

  for (int v = 0; v < V; v++) {
    if (sptSet[v] == false && dist[v] <= min) {
      min = dist[v], min_index = v;
    }
  }

  return min_index;
}

void dijkstra(int graph[V][V], int source, int dist[]) {
  // The shortest path tree (SPT)
  // sptSet[i] will be true if vertex i is included in
  // shortest path tree or shortest distance from src to i is
  bool sptSet[V];

  // Initialize distances from source to all vertices as infinite
  for (int i = 0; i < V; i++) {
    dist[i] = INT_MAX, sptSet[i] = false;
  }
  dist[source] = 0;

  // Find shortest path for all vertices
  for (int i = 0; i < V - 1; i++) {
    int u = minDistance(dist, sptSet);

    sptSet[u] = true;

    for (int v = 0; v < V; v++) {
      if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
          dist[u] + graph[u][v] < dist[v]) {
        dist[v] = dist[u] + graph[u][v];
      }
    }
  }
}

void printDistances(int dist[], int size) {
  printf("Vertex\tDistance from Source\n");
  for (int i = 0; i < size; i++) {
    printf("%d\t%d\n", i, dist[i]);
  }
}

int main() {
  int graph[V][V] = {
      {0, 4, 0, 0, 0, 0, 0, 8, 0},  {4, 0, 8, 0, 0, 0, 0, 11, 0},
      {0, 8, 0, 7, 0, 4, 0, 0, 2},  {0, 0, 7, 0, 9, 14, 0, 0, 0},
      {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0},
      {0, 0, 0, 0, 0, 2, 0, 1, 6},  {8, 11, 0, 0, 0, 0, 1, 0, 7},
      {0, 0, 2, 0, 0, 0, 6, 7, 0}};
  int source = 0;
  int dist[V];

  dijkstra(graph, source, dist);
  printDistances(&dist, V);

  return 0;
}