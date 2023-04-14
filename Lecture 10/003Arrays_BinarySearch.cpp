#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50, 60, 70};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	// 1. define the bounds of the search space

	int s = 0;
	int e = n-1;

	// 2. run the binary search algorithm

	while(s <= e) {
		// int m = (s+e)/2; // this can lead to integer overflow
		// int m = s+(e-s)/2;
		int m = s+((e-s)>>1) ;
		if(arr[m] == t) {
			// you've found the target at index 'm' therefore stop
			cout << t << " found at index " << m << endl;
			break;
		} else if(t > arr[m]) {
			// reduce the search space from [s, e] to [m+1, e]
			s = m+1;
		} else { // t < arr[m]
			// reduce the search space from [s, e] to [s, m-1]
			e = m-1;
		}
	}

	if(s > e) {
		// search space has become empty i.e. 't' was not found
		cout << t << " not found!" << endl;
	}

	return 0;
}