#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "enter the value of n : ";
	cin >> n;

	// allocate memory for a 1D array with custom size on the heap

	int* arr = new int[n];

	// read values in the 1D array

	for(int i=0; i<n; i++) {
		cin >> arr[i]; // or cin >> *(arr+i);
	}

	// print values of the 1D array

	for(int i=0; i<n; i++) {
		cout << arr[i] << " "; // or cout << *(arr+i) << " ";
	}

	// deallocate memory for 1D array

	delete [] arr;

	return 0;
}