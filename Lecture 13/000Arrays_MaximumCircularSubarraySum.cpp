#include<iostream>

using namespace std;

int maximumCircularSubarraySum(int arr[], int n) {

	int x = arr[0]; 
	int y = arr[0];
	int sum = arr[0];

	int max_sum = x; // assume x[0] is the maximum subarray sum
	int min_sum = y; // assume y[0] is the minimum subarray sum

	for(int i=1; i<=n-1; i++) {
		x = max(x+arr[i], arr[i]);
		max_sum = max(max_sum, x);

		y = min(y+arr[i], arr[i]);
		min_sum = min(min_sum, y);

		sum += arr[i];
	}

	return sum == min_sum ? max_sum : max(max_sum, sum-min_sum);

}

int main() {

	// int arr[] = {-1, -2, -3, 1, 2, 3};
	int arr[] = {-1, -2, -3, -4, -5, -6};
	int n = sizeof(arr) / sizeof(int);

	cout << maximumCircularSubarraySum(arr, n) << endl;
 	
	return 0;
}