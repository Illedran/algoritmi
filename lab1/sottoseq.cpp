#include <fstream>
#include <vector>

using namespace std;

int maxsum(vector<int> intvec){
    int maxval = 0;
    int here = 0;
    for(int el: intvec){
        here = max(here + el, 0);
        maxval = max(here, maxval);
    }
    return maxval;
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
    out << maxsum(intvec);
    return 0;
}

