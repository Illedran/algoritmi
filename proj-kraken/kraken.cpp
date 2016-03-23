#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

long long int simple = 0;

void printvals(vector<vector<bool>>& A, int N){
    for(int i=0; i<N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print(vector<long long int>& A, int N){
    for(long long int i=0;i<N;i++){
        cout << '[' << i << ']' << A[i] << " ";
    }
    cout << endl;
}

long long int sequenze(long long int X, int N, vector<vector<bool>>& vals, const vector<long long int>& cons, vector<long long int>& last){
    long long int count = N;
    long long int size=1;
    vector<vector<long long int>> seq_terminanti (2, vector<long long int> (N, 1));
    int idx=1;
    for(long long int i=0; i<N; i++){
        seq_terminanti[idx][i] = 0;
    }
    if(simple!=N) {
        while (count < X) {
            /*
            cout << size << endl;
            print(seq_terminanti[1-idx], N);
            cout << "tot=" << count << endl;
            */
            for (long long int i = 0; i < N; i++){
                //cout << cons[i] << endl;
                if(cons[i]==N-1) {
                    seq_terminanti[idx][last[i]] += seq_terminanti[1 - idx][i];
                    count+=seq_terminanti[1 - idx][i];
                } else {
                    for (long long int j = 0; j < N; j++) {
                        if (vals[i][j] == false) {
                            seq_terminanti[idx][j] += seq_terminanti[1 - idx][i];
                            count += seq_terminanti[1 - idx][i];
                        }
                    }
                }
            }
            for (long long int i = 0; i < N; i++) {
                seq_terminanti[1 - idx][i] = 0;
            }
            idx = 1 - idx;
            size++;
        }
        /*
        cout << size << endl;
        print(seq_terminanti[1-idx], N);
        cout << "tot=" << count << endl;
        */
    } else {
        size = X/N + 1;
    }
    return size;
}


int main() {
    ifstream in ("input.txt");
    long long int X;
    int N;
    in >> X >> N;
    vector<vector<bool>> vals (N, vector<bool> (N, false));
    vector<long long int> cons (N);
    vector<long long int> last (N,0);
    long long int b;
    for(long long int i=0; i<N; i++){
        in >> cons[i];
        //cout << cons[i] << endl;
        if(cons[i]==N-1){
            simple++;
        }
        for(long long int j=0; j<cons[i]; j++){
            in >> b;
            vals[i][b] = true;
            if(last[i]==b) {
                last[i] = b + 1;
            }
        }
        //cout << last[i] << endl;
    }
    //cout << simple << endl;
    //print(poss, N);
    ofstream out ("output.txt");
    //printvals(vals, N);
    out << sequenze(X, N, vals, cons, last);
    return 0;
}