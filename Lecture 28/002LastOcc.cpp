#include<iostream>

using namespace std;

int f(int* x, int t, int i) {

	// base case

	// if (i == 0) {
	// 	// find the idx of the last occ. of the 't' in x[0...0]
	// 	return x[0] == t ? 0 : -1;
	// }

	if (i == -1) {
		// find the idx of the last occ. of the 't' in x[0...-1] = {}
		return -1;
	}

	// recursive case

	// find the idx of the last occ. of the 't' in x[0....i]

	if (x[i] == t) {
		return i;
	}

	// recursively find the idx of the last occ. of the 't' in x[0...i-1]

	return f(x, t, i - 1);

}

int main() {

	int x[] = {10, 20, 30, 20, 30};
	int n = sizeof(x) / sizeof(int);
	int t = 30;

	cout << f(x, t, n - 1) << endl;

	return 0;
}