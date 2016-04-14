#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include "./graph.h"

int diameter(std::vector<node> &graph, int nodes) {
  std::queue<int> frontier;
  std::vector<int> maxnode_dist(nodes, 0);
  for (int i = 0; i < nodes; i++) {
    frontier.push(i);
    graph[i].visited = true;
    graph[i].dist = 0;
    while (!frontier.empty()) {
      int u = frontier.front();
      frontier.pop();
      graph[u].visited = true;
      for (int v: graph[u].neighbors) {
        if (!graph[v].visited) {
          graph[v].dist = graph[u].dist + 1;
          graph[v].visited = true;
          frontier.push(v);
        }
      }
    }
    for (int j = 0; j < nodes; j++) {
      //cout<< graph[j].dist << " ";
      maxnode_dist[i] = std::max(maxnode_dist[i], graph[j].dist);
      graph[j].visited = false;
    }
    //cout<<endl;
  }
  int maxval = 0;
  for (int i: maxnode_dist) {
    //cout << i << endl;
    maxval = std::max(i, maxval);
  }
  return maxval;
}

/*
 * N nodes, M edges
 * source is the index of the source node
 * Input format:
 * N M
 * <list of edges>
 * Returns the diameter of the graph.
 * The diameter is the greatest distance between any two vertices.
 */

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");
  int N, M;
  in >> N >> M;
  std::vector<node> graph (N);
  for (int i = 0; i < M; i++) {
    int from, to;
    in >> from >> to;
    graph[from].neighbors.push_back(to);
    graph[to].neighbors.push_back(from);
  }
  out << diameter(graph, N);
  out.close();
  in.close();
  return 0;
}
