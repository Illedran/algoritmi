#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

struct nodo{
  vector<int> vic;
  bool visited;
  int dist;
};

vector<nodo> grafo;

void dfs(vector<nodo>& grafo, int S){
    queue<int> Q;
    Q.push(S);
    grafo[S].visited=true;
    grafo[S].dist=0;
    while(!Q.empty()){
        int u  = Q.front();
        Q.pop();
        grafo[u].visited=true;
        for(int v: grafo[u].vic){
            if (grafo[v].visited==false){
                grafo[v].visited=true;
                grafo[v].dist=grafo[u].dist+1;
                Q.push(v);
            }
        }
    }
}

void calc_num(vector<nodo>& grafo, int S, int T, int length, int& numcammini){
    for(int v: grafo[S].vic){
        if(length>0){
            if (v==T){
                numcammini++;
            }
            calc_num(grafo, v, T, length-1, numcammini);
        }
    }
}

void num_cammini_min(vector<nodo>& grafo, int S, int T, ofstream& out){
    dfs(grafo,S);
    int minlength = grafo[T].dist;
    int numcammini=0;
    calc_num(grafo, S, T, minlength, numcammini);
    out << minlength << " " << numcammini;
}

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int N,M,S,T;
  in>>N>>M>>S>>T;
  grafo.resize(N);
  for(int i=0;i<M;i++){
    int from, to;
    in>>from>>to;
    grafo[from].vic.push_back(to);
  }
  num_cammini_min(grafo, S, T, out);
  return 0;
}
