#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int max(int i, int j){
  if(i > j){
    return i;
  }else{
    return j;
  }
}

void cutRod(int p[], int n, int s[], int r[]){
  r[0] = 0;
  for(int j = 1; j <= n; j++){
    int q = INT_MIN;
    for(int i = 1; i <= j; i++){
      if(q < (p[i] + r[j-i])){
        q = p[i] + r[j-i];
        s[j] = i;
      }
    }
    r[j] = q;
  }
}

void printCut(int Arr[], int n, int s[], int r[]){

  cutRod(Arr, n, s, r);

  cout << r[n] << endl;

  while(n > 0){
    cout << s[n] << " ";
    n = n - s[n];
  }

  cout << "-1" << endl;
}

int main(int argc, char const *argv[]) {
  int size;
  int bestRev;

  cin >> size;

  int s[size+1];
  int r[size+1];


  int Arr[size+1];

  for(int i = 1; i <= size+1; i++){
    cin >> Arr[i];
  }

  printCut(Arr, size, s, r);


  return 0;
}
