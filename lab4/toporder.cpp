#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

struct nodo{
  vector<int> vic;
  bool visited;
};

vector<nodo> grafo;

void print(stack<int> S){
    while(!S.empty()){
        cout << S.top() << " ";
        S.pop();
    }
    cout << endl;
}

void tsdfs(vector<nodo>& grafo, int u, stack<int>& S){
    grafo[u].visited=true;
    for(int v: grafo[u].vic){
        if (grafo[v].visited==false){
            grafo[v].visited=true;
            tsdfs(grafo, v, S);
        }
    }
    S.push(u);
}

stack<int> topSort(vector<nodo>& grafo, int N, ofstream& out){
    for(int i=0; i<N; i++){
        grafo[i].visited=false;
    }
    stack<int> S;
    for(int i=0; i<N; i++){
        if(!grafo[i].visited){
            tsdfs(grafo, i, S);
        }
    }
    return S;
}

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int N,M;
  in>>N>>M;
  grafo.resize(N);
  for(int i=0;i<M;i++){
    int from, to;
    in>>from>>to;
    grafo[from].vic.push_back(to);
  }
  stack<int> S = topSort(grafo, N, out);
  while(!S.empty()){
        out << S.top() << " ";
        S.pop();
  }
  return 0;
}
