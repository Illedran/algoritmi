#include <fstream>
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

void print(const std::vector<std::vector<int>> &T, int C) {
  for (int j = 0; j <= C; j++) {
    std::cout << T[0][j] << " ";
  }
  std::cout << std::endl;
  for (int j = 0; j <= C; j++) {
    std::cout << T[1][j] << " ";
  }
  std::cout << std::endl;
}


// P weight, V values
int zaino(const std::vector<int> &P,
          const std::vector<int> &V,
          int i,
          int c,
          std::vector<std::vector<int>> &T,
          int idx) {
  if (c < 0) {
    return INT_MIN;
  }
  if ((i == 0) || (c == 0)) {
    return 0;
  }
  if (T[idx][c] == -1) {
    T[idx][c] = std::max(zaino(P, V, i - 1, c, T, 0),
                         zaino(P, V, i - 1, c - P[i - 1], T, 0) + V[i - 1]);
  }
  return T[idx][c];
}

int main() {
  int C, N;
  std::ifstream in("input.txt");
  in >> C >> N;
  std::vector<std::vector<int>> T(2, std::vector<int>(C + 1, -1));
  std::vector<int> P(N);
  std::vector<int> V(N);
  for (int i = 0; i < N; i++) {
    in >> P[i] >> V[i];
  }
  std::ofstream out("output.txt");
  out << zaino(P, V, N, C, T, 1) << std::endl;
  print(T, C);
  out.close();
  in.close();
  return 0;
}


