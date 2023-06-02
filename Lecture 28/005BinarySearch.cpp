#include<iostream>

using namespace std;

int binarySearch(int* x, int t, int s, int e) {

	// base case
	if (s > e) {
		// search space is empty
		return -1;
	}

	// recusive case

	// search for the 't' in x[s...e]

	int m = s + (e - s) / 2;

	// if (x[m] == t) {
	// 	return m;
	// } else {
	// 	if (t > x[m]) {
	// // recusively search for the 't' in x[m+1...e]
	// return binarySearch(x, t, m + 1, e);
	// 	} else { // t < x[m]
	// 		// recusively search for the 't' in x[s...m-1]
	// 		return binarySearch(x, t, s, m - 1);
	// 	}
	// }

	if (x[m] == t) {
		return m;
	} else if (t > x[m]) {
		// recusively search for the 't' in x[m+1...e]
		return binarySearch(x, t, m + 1, e);
	} else { // t < x[m]
		// recusively search for the 't' in x[m+1...e]
		return binarySearch(x, t, m + 1, e);
	}

}

int main() {

	int x[] = {10, 20, 30, 40, 50};
	int n = sizeof(x) / sizeof(int);
	int t = 30;

	cout << binarySearch(x, t, 0, n - 1) << endl;

	return 0;
}