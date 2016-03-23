#include <fstream>
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print(vector<vector<int>> T, int C){
    for(int j=0; j<=C; j++) {
        cout << T[0][j] << " ";
    }
    cout << endl;
    for(int j=0; j<=C; j++) {
        cout << T[1][j] << " ";
    }
    cout << endl;
}


// P pesi e V valori
int zaino(vector<int>& P, vector<int>& V, int i, int c, vector<vector<int>>& T, int idx){
    if (c < 0) {
        return INT_MIN;
    }
    if ((i == 0) || (c == 0)) {
        return 0;
    }
    if (T[idx][c] == -1) {
        /*
        cout << "Going over item " << i << endl;
        int z1 = ;
        cout << "Max value for " << c << " when not taking item " << i << " is " << z1 << endl;
        int z2 =  + V[i-1];
        cout << "Max value for " << c << " when taking item " << i << " is " << z2 << endl;
        */
        //cout << "Setting T[" << c << "] to max(" << zaino(P, V, i-1, c, T, 0) << ", " << zaino(P, V, i-1, c - P[i-1], T, 0) << " + " << V[i-1] << ")" << endl;
        T[idx][c] = max(zaino(P, V, i-1, c, T, 0), zaino(P, V, i-1, c - P[i-1], T, 0) + V[i-1]);
        //cout << "Setting T[" << c << "] to max(" << zaino(P, V, i-1, c, T) << ", " << zaino(P, V, i-1, c - P[i-1], T) << " + " << V[i-1] << ")" << endl;
    }
    return T[idx][c];
}

int main() {
    int C, N;
    ifstream in ("input.txt");
    //cout << INT_MIN;
    in >> C >> N;
    capa = C;
    vector<vector<int>> T (2, vector<int>(C+1, -1));
    vector<int> P (N);
    vector<int> V (N);
    for(int i=0; i<N; i++) {
        in >> P[i] >> V[i];
    }
    ofstream out ("output.txt");
    out << zaino(P, V, N, C, T, 1) << endl;
    print(T, C);
    out.close();
    in.close();
    return 0;
}


