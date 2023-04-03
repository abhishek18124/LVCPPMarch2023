#include<iostream>

using namespace std;

int main() {

	int n = 5;

	// iterate over the n rows from 1 to n
	for(int i=1; i<=n; i++) {

		// for the ith row, print n-i spaces
		for(int j=1; j<=n-i; j++) {
			cout << "  ";
		}

		// followed by i nos. in the increasing order starting with i
		
		// for(int j=1, no=i; j<=i; j++, no++) {
		// 	cout << no << " ";
		// }

		// int no = i;
		// for(int j=1; j<=i; j++) {
		// 	cout << no << " ";
		// 	no++;
		// }

		int no = i;
		int j = 1;
		while(j <= i) {
			cout << no << " ";
			no++;
			j++;
		}

		cout << endl;

	}

	return 0;
}