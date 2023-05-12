#include<iostream>

using namespace std;

int main() {

	// allocate memory for a 1D array on the heap memory

	// int* ptr = new int[5];

	int* arr = new int[5]{10, 20, 30, 40, 50};

	// access elements of the 1D array

	cout << *(arr+0) << " " << arr[0] << endl;
	cout << *(arr+1) << " " << arr[1] << endl;
	cout << *(arr+2) << " " << arr[2] << endl;
	cout << *(arr+3) << " " << arr[3] << endl;
	cout << *(arr+4) << " " << arr[4] << endl; 

	cout << endl;

	for(int i=0; i<5; i++) {
		cout << *(arr+i) << " " << arr[i] << endl;
	}

	// deallocate memory for 1D array

	delete [] arr; 

	return 0;
}