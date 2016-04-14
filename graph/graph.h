#ifndef GRAPH_GRAPH_H_
#define GRAPH_GRAPH_H_

#include <vector>

// A graph is a vector of nodes.

struct node {

  // Each node stores the indices of its neighbors
  std::vector<int> neighbors;

  // Used in algorithms.
  bool visited;
  int dist;
};


#endif  // GRAPH_GRAPH_H_
