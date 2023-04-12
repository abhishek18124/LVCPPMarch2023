#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	int num_comp = 0;

	// iterate over the n-1 passes starting from the 1st pass and going towards the n-1th pass

	for(int i=1; i<=n-1; i++) {

		// in the ith pass, place the largest element in the unsorted part of the array to its correct position

		bool flag = false; // assume, no swaps will be done in the ith pass

		for(int j=0; j<n-i; j++) {
			num_comp++;
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
				flag = true;
			}
		}

		if(!flag) { // flag == false 
			break;
		}

	}

	cout << "num comparision = " << num_comp << endl;
	
	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;
	
	return 0;
}