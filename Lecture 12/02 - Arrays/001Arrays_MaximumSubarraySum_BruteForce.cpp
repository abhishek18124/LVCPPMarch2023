#include<iostream>
#include<climits>

using namespace std;

// Approach 1 : time - O(n^3) space - O(1)

int maximumSubarraySum(int arr[], int n) {

	int maxSum = INT_MIN;

	// iterate over all the starting indices for subarrays

	for(int i=0; i<=n-1; i++) {

		// for the given starting index 'i', iterate over all the possible ending indices

		for(int j=i; j<=n-1; j++) {

			// compute the sum of the subarray that starts at the ith index and ends at the jth index i.e. arr[i...j]

			int sum = 0;

			for(int k=i; k<=j; k++) {
				sum += arr[k];
			}

			// maxSum = max(maxSum, sum);

			if(sum > maxSum) {
				maxSum = sum;
			}


		}

	}

	return maxSum;

}

int main() {

	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumSubarraySum(arr, n) << endl;

	return 0;
}