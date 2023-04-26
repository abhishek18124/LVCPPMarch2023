// contraints : n <= 100

#include<iostream>

using namespace std;

int main() {	

	int arr[] = {2, 0, 4, 1, 3};
	int n = sizeof(arr) / sizeof(int);
	
	int inv[100]; // based on constraints

	for(int i=0; i<n; i++) {
		cout << i << " : " << arr[i] << endl;
		inv[arr[i]] = i;
	}

	cout << endl;
	
	for(int i=0; i<n; i++) {
		cout << i << " : " << inv[i] << endl;
	}

	return 0;
}