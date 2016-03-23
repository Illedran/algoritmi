#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

void print_sudoku(vector<vector<int>> M, int N) {
    int sq_size = int(sqrt(N));
    for (int i = 0; i < N; i++) {
        ostringstream row;
        for (int j = 0; j < N; j++) {
            if (j % sq_size == 0 && j != 0) {
                row << "| ";
            }
            row << setw(to_string(N).length()) << M[i][j];
            row << " ";
        }
        if (i % sq_size == 0 && i != 0) {
            ostringstream dashrow;
            for (int x = 0; x < row.str().length() - 1; x++) {
                dashrow << "-";
            }
            cout << dashrow.str() << endl;
        }
        cout << row.str() << endl;
    }
}

vector<int> get_choices(vector<vector<int>> &M, int N, int i, int j) {
    vector<int> choices(N);
    for (int r = 1; r <= N; r++) {
        choices[r - 1] = r;
    }
    int sq_size = int(sqrt(N));
    for (int m = 0; m < N; m++) {
        if (M[i][m] != 0) {
            choices[M[i][m] - 1] = 0;
        }
    }
    for (int n = 0; n < N; n++) {
        if (M[n][j] != 0) {
            choices[M[n][j] - 1] = 0;
        }
    }
    int m = i / sq_size;
    int n = j / sq_size;
    for (int x = sq_size * m; x < sq_size * (m + 1); x++) {
        for (int y = sq_size * n; y < sq_size * (n + 1); y++) {
            if (M[x][y] != 0) {
                choices[M[x][y] - 1] = 0;
            }
        }
    }
    //random_shuffle(choices.begin(),choices.end());
    return choices;
}


bool solve_sudoku_wrap(vector<vector<int>> &M, const vector<vector<bool>> &given, int N, int i, int j) {
    if (!given[i][j]) {
        vector<int> choices = get_choices(M, N, i, j);
        bool res = false;
        for (int x = 0; x < N && !res; x++) {
            if (choices[x] != 0) {
                M[i][j] = choices[x];
//                print_sudoku(M, N);
//                cout << endl;
                if ((j == N - 1) && (i < N - 1)) {
                    res = solve_sudoku_wrap(M, given, N, i + 1, 0);
                } else if (j < N - 1) {
                    res = solve_sudoku_wrap(M, given, N, i, j + 1);
                }
                if ((i == N - 1) && (j == N - 1)) {
                    return true;
                }
                if (!res) {
                    M[i][j] = 0;
                }
            }
        }
        return res;
    } else {
        if ((j == N - 1) && (i < N - 1)) {
            return solve_sudoku_wrap(M, given, N, i + 1, 0);
        } else if (j < N - 1) {
            return solve_sudoku_wrap(M, given, N, i, j + 1);
        }
        if ((i == N - 1) && (j == N - 1)) {
            return true;
        }
    }
}


void solve_sudoku(vector<vector<int>> &M, vector<vector<bool>> &given, int N) {
    solve_sudoku_wrap(M, given, N, 0, 0);
}


int main() {
    srand(time(NULL));
    int N = 9;
    vector<vector<int>> M(N, vector<int>(N, 0));
    vector<vector<bool>> given(N, vector<bool>(N, false));
    M[1][5]=3;
    M[1][7]=8;
    M[1][8]=5;
    M[2][2]=1;
    M[2][4]=2;
    M[3][3]=5;
    M[3][5]=7;
    M[4][2]=4;
    M[4][6]=1;
    M[5][1]=9;
    M[6][0]=5;
    M[6][7]=7;
    M[6][8]=3;
    M[7][2]=2;
    M[7][4]=1;
    M[8][4]=4;

    given[1][5]=true;
    given[1][7]=true;
    given[1][8]=true;
    given[2][2]=true;
    given[2][4]=true;
    given[3][3]=true;
    given[3][5]=true;
    given[4][2]=true;
    given[4][6]=true;
    given[5][1]=true;
    given[6][0]=true;
    given[6][7]=true;
    given[6][8]=true;
    given[7][2]=true;
    given[7][4]=true;
    given[8][4]=true;
    cout << "Input sudoku: " << endl;
    print_sudoku(M, N);
    solve_sudoku(M, given, N);
    cout << "Result sudoku: " << endl;
    print_sudoku(M, N);
    return 0;
}