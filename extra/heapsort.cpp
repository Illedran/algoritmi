#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

void print(vector<int> A){
    for(int v: A){
        cout << v << " ";
     }
     cout << endl;
}

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*i+2;
}

void maxHeapRestore(vector<int>& A, int idx, int dim){
    int max = idx;
    if (left(idx)<=dim && A[left(idx)] > A[max]){
        max = left(idx);
    }
    if (right(idx)<=dim && A[right(idx)] > A[max]){
        max = right(idx);
    }
    if (idx != max){
        int tmp = A[max];
        A[max]=A[idx];
        A[idx]=tmp;
        maxHeapRestore(A, max, dim);
    }
}

void heapBuild(vector<int>& A, int dim){
    for(int i=floor(dim/2); i>=0; i--){ 
        maxHeapRestore(A, i, dim);
    }
}

void heapsort(vector<int>& A, int dim){
    heapBuild(A, dim);
    for(int i=dim-1; i>=1; i--){
        int tmp = A[0];
        A[0]=A[i];
        A[i]=tmp;
        maxHeapRestore(A, 0, i-1);
    }
}

int main(){
    ifstream in("input.txt");
    int N;
    in >> N;
    vector<int> intvec(N);
    for(int i=0; i<N; i++){
        in >> intvec[i];
    }
    ofstream out("output.txt");
    //print(intvec);
    heapsort(intvec, N);
    //print(intvec);
    for(int i=0; i<N; i++){
        out << intvec[i] << " ";
     }
    return 0;
}

