#include <iostream>

using namespace std;

int partition(int A[], int p, int r){

  int x = A[r];
  int i = p-1;

  for(int j = p; j <= r-1; j++){

    if(A[j]<=x){
      i++;
      swap(A[i],A[j]);
    }

  }
  swap(A[i+1], A[r]);
  return (i+1);
}


//
int randomizedPartition(int A[], int p, int r){
  int i = p + rand() % (r-p + 1);
  swap(A[r], A[i]);
  return partition(A, p, r);

}


//main sort function iterates the whole tree recursively
void randomizedQuickSort(int A[], int p, int r){

  if (p < r){
    int q = randomizedPartition(A, p, r);
    randomizedQuickSort(A, p, q-1);
    randomizedQuickSort(A, q+1, r);
  }

}


int main(int argc,char **argv) {
  //Initialize variables and array

    int arraySize = 0;

    cin >> arraySize;

    int Arr[arraySize];

    //insert values to array

    for(int s = 1; s <= arraySize; s++){
        cin >> Arr[s];
      }

    randomizedQuickSort(Arr, 1, arraySize);

    //print sorted array

    for(int f = 1; f <= arraySize; f++){
      cout << Arr[f] << ";";
    }


      return 0;
}
