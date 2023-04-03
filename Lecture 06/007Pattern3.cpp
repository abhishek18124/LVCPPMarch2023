#include<iostream>

using namespace std;

int main() {

	int n = 4;

	// iterate over the n rows from 1 to n
	int i=1;
	int no = 1;
	while(i <= n) {

		// for the ith row, print i nos.

		int j = 1;
		while(j <= i) {
			cout << no << " ";
			no++;
			j++;
		}

		i++;
		cout << endl;

	}

	return 0;
}