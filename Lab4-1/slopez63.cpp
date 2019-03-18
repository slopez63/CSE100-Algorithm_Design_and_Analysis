
#include <iostream>

using namespace std;

//Functions to get index

int left(int i){
  return 2*i;
}

int right(int i){
  return 2*i + 1;
}


//sort heap
void maxHeapify(int A[], int i, int arraySize){

  int largest;

  int l = left(i);
  int r = right(i);

  if(l <= arraySize && A[l] > A[i]){
    largest = l;
  }else{
    largest = i;
  }

  if(r <= arraySize && A[r] > A[largest]){
    largest = r;
  }

  if(largest != i){
    swap(A[i], A[largest]);
    maxHeapify(A, largest, arraySize);
  }
}


//create heap tree
void buildMaxHeap(int A[],int arraySize){

  for (int i = arraySize/2; i >= 1; i--){
    maxHeapify(A,i, arraySize);
  }
}


//main sort function iterates the whole tree recursively
void heapSort(int A[], int arraySize){

  buildMaxHeap(A, arraySize);

  for(int i = arraySize; i >= 2; i--){

    swap(A[1], A[i]);

    maxHeapify(A,1,i-1);
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

    heapSort(Arr, arraySize);

    //print sorted array

    for(int f = 1; f <= arraySize; f++){
      cout << Arr[f] << ";";
    }


      return 0;
}
