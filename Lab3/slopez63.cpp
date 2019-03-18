#include <iostream>

using namespace std;

int maxSub(int arr[],int n){
    
    if(n==1){
        return arr[0];
    }
    
    int m = n/2;
    int left_arr = maxSub(arr,m);
    int right_arr = maxSub(arr+m,n-m);
    int leftsum = INT_MIN;
    int rightsum = INT_MIN;
    int sum=0;
    
    for(int i = m; i < n; i++){
        sum += arr[i];
        rightsum = max(rightsum, sum);
    }
    sum = 0;
    
    for(int i = (m-1);i >= 0; i--){
        sum += arr[i];
        leftsum = max(leftsum, sum);
    }
    
    int ans = max(left_arr, right_arr);
    return max(ans, leftsum+rightsum);
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

 int sum = maxSub(Arr, arraySize);

  //Print sorted array

  cout << sum;


  return 0;

}
