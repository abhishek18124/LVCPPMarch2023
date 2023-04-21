#include<iostream>

using namespace std;

// // Approach - 1 time : (n^2) space : O(1)

// int targetSumPair(int arr[], int n, int t) {

// 	int count = 0; // to track no. of pairs that sum upto target

// 	// iterate over all the possible indices for the the 1st element of the pair

// 	for(int i=0; i<=n-2; i++) {

// 		// for a given 'i', iterate over all the possible indices for the 2nd element of the pair

// 		for(int j=i+1; j<=n-1; j++) {

// 			if(arr[i]+arr[j] == t) {
// 				cout << "(" << arr[i] << ", " << arr[j] << ") ";
// 				count++;
// 			}

// 		}

// 	}

// 	return count;

// }

// Approach - 2 time : O(n) space : O(1)

int targetSumPair(int arr[], int n, int t) {

	int count = 0; // to track no. of pairs that sum upto target

	int i = 0;
	int j = n-1;

	while(i < j) {

		int s = arr[i]+arr[j];
		if(s == t) {
			// you've found a valid pair
			cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
			count++;
			i++;
			j--;
		} else if(s > t) {
			j--;
		} else { // s < t
			i++;
		}

	}

	return count;

}

int main() {	

	int arr[] = {10, 20, 30, 40, 50, 60};
	int n = sizeof(arr) / sizeof(int);
	int t = 60;

	cout << targetSumPair(arr, n, t) << endl;

	return 0;
}