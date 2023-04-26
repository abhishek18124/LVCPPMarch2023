// contraints : n <= 100, k <= 9

#include<iostream>

using namespace std;

int main() {	

	int arr[] = {1, 0, 3, 2, 3, 1, 2, 0, 2};
	int n = sizeof(arr) / sizeof(int);
	
	int k = 3; // denotes the maximum element in the array

	int freq[10]; // based on the contraints

	memset(freq, 0, sizeof(freq));

	for(int i=0; i<n; i++) {
		freq[arr[i]]++;
	}

	for(int i=0; i<=k; i++) {
		cout << freq[i] << " ";
	}

	cout << endl;

	// // non-stable version

	// for(int i=0; i<=k; i++) {
	// 	int j = freq[i];
	// 	// the element 'i' has occurred 'j' times in the input
	// 	for(int ii=0; ii<j; ii++) {
	// 		cout << i << " ";	
	// 	}
	// }

	// cout << endl;

	// stable version

	for(int i=1; i<=k; i++) {
		freq[i] += freq[i-1];
	}

	for(int i=0; i<=k; i++) {
		cout << freq[i] << " ";
	}

	cout << endl;

	for(int i=k; i>=1; i--) {
		freq[i] = freq[i-1];
	}

	freq[0] = 0; // starting position of 0 is the 0th index

	for(int i=0; i<=k; i++) {
		cout << freq[i] << " ";
	}

	cout << endl;

	int out[100]; // based on the contraints

	for(int i=0; i<n; i++) {
		out[freq[arr[i]]++] = arr[i];
	}

	for(int i=0; i<n; i++) {
		cout << out[i] << " ";
	}

	cout << endl;

	return 0;
}