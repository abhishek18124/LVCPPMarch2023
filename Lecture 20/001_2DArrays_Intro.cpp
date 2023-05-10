/*

	Constraints

	0 < m, n <= 10

	here, m denotes the no. of rows in the given 2D array
	      n denotes the no. of cols in the given 2D array

*/

#include<iostream>

using namespace std;

int main() {

	int arr[10][10]; // 2D array declaration

	int m;
	cout << "Enter the no. of row : ";
	cin >> m;

	int n;
	cout << "Enter the no. of columns : ";
	cin >> n;

	// read mxn values into the 2D array
	
	// iterate over the 'm' rows starting from the 0th row and going towards the m-1th row

	for(int i=0; i<m; i++) {

		// to read values in the ith row, iterate over the 'n' columns starting from the 0th column and going towards the n-1th column

		for(int j=0; j<n; j++) {

			cin >> arr[i][j];

		}
	}

	// print mxn values of the 2D array

	for(int i=0; i<m; i++) {

		for(int j=0; j<n; j++) {

			cout << arr[i][j] << " ";

		}

		cout << endl;

	}

	cout << endl;

	return 0;
}


