#include<iostream>

using namespace std;

// time : O(m.n)

bool isPresent(int mat[][3], int m, int n, int t) { // or int (*mat)[3]

	for(int i=0; i<m; i++) {

		for(int j=0; j<n; j++) {

			if(mat[i][j] == t) {

				// you've found the target at the (i, j)th index

				return true;

			}
		}

	}	

	// target is not present

	return false;

}

int main() {

	int mat[][3]  = {{50, 80, 20},
					 {90, 10, 70},
					 {60, 30, 40}};

	int m = 3;
	int n = 3;

	int t = 10;

	isPresent(mat, m, n, t) ? cout << t << " found!" << endl :
	                          cout << t << " not found!" << endl;

	return 0;
}