// constrains : n <= 100

#include<iostream>

using namespace std;

int main() {

	int arr[] = {1, 6, 5, 2, 4, 3};
	int n = sizeof(arr) / sizeof(int);

	int csum = 0;

	int freq[100] = {};
	freq[0] = 1;

	// time : n computations

	for(int i=0; i<n; i++) {
		csum += arr[i];
		freq[((csum%n)+n)%n]++;
	}

	// for(int i=0; i<n; i++) {
	// 	cout << freq[i] << " ";
	// }

	int total = 0; // tracks the no. of good subarrays

	// time : n computations

	for(int i=0; i<n; i++) {
		int x_i = freq[i];
		if(x_i >= 2) {
			total += x_i*(x_i-1)/2;
		}
	}

	cout << total << endl;

	// total numComputations = n+n = 2.n ~ O(n)

	// total space = n (due to freq[]) ~ O(n)

	// cout << -17%3 << endl;

	return 0;
}