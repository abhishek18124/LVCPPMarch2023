// n < 10

#include<iostream>

using namespace std;

void f(int n, int i, char* out, int j) {

	// base case
	if (i == n) { // or j == n
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// take decisions for the remaining coins [i...n-1]

	// make a decision for the ith coin

	// 1. ith coin shows 'H'

	if (i == 0 || out[i - 1] != 'H') {
		out[j] = 'H';
		f(n, i + 1, out, j + 1);
	}

	// 2. ith coin shows 'T'
	out[j] = 'T';
	f(n, i + 1, out, j + 1);

}

int main() {

	int n = 3;

	char out[10];

	f(n, 0, out, 0);

	return 0;
}