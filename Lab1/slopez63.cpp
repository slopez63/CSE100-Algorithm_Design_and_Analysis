#include <iostream>

using namespace std;

//Used pseudocode https://en.wikipedia.org/wiki/Insertion_sort

void insertionSort(int arraySize,int* Arr){


    int i = 1;

    while(i < arraySize){
      int j = i-1;
      int tmp = Arr[i];

//Checks if two numbers are sorted and itterates array
    while (j >= 0 && Arr[j] > tmp) {
      Arr[j+1] = Arr[j];
      j--;
    }

      Arr[j+1] = tmp;
      i++;

      int x = 0;

      //print each step the search does
      while(x < i){
          cout << Arr[x] << ";";
          x++;
        }
        cout << endl;

      }

}


int main(int argc,char **argv) {

//Initialize variables and array
  int* Arr;
  int arraySize = 0;


//create array with input array size
  cin >> arraySize;

  Arr = new int[arraySize];

//Put input into an array
  for(int s = 0; s < arraySize; s++){
      cin >> Arr[s];
  }

//Initialize insertionSort
  insertionSort(arraySize,Arr);

}
