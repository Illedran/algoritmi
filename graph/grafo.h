#ifndef GRAPH_GRAFO_H_
#define GRAPH_GRAFO_H_

#include <vector>

struct nodo {
  std::vector<int> vic;
  bool visited;
  int dist;
};


#endif  // GRAPH_GRAFO_H_
