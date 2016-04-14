#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include "./graph.h"


void print(std::stack<int> S) {
  while (!S.empty()) {
    std::cout << S.top() << " ";
    S.pop();
  }
  std::cout << std::endl;
}

// Top sort depth-first search
void tsdfs(std::vector<node> &graph, int node_id, std::stack<int> &S) {
  graph[node_id].visited = true;
  for (int v: graph[node_id].neighbors) {
    if (!graph[v].visited) {
      graph[v].visited = true;
      tsdfs(graph, v, S);
    }
  }
  S.push(node_id);
}

std::stack<int> topSort(std::vector<node> &graph, int N, std::ofstream &out) {
  for (int i = 0; i < N; i++) {
    graph[i].visited = false;
  }
  std::stack<int> topological_order;
  for (int i = 0; i < N; i++) {
    if (!graph[i].visited) {
      tsdfs(graph, i, topological_order);
    }
  }
  return topological_order;
}

// N nodes, M edges
// Input format:
// N M
// <list of edges>

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");
  int N, M;
  in >> N >> M;
  std::vector<node> graph(N);
  for (int i = 0; i < M; i++) {
    int from, to;
    in >> from >> to;
    graph[from].neighbors.push_back(to);
  }
  std::stack<int> topological_order = topSort(graph, N, out);
  while (!topological_order.empty()) {
    out << topological_order.top() << " ";
    topological_order.pop();
  }
  out.close();
  in.close();
  return 0;
}
