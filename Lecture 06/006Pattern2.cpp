#include<iostream>

using namespace std;

int main() {

	int n = 5;

	// iterate over the n rows from 1 to n
	int i=1;

	while(i <= n) {

		// for the ith row, print i nos. starting from 1 in the increasing order

		int j = 1;
		int no = 1;
		while(j <= i) {
			cout << no << " ";
			no++;
			// cout << j << " ";
			j++;
		}

		i++;
		cout << endl;

	}

	return 0;
}