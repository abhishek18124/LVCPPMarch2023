// n <= 10^6

// 10^8 ~ 1s

#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// approach : time : O(n^2) why ? for each building, we do ~ n computations space : O(1)

	int w = 0; // to store the total amt. of rainwater trapped between the buildings

	for(int i=0; i<n; i++) {

		// compute the amt. of rainwater trapped on top of the ith building : w_i

		// l_i : it is the max. of heights of all the buildings in the range [0, i]
		int l_i = h[i];
		for(int j=i-1; j>=0; j--) {
			// if(h[j] > l_i) {
			// 	l_i = h[j];
			// }
			l_i = max(l_i, h[j]);
		}

		// r_i : it is the max. of heights of all the buildings in the range [i, n-1]
		int r_i = h[i];
		for(int j=i+1; j<n; j++) {
			r_i = max(r_i, h[j]);
		}

		int w_i = min(l_i, r_i) - h[i];

		w += w_i;

	}

	cout << w << endl;

	return 0;
}