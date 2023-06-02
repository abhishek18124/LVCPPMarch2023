#include<iostream>

using namespace std;

int f(int* x, int n, int t, int i) {

	// base case

	// if (i == n - 1) {
	// 	// find the idx of the 1st occ. of the 't' in x[n-1...n-1] = {x[n-1]}
	// 	return x[n - 1] == t ? n - 1 : -1;
	// }

	if (i == n) {
		// find the idx of the 1st occ. of the 't' in x[n...n-1] = {}
		return -1;
	}

	// recursive case

	// find the idx of the 1st occ. of the 't' in x[i...n-1]

	if (x[i] == t) {
		return i;
	}

	// recursively find the idx of the 1st occ. of the 't' in x[i+1...n-1]

	return f(x, n, t, i + 1);

}

int main() {

	int x[] = {10, 20, 30, 20, 30};
	int n = sizeof(x) / sizeof(int);
	int t = 30;

	cout << f(x, n, t, 0) << endl;

	return 0;
}