// constraints : n <= 100

#include<iostream>

using namespace std;

void merge(int* arr, int s, int m, int e) {

	int i = s;
	int j = m + 1;
	int k = s;

	int crr[100]; // based on the contraints

	while (i <= m and j <= e) {

		if (arr[i] <= arr[j]) {
			crr[k] = arr[i];
			i++;
			k++;
		} else {
			crr[k] = arr[j];
			j++;
			k++;
		}

	}

	while (i <= m) {
		crr[k] = arr[i];
		i++;
		k++;
	}

	while (j <= e) {
		crr[k] = arr[j];
		j++;
		k++;
	}

	for (int l = s; l <= e; l++) {
		arr[l] = crr[l];
	}


}

void mergeSort(int* arr, int s, int e) {

	// base case
	if (s == e) {
		// sort the arr[s...e] = {arr[s]} -> already sorted
		return;
	}

	// recursive case

	// 1. divide the array into two subarrays around the midPoint
	int m = s + (e - s) / 2;

	// 2. recursively sort the two subarrays arr[s...m] and arr[m+1...e]

	mergeSort(arr, s, m);
	mergeSort(arr, m + 1, e);

	// 3. merge the to sorted subarrays arr[s...m] and arr[m+1...e] such that the merged array is sorted
	merge(arr, s, m, e);

}

int main() {

	int arr[] = {50, 10, 30, 20, 40};
	int n = sizeof(arr) / sizeof(int);

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}