#include<iostream>

using namespace std;

bool isSorted(int*x, int n, int i) {

	// base case

	if (i == n - 1) {
		// check if x[n-1...n-1] is sorted
		return true;
	}

	// recursive case

	// check if x[i...n-1] is sorted

	return x[i] <= x[i + 1] and isSorted(x, n, i + 1);

}

int main() {

	int x[] = {10, 20, 30, 50, 40};
	int n = sizeof(x) / sizeof(int);

	isSorted(x, n, 0) ? cout << "x[] is sorted" << endl :
	                         cout << "x[] is not sorted" << endl;

	return 0;
}