// constraints : n <= 100

#include<iostream>

using namespace std;

// Approach 3 - time : O(n) space : O(n)

// int maximumSubarraySum(int arr[], int n) {

// 	int X[100]; // based on constraints


// 	X[0] = arr[0];
// 	int maxSum = X[0];
// 	for(int i=1; i<=n-1; i++) {
// 		X[i] = max(X[i-1]+arr[i], arr[i]);
// 		maxSum = max(maxSum, X[i]);
// 	}

// 	// int maxSum = INT_MIN;
// 	// for(int i=0; i<n; i++) {
// 	// 	maxSum = max(maxSum, X[i]);
// 	// }

// 	return maxSum;

// }

// Approach 4 - time : O(n) space : O(1)

int maximumSubarraySum(int arr[], int n) {

	int X = arr[0];
	int maxSum = X;
	for(int i=1; i<=n-1; i++) {
		X = max(X+arr[i], arr[i]);
		maxSum = max(maxSum, X);
	}

	return maxSum;

}

int main() {

	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumSubarraySum(arr, n) << endl;

	return 0;
}