#include<iostream>

using namespace std;

int f(int* X, int i) {

	// base case

	// if (i == 0) {
	// 	// compute sum(X[0...0]) = sum({X[0]})
	// 	return X[0]; // or X[i]
	// }


	if (i == -1) {
		// compute sum(X[0...-1]) = sum(empty subarray)
		return 0;
	}

	// recursive case

	// compute sum(X[0...i])

	// 1. ask your friend to compute sum(X[0...i-1])

	int A = f(X, i - 1);

	return X[i] + A;

}

int main() {

	int X[] = {10, 20, 30, 40, 50};
	int n = sizeof(X) / sizeof(int);

	cout << f(X, n - 1) << endl;

	return 0;
}