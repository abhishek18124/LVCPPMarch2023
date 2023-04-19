// constraints : n <= 100

#include<iostream>

using namespace std;

// Approach 2 : time - n + n^2 ~ n^2 i.e. O(n^2) space : n+1 ~ n i.e. O(n)

int maximumSubarraySum(int arr[], int n) {

	int csum[101]; // based on constraints
	csum[0] = 0;

	for(int i=1; i<=n; i++) {
		csum[i] = csum[i-1] + arr[i-1];
	}	

	// for(int i=0; i<=n; i++) {
	// 	cout << csum[i] << " ";
	// }

	// cout << endl;

	int maxSum = INT_MIN;

	int start, end;

	// iterate over all the possible starting indices for subarrays

	for(int i=0; i<=n-1; i++) {

		// for the given starting index 'i', iterate over all the possible ending indices 

		for(int j=i; j<=n-1; j++) {

			// compute the sum of the subarray that starts at the ith index and ends at the jth index i.e. arr[i...j]

			int sum = csum[j+1] - csum[i];

			// maxSum = max(maxSum, sum);

			if(sum > maxSum) {
				maxSum = sum;
				start = i;
				end = j;
			}

		}

	}

	for(int i=start; i<=end; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return maxSum;

}

int main() {

	int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumSubarraySum(arr, n) << endl;

	return 0;
}