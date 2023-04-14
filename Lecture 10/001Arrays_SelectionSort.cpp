#include<iostream>

using namespace std;

int main() {

	int arr[] = {50, 40, 10, 30, 20};
	int n = sizeof(arr) / sizeof(int);

	// iterate over n-1 passes starting from the 0th pass and going towards the n-2th pass

	for(int i=0; i<=n-2; i++) {


		// in the ith pass, place the smallest element in the unsorted part of the array to its correct position

		int min_idx = i;

		for(int j=i+1; j<=n-1; j++) {

			if(arr[j] < arr[min_idx]) {
				min_idx = j;
			}

		}

		swap(arr[i], arr[min_idx]);		

	}
	
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	
	return 0;
}