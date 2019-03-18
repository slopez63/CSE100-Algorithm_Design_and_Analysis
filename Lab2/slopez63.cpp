#include <iostream>

using namespace std;

//Using pseudocode from book "Introduction to algorithims" pg 31-34

void merge(int A[], int p, int q, int r) {

  //Start new index
  int n1 = q - p + 1;
  int n2 = r - q;

  //Create new arrays to separate old array
  int L[n1+1], R[n2+1];

  for(int i = 0; i < n1; i++){
    L[i] = A[p+i];
  }

  for(int j = 0; j < n2; j++){
    R[j] = A[q+1+j];
  }

  //Initialize this values as final test
  L[n1] = INT_MAX;
  R[n2] = INT_MAX;

  //Initialize values for sorting the new array
  int i = 0;
  int j = 0;

  //Chech which value is larger and merge them
  for(int k = p; k <= r; k++){
    if(L[i] <= R[j]){
      A[k] = L[i];
      i++;
    }else{
      A[k] = R[j];
      j++;
    }
  }
}

void mergeSort(int A[], int p, int r){
  //check how long is the array on each recursion
  //Aka initial test
  if(p < r){
    int q = (p+r)/2;
    mergeSort(A, p, q);
    mergeSort(A, q+1, r);
    merge(A,p,q,r);
  }
}

int main(int argc,char **argv) {
  //Initialize variables and array

  int arraySize = 0;

  cin >> arraySize;

  int Arr[arraySize];

  //insert values to array

  for(int s = 0; s < arraySize; s++){
      cin >> Arr[s];
  }

  //Do sorting algorithim

  mergeSort(Arr, 0, arraySize-1);

  //Print sorted array

  for(int s = 0; s < arraySize; s++){
      cout << Arr[s] << ";";
  }


  return 0;

}
