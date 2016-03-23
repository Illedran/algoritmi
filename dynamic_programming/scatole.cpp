#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

void print_scatole(vector<int> &M, vector<int> &idx, int N, vector<int> &x, vector<int> &y, vector<int> &z, int rand_max) {
    for (int i = 0; i <= N; i++) {
        cout << setfill('0') << setw(1+(int)log10(N+1)) << i << ": (" << setw(1+(int)log10(rand_max)) << x[i] << ", " << setw(1+(int)log10(rand_max)) << y[i] << ", " << setw(1+(int)log10(rand_max)) << z[i] << ")";
        cout << setfill('0') << "    M[" << setw(1+(int)log10(N+1)) << i << "] = " << setw(1+(int)log10(N+1)) << M[i];
        cout << setfill('0') << "    idx[" << setw(1+(int)log10(N+1)) << i << "] = " << setw(1+(int)log10(N+1)) << idx[i];
        cout << endl;
    }
}

int scatole(vector<int> &M, vector<int> &idx, vector<int> &x, vector<int> &y, vector<int> &z, int i) {
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
        candidate_max = scatole(M, idx, x, y, z, i-1);
        if (candidate_max > M[i]) {
            M[i] = candidate_max;
            idx[i] = idx[i-1];
        }
    }
    return M[i];
}

void print_quali(vector<int>& idx, int N){
    for(int i=N; i>0; i--){
        if (idx[i-1]!=idx[i]){
            cout << i << " ";
        }
    }
}

int main() {
    srand(time(NULL));
    int N = 100;
    vector<int> M(N + 1, -1);
    vector<int> idx(N + 1, -1);
    vector<int> x(N + 1);
    vector<int> y(N + 1);
    vector<int> z(N + 1);
    M[0]=0; M[1]=1; idx[1]=0;
    x[0] = 0;
    y[0] = 0;
    z[0] = 0;
    int rand_max = 1000;
    for (int i = 1; i <= N; i++) {
        x[i] = rand() % (rand_max - 1) + (int)(i*log10(i))+i+i*i;
        y[i] = rand() % (rand_max - 1) + (int)(i*log10(i))+i+i*i;
        z[i] = rand() % (rand_max - 1) + (int)(i*log10(i))+i+i*i;
    }
    cout << scatole(M, idx, x, y, z, N) << endl;
    print_scatole(M, idx, N, x, y, z, rand_max);
    print_quali(idx, N);
    return 0;
}