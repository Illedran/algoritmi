#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
#include <utility>

void print(const std::vector<int>& A) {
  for (int v: A) {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}

int left(int i) {
  return 2 * i + 1;
}

int right(int i) {
  return 2 * i + 2;
}

void maxHeapRestore(std::vector<int> &A, int idx, int dim) {
  int max = idx;
  if (left(idx) < dim && A[left(idx)] > A[max]) {
    max = left(idx);
  }
  if (right(idx) < dim && A[right(idx)] > A[max]) {
    max = right(idx);
  }
  if (idx != max) {
    int tmp = A[max];
    A[max] = A[idx];
    A[idx] = tmp;
    maxHeapRestore(A, max, dim);
  }
}

void heapBuild(std::vector<int> &A, int dim) {
  for (int i = floor(dim / 2); i >= 0; i--) {
    maxHeapRestore(A, i, dim);
  }
}

void heapsort(std::vector<int> &A, int dim) {
  heapBuild(A, dim);
  for (int i = dim - 1; i >= 1; i--) {
    std::swap(A[0],A[i]);
    maxHeapRestore(A, 0, i - 1);
  }
}

/*
 * Heapsort
 * N is the number of integers in the file
 * Input format:
 * N
 * <list of integers separated by a blank character>
 * Outputs the sorted array.
 */
int main() {
  std::ifstream in("input.txt");
  std::ofstream out("output.txt");
  int N;
  in >> N;
  std::vector<int> list_of_integers(N);
  for (int i = 0; i < N; i++) {
    in >> list_of_integers[i];
  }
  //print(list_of_integers);
  heapsort(list_of_integers, N);
  //print(list_of_integers);
  for (int i = 0; i < N; i++) {
    out << list_of_integers[i] << " ";
  }
  return 0;
}

