#include<iostream>

using namespace std;

int main() {

	int h[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	int n = sizeof(h) / sizeof(int);

	int i = 0; 
	int j = n-1;

	int l = 0; // stores the max. of heights of the buildings in the range [0 to i]
	int r = 0; // stores the max. of heights of the buildings in the range [j to n-1]

	int w = 0; // stores the total amt. of rainwater trapped on top of all the buildings

	// time : O(n) space : O(1)

	while(i <= j) {

		l = max(l, h[i]);
		r = max(r, h[j]);

		if(l < r) {
			// compute the amt. of rainwater trapped on top of the ith building : w_i
			int w_i = l-h[i];
			w += w_i;
			i++;
		} else { // r <= l
			// compute the amt. of rainwater trapped on top of the jth building : w_j
			int w_j = r-h[j];
			w += w_j;
			j--;
		}

	} 

	cout << w << endl;

	return 0;
}