#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int retidx(vector<int> array, int val){
  return distance(array.begin(), find(array.begin(), array.end(), val));
}


int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int N;
  in>>N;
  vector<int> myarr (N);
  for(int i=0; i<N; i++){
    in>>myarr[i];
  }
  int i=0;
  int passi=0;
  int costo=0;
  while(i<N){
    int j=i;
    if (myarr[j]!=j+1){
        // search the index of element with value j+1
        int idx=retidx(myarr, j+1);
        while(myarr[j]!=j+1){
            int tmp;
            int validx = retidx(myarr, idx+1);
            costo+=myarr[idx]+myarr[validx];
            tmp=myarr[idx];
            myarr[idx]=myarr[validx];
            myarr[validx]=tmp;
            idx=validx;
            passi++;
        }
    }
    i++;
  }
  out << passi << " " << costo;
  /*
  for(int i=0; i<N; i++){
    in>>myarr[i];
    out<<myarr[i];
  }
  */
}
