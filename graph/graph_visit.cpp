#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include "./graph.h"


// Depth-first search
int dfs(std::vector<node> &graph, int source) {
  std::stack<int> frontier;
  frontier.push(source);
  graph[source].visited = true;
  while (!frontier.empty()) {
    int u = frontier.top();
    frontier.pop();
    graph[u].visited = true;
    for (int v: graph[u].neighbors) {
      if (!graph[v].visited) {
        graph[v].visited = true;
        frontier.push(v);
      }
    }
  }
  int visnum = 0;
  for (node &n: graph) {
    visnum += n.visited;
    n.visited = false;
  }
  return visnum;
}

// Breadth-first search
int bfs(std::vector<node> &graph, int source) {
  std::queue<int> frontier;
  frontier.push(source);
  graph[source].visited = true;
  while (!frontier.empty()) {
    int u = frontier.front();
    frontier.pop();
    graph[u].visited = true;
    for (int v: graph[u].neighbors) {
      if (!graph[v].visited) {
        graph[v].visited = true;
        frontier.push(v);
      }
    }
  }
  int visnum = 0;
  for (node &n: graph) {
    visnum += n.visited;
    n.visited = false;
  }
  return visnum;
}

/*
 * N nodes, M edges
 * source is the index of the source node
 * Input format:
 * N M source
 * <list of edges>
 * Returns the number of visited nodes using a dfs from source
 */

int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");
  int N, M, source;
  in >> N >> M >> source;
  std::vector<node> graph(N);
  for (int i = 0; i < M; i++) {
    int from, to;
    in >> from >> to;
    graph[from].neighbors.push_back(to);
  }
  out << dfs(graph, source);
  out.close();
  in.close();
  return 0;
}
