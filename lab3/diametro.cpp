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


int diameter(vector<nodo>& grafo, int nodes){
    queue<int> Q;
	vector<int> maxnode_dist (nodes, 0);
    for(int i=0;i<nodes;i++){
		Q.push(i);
		grafo[i].visited=true;
		grafo[i].dist=0;
		while(!Q.empty()){
		    int u = Q.front();
		    Q.pop();
		    grafo[u].visited=true;
		    for(int v: grafo[u].vic){
		        if (grafo[v].visited==false){
		            grafo[v].dist=grafo[u].dist+1;
		            grafo[v].visited=true;
		            Q.push(v);
		        }
		    }
		}
		for(int j=0; j<nodes; j++){
		    //cout<< grafo[j].dist << " ";
		    maxnode_dist[i]=max(maxnode_dist[i], grafo[j].dist);
		    grafo[j].visited=false;
		}
        //cout<<endl;
	}
	int maxval=0;	
	for(int i: maxnode_dist){
    	//cout << i << endl;
        maxval=max(i,maxval);
	}
	return maxval;
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
    grafo[to].vic.push_back(from);
  }
  out << diameter(grafo, N);
  return 0;
}
