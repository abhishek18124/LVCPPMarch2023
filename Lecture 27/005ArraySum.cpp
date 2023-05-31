#include<iostream>

using namespace std;

int f(int* X, int n, int i) {

	// base case

	// if (i == n - 1) {
	// 	// compute the sum(X[n-1...n-1]) = sum({X[n-1]})
	// 	return X[n - 1]; // or X[i]
	// }

	if (i == n) {
		// compute sum(X[n...n-1]) = sum(empty subarray)
		return 0;
	}

	// recursive case

	// compute the sum(X[i...n-1])

	// 1. ask your friend to compute sum(X[i+1...n-1])

	int A = f(X, n, i + 1);

	return X[i] + A;

}

int main() {

	int X[] = {10, 20, 30, 40, 50};
	int n = sizeof(X) / sizeof(int);

	cout << f(X, n, 0) << endl;

	return 0;
}