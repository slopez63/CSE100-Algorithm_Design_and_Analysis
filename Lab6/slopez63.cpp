#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

int hashFunction(int k, int m){
  return k % m;
}

void hashInsert(vector < list<int> > &hashTable, int x, int m){
  hashTable[hashFunction(x,m)].push_front(x);
}

void hashDelete(vector < list<int> > &hashTable, int x, int m){
  int index = 0;
  for (list<int>::iterator element = hashTable[hashFunction(x,m)].begin(); element != hashTable[hashFunction(x,m)].end(); ++element) {
    if(*element == x){
      hashTable[hashFunction(x,m)].erase(element);
      cout << x << ":DELETED;" << endl;
      return;
    }else{
      index++;
    }
  }
  cout << x << ":DELETE_FAILED;" << endl;
}


void hashSearch(vector < list<int> > hashTable, int x, int m){

  int index = 0;
  for (list<int>::const_iterator element = hashTable[hashFunction(x,m)].begin(); element != hashTable[hashFunction(x,m)].end(); ++element) {
    if(*element == x){
      cout << x << ":FOUND_AT"<< hashFunction(x,m) << "," << index << ";" << endl;
      return;
    }else{
      index++;
    }
  }

  cout << x << ":NOT_FOUND;" << endl;

}

void hashOutput(vector < list<int> > hashTable, int m){

  int index = 0;

  for (vector< list<int> >::const_iterator helement = hashTable.begin(); helement != hashTable.end(); ++helement) {
    cout << index << ":";
    for (list<int>::const_iterator lelement = hashTable[index].begin(); lelement != hashTable[index].end(); ++lelement) {
        cout << *lelement << "->";
    }
    cout << ";" << endl;
    index++;
  }

}


int main(int argc, char const *argv[]) {

  int hashSize = 0;
  int number =  0;
  int num;
  bool repeat = true;

  string input = "";
  cin >> hashSize;

  vector<list<int> > hashTable(hashSize, list<int>());

  do{
      number = 0;
      cin >> input;
      //Create integer if required by function
      if (input[0] != 'o' || input[0] != 'e'){
        for (int i = 1; i < input.size(); i++){
          int digit = input[i] - '0';
          number = 10 * number + digit;
        }
      }

      if(input[0] == 'i'){
        hashInsert(hashTable, number, hashSize);
      }else if(input[0] == 'd'){
        hashDelete(hashTable, number, hashSize);
      }else if(input[0] == 's'){
        hashSearch(hashTable, number, hashSize);
      }else if(input[0] == 'o'){
        hashOutput(hashTable, hashSize);
      }else if(input[0] == 'e'){
        repeat = false;
      }else{
        cout << "Wrong input" << endl;
      }
  }while(repeat);

  return 0;
}
