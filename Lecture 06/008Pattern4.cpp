#include<iostream>

using namespace std;

int main() {

	int n = 5;

	// iterate over the n rows from 1 to n
	int i = 1;
	while(i <= n) {

		// for the ith row, print i nos.

		int j = 1;
		
		// // int no = i%2 == 0 ? 0 : 1;

		int no;
		if(i%2 == 0) {
			// ith row is even
			no = 0;
		} else {
			// ith row is odd
			no = 1;
		}

		while(j <= i) {
			cout << no << " ";
			no = 1-no;
			j++;
		}

		// bool no = i%2 == 0 ? false : true;

		// while(j <= i) {
		// 	cout << no << " ";
		// 	no = !no;
		// 	j++;
		// }

		i++;
		cout << endl;

	}

	cout << endl;

	return 0;
}