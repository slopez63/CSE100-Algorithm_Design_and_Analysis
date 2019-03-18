#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int> A[], int numberVectors, int k){

  vector<int> *fvectors;
  fvectors = new vector<int>[numberVectors];

  int C[4] = {0};

  for(int i = 0; i < numberVectors; i++){
    C[A[i][k]%4] = C[A[i][k]%4] + 1;
  }

  for(int j = 1; j < 4; j++){
    C[j] = C[j] + C[j-1];
  }

  for(int i = numberVectors - 1; i >= 0; i--){
    fvectors[C[A[i][k]%4] - 1] = A[i];
    C[A[i][k]%4] = C[A[i][k]%4] - 1;
  }

  for(int j = 0; j < numberVectors; j++){
    A[j] = fvectors[j];
  }

}

void radixSort(vector<int> A[], int numberVectors){
  int s = 10;
  for(int i = s - 1; i >= 0; i--){
    countingSort(A, numberVectors, i);
  }
}


int main(int argc, char const *argv[]) {
  int numberVectors, tmp;

  cin >> numberVectors;

  vector<int> *A;

  A = new vector<int>[numberVectors];

  for(int i = 0; i < numberVectors; i++){
    for(int j = 0; j < 10; j++){
      cin >> tmp;
      A[i].push_back(tmp);
    }
  }

  radixSort(A, numberVectors);

  for(int i = 0; i < numberVectors; i++){
    vector<int>::iterator it = A[i].begin();
    while(it != A[i].end()){
      cout << *it << ";";
      it++;
    }
    cout << endl;
  }


  return 0;
}
