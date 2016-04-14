#include <iostream>
#include <fstream>
#include <vector>

// Used for optimizations of edge cases.
long long int simple = 0;

void printvals(const std::vector<std::vector<bool>> &A, int N) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << A[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void print(const std::vector<long long int> &A, int N) {
  for (long long int i = 0; i < N; i++) {
    std::cout << '[' << i << ']' << A[i] << " ";
  }
  std::cout << std::endl;
}

long long int sequences(long long int X,
                        int N,
                        const std::vector<std::vector<bool>> &vals,
                        const std::vector<long long int> &cons,
                        const std::vector<long long int> &last) {
  long long int count = N;
  long long int size = 1;
  std::vector<std::vector<long long int>>
      ending_sequences(2, std::vector<long long int>(N, 1));
  int idx = 1;
  for (long long int i = 0; i < N; i++) {
    ending_sequences[idx][i] = 0;
  }
  if (simple != N) {
    while (count < X) {
      /*
      std::cout << size << std::endl;
      print(ending_sequences[1-idx], N);
      std::cout << "tot=" << count << std::endl;
      */
      for (long long int i = 0; i < N; i++) {
        //std::cout << cons[i] << std::endl;
        if (cons[i] == N - 1) {
          ending_sequences[idx][last[i]] += ending_sequences[1 - idx][i];
          count += ending_sequences[1 - idx][i];
        } else {
          for (long long int j = 0; j < N; j++) {
            if (!vals[i][j]) {
              ending_sequences[idx][j] += ending_sequences[1 - idx][i];
              count += ending_sequences[1 - idx][i];
            }
          }
        }
      }
      for (long long int i = 0; i < N; i++) {
        ending_sequences[1 - idx][i] = 0;
      }
      idx = 1 - idx;
      size++;
    }
    /*
    std::cout << size << std::endl;
    print(ending_sequences[1-idx], N);
    std::cout << "tot=" << count << std::endl;
    */
  } else {
    size = X / N + 1;
  }
  return size;
}

/*
 * Read kraken.pdf for info.
 * Solved with dynamic programming.
 */

int main() {
  std::ifstream in("input.txt");
  long long int X;
  int N;
  in >> X >> N;
  std::vector<std::vector<bool>> vals(N, std::vector<bool>(N, false));
  std::vector<long long int> cons(N);
  std::vector<long long int> last(N, 0);
  long long int b;

  // Optimizations for edge cases.
  for (long long int i = 0; i < N; i++) {
    in >> cons[i];
    //std::cout << cons[i] << std::endl;
    if (cons[i] == N - 1) {
      simple++;
    }
    for (long long int j = 0; j < cons[i]; j++) {
      in >> b;
      vals[i][b] = true;
      if (last[i] == b) {
        last[i] = b + 1;
      }
    }
    //std::cout << last[i] << std::endl;
  }
  //std::cout << simple << std::endl;

  //print(poss, N);
  std::ofstream out("output.txt");
  //printvals(vals, N);
  out << sequences(X, N, vals, cons, last);
  return 0;
}