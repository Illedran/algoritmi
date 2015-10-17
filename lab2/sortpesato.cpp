#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/*
void print(vector<int>& array, int costo){
    for(int c: array){
        cout << c << " ";
    }
    cout << "-- Costo: " << costo << endl;
}
*/
int retidx(vector<int>& array, int val){
  return distance(array.begin(), find(array.begin(), array.end(), val));
}


void swap(vector<int>& array, int idx1, int idx2){
    int tmp = array[idx1];
    array[idx1]=array[idx2];
    array[idx2]=tmp;
}

int weightsort_c(vector<int> array, int& passi){
  int i=0;
  int costo=0;
  int validx, idx;
  while(i < array.size()){
    int j=i;
    if (array[j]!=j+1){
        // search the index of element with value j+1
        idx=retidx(array, j+1);
        while(array[j]!=j+1){
            validx = retidx(array, idx+1);
            costo+=array[idx]+array[validx];
            swap(array, idx, validx);
            idx=validx;
            passi++;
       }
    }
    i++;
  }
  return costo;
}

int weightsort_i(vector<int> array){
    int i=0;
    int costo=0;
    int validx, idx;
    //print(array, costo);
    while(i < array.size()){
        int j=i;
        if (array[j]!=j+1){
            // search the index of element with value j+1
            idx=retidx(array, j+1);
            int origidx=idx;
            if(i>0){
                // cout << "Using 1 to solve cycles..." << endl;
                swap(array,0,idx);
                costo+=array[0]+array[idx];
                //print(array, costo);
            }
            while(array[j]!=j+1){
                validx = retidx(array, idx+1);
                costo+=array[idx]+array[validx];
                swap(array, idx, validx);
                idx=validx;
                //print(array, costo);
            }            
        }
        i++;
    }
    return costo;
}

int main(){
  ifstream in("input.txt");
  ofstream out("output.txt");
  int N;
  in>>N;
  vector<int> myarr (N);
  for(int i=0; i<N; i++){
    in>>myarr[i];
    // cout<<myarr[i]<<" ";
  }
  // cout << endl;
  int passi=0;
  int costo_c = weightsort_c(myarr, passi);
  int costo_i = weightsort_i(myarr);
  //cout << costo_c << " " << costo_i << endl;
  out << passi << " " << min(costo_c,costo_i);
}
