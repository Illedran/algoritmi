#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "./graph.h"


void breadth_first_search(const std::vector<node> &graph, int source) {
  std::queue<int> frontier;
  frontier.push(source);
  graph[source].visited = true;
  graph[source].dist = 0;
  while (!frontier.empty()) {
    int u = frontier.front();
    frontier.pop();
    graph[u].visited = true;
    for (int v : graph[u].neighbors) {
      if (!graph[v].visited) {
        graph[v].visited = true;
        graph[v].dist = graph[u].dist + 1;
        frontier.push(v);
      }
    }
  }
}

int calc_num(const std::vector<node> &graph,
             int source,
             int destination,
             int length,
             int &numcammini) {
  if (source == destination && length == 0) {
    return 1;
  }
  if (source != destination && length == 0) {
    return 0;
  }
  int return_value = 0;
  for (int v : graph[source].neighbors) {
    return_value += calc_num(graph, v, destination, length - 1, numcammini);
  }
  return return_value;
}

void num_min_paths(const std::vector<node> &grafo,
                   int source,
                   int destination,
                   std::ofstream &out) {

  // Used to calculate the length of path from source to destination.
  breadth_first_search(grafo, source);

  int min_length = grafo[destination].dist;
  out << min_length << " "
      << calc_num(grafo, source, destination, min_length, min_length);
}

/*
 * N nodes, M edges
 * source is the index of the source node
 * destination is the index of the destination node
 * Input format:
 * N M source destination
 * <list of edges>
 * Returns the number of paths of minimal length from source to destination
 */

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");

  int N, M, source, destination;
  in >> N >> M >> source >> destination;
  std::vector<node> graph(N);
  for (int i = 0; i < M; i++) {
    int vid_from, vid_to;
    in >> vid_from >> vid_to;
    graph[vid_from].neighbors.push_back(vid_to);
  }
  num_min_paths(graph, source, destination, out);
  out.close();
  in.close();
  return 0;
}
