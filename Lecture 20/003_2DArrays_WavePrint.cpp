#include<iostream>

using namespace std;

int main() {

	int mat[][3] = {{10, 20, 30},
					{40, 50, 60},
					{70, 80, 90}};

	int m = 3;
	int n = 3;

	// iterate over the 'n' columns starting from the 0th column and going towards the (n-1)th column

	for(int j=0; j<n; j++) {

		if(j%2 == 0) {

			// jth column is an even column

			// iterate over the 'm' rows starting from the 0th row and going towards the (m-1)th row

			for(int i=0; i<m; i++) {

				cout << mat[i][j] << " ";

			}

		} else {

			// jth column is an odd column

			// iterate over the 'm' rows starting from the m-1th row and going towards the 0th row

			for(int i=m-1; i>=0; i--) {

				cout << mat[i][j] << " ";
				
			}


		}

	}

	return 0;
}