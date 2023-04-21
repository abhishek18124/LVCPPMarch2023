#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40, 50};
	int n = sizeof(arr) / sizeof(int);

	// // iterate over all the possible indices for the 1st element in the pair

	// for(int i=0; i<=n-2; i++) {

	// 	// for a given 'i', iterate over all the possible indicies for the 2nd element of the pair
	// 	for(int j=i+1; j<=n-1; j++) {

	// 		cout << arr[i] << " " << arr[j] << endl;

	// 	}

	// 	cout << endl;

	// }

	// iterate over all the possible indices for the 1st element in the pair

	for(int i=n-1; i>=1; i--) {

		// for a given 'i', iterate over all the possible indicies for the 2nd element of the pair
		for(int j=i-1; j>=0; j--) {

			cout << arr[i] << " " << arr[j] << endl;

		}

		cout << endl;

	}

	return 0;
}