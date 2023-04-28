// n <= 100

#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	// numComputations ~ n

	int l[100]; // based on the contraints
	l[0] = h[0];
	for(int i=1; i<n; i++) {
		l[i] = max(l[i-1], h[i]);
	}

	// numComputations ~ n

	int r[100]; // based on the contraints
	r[n-1] = h[n-1];
	for(int i=n-2; i>=0; i--) {
		r[i] = max(r[i+1], h[i]);
	}

	// numComputations ~ n

	int w = 0; // to store the total amt. of rainwater trapped b/w the buildings
	
	//int l_i = 0;

	for(int i=0; i<n; i++) {

		// compute the amt. of rainwater trapped on top of the ith building : w_i

		// l_i = max(l_i, h[i]);

		int w_i = min(l_i, r[i]) - h[i];
		w += w_i;

	}	

	cout << w << endl;

	// total numComputations = n+n+n = 3.n ~ O(n)

	// total space = n(due to l[]) + n(due to r[]) = 2.n ~ O(n) 

	return 0;
}