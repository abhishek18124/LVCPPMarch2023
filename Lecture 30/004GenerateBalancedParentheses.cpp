// n <= 8

#include<iostream>

using namespace std;

/*

	x : no. of opening brackets you've used
	y : no. of closing brackets you've used

*/

void f(int n, int x, int y, char* out, int j) {

	// base case
	if (j == 2 * n) { // x == n and y == n
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	// recursive case

	// make a decision for the jth index of out[]

	// 1. assign '(' to the jth index of out[]
	if (x < n) {
		out[j] = '(';
		f(n, x + 1, y, out, j + 1);
	}

	// 2. assign ')' to the jth index of out[]
	if (y < x) {
		out[j] = ')';
		f(n, x, y + 1, out, j + 1);
	}

}

int main() {

	int n = 3;

	char out[20];

	f(n, 0, 0, out, 0);

	return 0;
}