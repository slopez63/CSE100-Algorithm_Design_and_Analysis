
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node
{
    int freq;
		char character;
		string binary;
    Node *left;        // Pointer to the left child node
    Node *right;    // Pointer to the right child node
		Node *root;
};

void printBinary(Node *root, string output, char character) {
	Node *tmpRoot = new Node();
	tmpRoot = root;
	tmpRoot->binary = output;

		if((tmpRoot->left == NULL) && (tmpRoot->right == NULL)) {

				if(tmpRoot->character == character) {
					cout << tmpRoot->character << ":" << tmpRoot->binary <<endl;
				}

		} else {
			tmpRoot->left->binary = output.append("0");
			output.erase(output.end() - 1);
			tmpRoot->right->binary = output.append("1");
			output.erase(output.end() - 1);
			printBinary(tmpRoot->left, output.append("0"), character);
			output.erase(output.end() - 1);
			printBinary(tmpRoot->right, output.append("1"), character);
			output.erase(output.end() - 1);
		}

}

void printFinalResult(Node root){
	printBinary(&root,"",'A');
	printBinary(&root,"",'B');
	printBinary(&root,"",'C');
	printBinary(&root,"",'D');
	printBinary(&root,"",'E');
	printBinary(&root,"",'F');
}

Node extractMin(vector<Node> &NodeQueue){
	int val = INT_MAX;
	vector<Node>::iterator i;
	vector<Node>::iterator j;

	for(i = NodeQueue.begin(); i != NodeQueue.end(); i++){
		if(val > (*i).freq){
			j = i;
			val = (*i).freq;
		}
	}

	Node temp = (*j);
	NodeQueue.erase(j);
	return temp;
}

Node Huffman(vector<Node> &NodeQueue){
	for(int i = 0; i < 5; i++){
		Node *z = new Node();
		Node *x = new Node();
		Node *y = new Node();

		*x = extractMin(NodeQueue);
	  *y = extractMin(NodeQueue);

		z->left = x;
		z->left->binary = z->left->binary + "0";
		z->right = y;
		z->right->binary = z->right->binary + "1";
		z->freq = x->freq + y->freq;
		NodeQueue.push_back(*z);

	}

	return NodeQueue[0];
}



int main(int argc, char const *argv[]) {

	int input;
	vector<Node> NodeQueue;

	for (int i = 0; i < 6; i++) {
		cin >> input;

		Node temp;

		temp.freq = input;
		temp.character = 'A' + i;
		temp.left = NULL;
		temp.right = NULL;

		NodeQueue.push_back(temp);
	}

	Node finalTree = Huffman(NodeQueue);

	printFinalResult(finalTree);

  return 0;
}
