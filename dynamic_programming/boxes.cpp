#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

void print_scatole(const std::vector<int> &M,
                   const std::vector<int> &idx,
                   const int N,
                   const std::vector<int> &x,
                   const std::vector<int> &y,
                   const std::vector<int> &z,
                   int rand_max) {
  for (int i = 0; i <= N; i++) {
    std::cout << std::setfill('0') << std::setw(1 + (int) log10(N + 1)) << i << ": ("
        << std::setw(1 + (int) log10(rand_max)) << x[i] << ", "
        << std::setw(1 + (int) log10(rand_max)) << y[i] << ", "
        << std::setw(1 + (int) log10(rand_max)) << z[i] << ")";
    std::cout << std::setfill('0') << "    M[" << std::setw(1 + (int) log10(N + 1)) << i
        << "] = " << std::setw(1 + (int) log10(N + 1)) << M[i];
    std::cout << std::setfill('0') << "    idx[" << std::setw(1 + (int) log10(N + 1)) << i
        << "] = " << std::setw(1 + (int) log10(N + 1)) << idx[i];
    std::cout << std::endl;
  }
}

int scatole(std::vector<int> &M,
            std::vector<int> &idx,
            std::vector<int> &x,
            std::vector<int> &y,
            std::vector<int> &z,
            int i) {
  if (M[i] == -1) {
    M[i] = 0;
    int candidate_max;
    for (int j = 0; j < i && x[j] < x[i] && y[j] < y[i] && z[j] < z[i]; j++) {
      candidate_max = scatole(M, idx, x, y, z, j) + 1;
      if (candidate_max > M[i]) {
        M[i] = candidate_max;
        idx[i] = j;
      }
    }
    candidate_max = scatole(M, idx, x, y, z, i - 1);
    if (candidate_max > M[i]) {
      M[i] = candidate_max;
      idx[i] = idx[i - 1];
    }
  }
  return M[i];
}

void print_which(const std::vector<int> &idx, int N) {
  for (int i = N; i > 0; i--) {
    if (idx[i - 1] != idx[i]) {
      std::cout << i << " ";
    }
  }
}

int main() {
  srand(time(NULL));
  int N = 100;
  std::vector<int> M(N + 1, -1);
  std::vector<int> idx(N + 1, -1);
  std::vector<int> x(N + 1);
  std::vector<int> y(N + 1);
  std::vector<int> z(N + 1);
  M[0] = 0;
  M[1] = 1;
  idx[1] = 0;
  x[0] = 0;
  y[0] = 0;
  z[0] = 0;
  int rand_max = 1000;

  // Using random inputs to test this one.
  for (int i = 1; i <= N; i++) {
    x[i] = rand() % (rand_max - 1) + (int) (i * log10(i)) + i + i * i;
    y[i] = rand() % (rand_max - 1) + (int) (i * log10(i)) + i + i * i;
    z[i] = rand() % (rand_max - 1) + (int) (i * log10(i)) + i + i * i;
  }
  std::cout << scatole(M, idx, x, y, z, N) << std::endl;
  print_scatole(M, idx, N, x, y, z, rand_max);
  print_which(idx, N);
  return 0;
}