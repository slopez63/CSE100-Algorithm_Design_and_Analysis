
#include <iostream>
#include <climits>
using namespace std;

void printParenthesis(int i, int j, int n, int *s) {

	if (i == j) {
		cout << 'A' << i-1;
	} else {
		cout << "(";
		printParenthesis(i, *((s + (i*n)) + j), n, s);
		printParenthesis(*((s + (i*n)) + j) + 1, j, n, s);
		cout << ")";
	}

}

void matrixChainOrder(int p[], int n) {

	int m[n][n];
	int s[n][n];

	for (int i = 1; i < n; i++) {
		m[i][i] = 0;
	}

	for (int l = 2; l < n; l++) {
		for (int i = 1; i < n - l + 1; i++) {
			int j = i + l - 1;
			m[i][j] = INT_MAX;

			for (int k = i; k <= j - 1; k++) {
				int q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}

	cout << m[1][n - 1] << endl;

	printParenthesis(1, n - 1, n, (int *)s);
    
    cout << endl;


}


int main(int argc, char const *argv[]) {

	int n;

	cin >> n;

	int arr[n + 1];
	int input;

	for (int i = 0; i <= n; i++) {

		cin >> input;
		arr[i] = input;

	}

	int size = sizeof(arr) / sizeof(arr[0]);

	matrixChainOrder(arr, size);

  return 0;
}


