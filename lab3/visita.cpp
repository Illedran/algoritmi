#include <fstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct nodo{
  vector<int> vic;
  bool visited;
};

vector<nodo> grafo;


int dfs(vector<nodo>& grafo, int S){
    stack<int> Q;
    Q.push(S);
    grafo[S].visited=true;
    while(!Q.empty()){
        int u  = Q.top();
        Q.pop();
        grafo[u].visited=true;
        for(int v: grafo[u].vic){
            if (grafo[v].visited==false){
                grafo[v].visited=true;
                Q.push(v);
            }
        }
    }
    int visnum=0;
    for(nodo n: grafo){
        visnum+=n.visited;
        n.visited=false;
    }
    return visnum;
}

int bfs(vector<nodo>& grafo, int S){
    queue<int> Q;
    Q.push(S);
    grafo[S].visited=true;
    while(!Q.empty()){
        int u  = Q.front();
        Q.pop();
        grafo[u].visited=true;
        for(int v: grafo[u].vic){
            if (grafo[v].visited==false){
                grafo[v].visited=true;
                Q.push(v);
            }
        }
    }
    int visnum=0;
    for(nodo n: grafo){
        visnum+=n.visited;
        n.visited=false;
    }
    return visnum;
}

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int N,M,S;
  in>>N>>M>>S;
  grafo.resize(N);
  for(int i=0;i<M;i++){
    int from, to;
    in>>from>>to;
    grafo[from].vic.push_back(to);
  }
  out << dfs(grafo, S);
  return 0;
}
