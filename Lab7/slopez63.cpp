
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int key_value;    // Key value of the node
    Node *left;        // Pointer to the left child node
    Node *right;    // Pointer to the right child node
    Node *parent;   // Pointer to the parent node
    
};

class BTree
{
    
public:
    
    Node *root;
    
    void updateRoot(Node *x){
        root = x;
    }
    
    BTree(){
        updateRoot(NULL);
    }
    
    void transplant(Node *u, Node *v){
        if(u->parent == NULL){
            updateRoot(v);
        }else if(u == u->parent->left){
            u->parent->left = v;
        }else{
            u->parent->right = v;
        }
        
        if(v != NULL){
            v->parent = u->parent;
        }
    }
    
    Node* treeMinimum(Node *x){
        while(x->left != NULL){
            x = x->left;
        }
        return x;
    }
    
    void btInsert(Node *z){
        
        Node *x = root;
        Node *y = NULL;
        
        while(x != NULL){
            y = x;
            if(z->key_value < x->key_value){
                x = x->left;
            }else{
                x = x->right;
            }
        }
        
        z->parent = y;
        
        if(y == NULL){
            updateRoot(z);
        }else if(z->key_value < y->key_value){
            y->left = z;
        }else{
            y->right = z;
        }
        
    }
    
    void btDelete(Node *z){
        if(z->left == NULL){
            transplant(z, z->right);
        }else if(z->right == NULL){
            transplant(z, z->left);
        }else{
            Node *y = treeMinimum(z->right);
            
            if(y->parent != z){
                transplant(y, y->right);
                y->right = z->right;
                y->right->parent = y;
            }
            transplant(z, y);
            y->left = z->left;
            y->left->parent = y;
        }
        
    }
    
    void printInOrder(Node *x){
        if(x != NULL){
            printInOrder(x->left);
            cout << x->key_value << endl;
            printInOrder(x->right);
        }
    }
    
    void printPreOrder(Node *x){
        if(x != NULL){
            cout << x->key_value << endl;
            printPreOrder(x->left);
            printPreOrder(x->right);
        }
    }
    
    void printPostOrder(Node *x){
        if(x != NULL){
            
            printPostOrder(x->left);
            printPostOrder(x->right);
            cout << x->key_value << endl;
           
        }
    }
    
    Node* search(Node *x, int k){
        if(x == NULL || k == x->key_value){
            return x;
        }
        if(k < x->key_value){
            return search(x->left, k);
        }else{
            return search(x->right, k);
        }
    }
    
};

int main(int argc, char const *argv[]) {
  int number = 0;
  string input = "";
  BTree tree;

  do{
      number = 0;
      cin >> input;

      //Create integer if required by function call
      if (input[0] == 'd' || input[0] == 'i'){
        for (int i = 1; i < input.size(); i++){
          int digit = input[i] - '0';
          number = 10 * number + digit;
        }
      }
      
      
      //Check inputs and exit when done
      if(input[0] == 'i'){
          Node *x = new Node;
          x->key_value = number;
          x->left = NULL;
          x->right = NULL;
          x->parent = NULL;
          tree.btInsert(x);
      }else if(input[0] == 'd'){
          Node *x = tree.search(tree.root, number);
          tree.btDelete(x);
      }else if(input == "oin"){
          tree.printInOrder(tree.root);
      }else if(input == "opost"){
          tree.printPostOrder(tree.root);
      }else if(input == "opre"){
          tree.printPreOrder(tree.root);
      }else if(input == "e"){
          return 0;
      }else{
        cout << "Wrong input" << endl;
      }

    }while(input[0] != 'e');

  return 0;
}


