/*

	constraints :

	0 < m, n <= 10

*/

#include<iostream>
#include<algorithm>

using namespace std;

void sortDiagonal(int mat[][10], int m, int n, int i, int j) {

	// sort the diagonal that starts at the (i, j)th index 

	int diagonalLength = min(m-i, n-j);
	int diagonal[diagonalLength];

	// 1. extract the diagonal elements into a 1D array

	for(int k=0; k<diagonalLength; k++) {

		diagonal[k] = mat[i+k][j+k];

	}

	// 2. sort the diagonal i.e. 1D array

	sort(diagonal, diagonal+diagonalLength);

	// 3. copy the diagonal into the 2D array

	for(int k=0; k<diagonalLength; k++) {
		mat[i+k][j+k] = diagonal[k];
	}

}

void sortDiagonally(int mat[][10], int m, int n) {

	// iterate over the starting points of the diagonals

	// 1. (i, 0)
	for(int i=0; i<=m-1; i++) {

		sortDiagonal(mat, m, n, i, 0);

	}

	// 2. (0, j)

	for(int j=1; j<=n-1; j++) {

		sortDiagonal(mat, m, n, 0, j);

	}

}


int main() {
	
	int mat[][10] = {{50, 80, 20},
					 {90, 10, 70},
					 {60, 30, 40}};

	int m = 3;
	int n = 3;

	sortDiagonally(mat, m, n);

	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
	
	return 0;
}