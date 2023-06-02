// constraints : n <= 100

#include<iostream>

using namespace std;

int partition(int* arr, int s, int e) {

	int j = s;
	int i = s - 1; // or j-1 // represent the boundary of the left partition

	int pivot = arr[e];

	while (j < e) {
		if (arr[j] < pivot) {
			// add the jth element to the left partition
			i++;
			swap(arr[i], arr[j]);
		}
		j++;
	}

	swap(arr[i + 1], arr[e]);

	return i + 1;

}

void quickSort(int* arr, int s, int e) {

	// base case

	// if (s == e) {
	// 	// sort the arr[s...s] which is already sorted
	// 	return;
	// }

	// if (s > e) {
	// 	// sort empty array
	// 	return;
	// }

	if (s >= e) {
		return;
	}

	// recursive case

	// 1. partition the arr[s...e] around the pivot i.e. arr[e]

	int m = partition(arr, s, e);

	// 2. recursively sort the left and right partitions i.e. arr[s...m-1] and arr[m+1...e]

	quickSort(arr, s, m - 1);
	quickSort(arr, m + 1, e);


}

int main() {

	int arr[] = {60, 50, 20, 10, 40, 30};
	int n = sizeof(arr) / sizeof(int);

	quickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}