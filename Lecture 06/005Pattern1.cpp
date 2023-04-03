#include<iostream>

using namespace std;

int main() {

	int n = 10;

	// iterate over the 'n' rows starting from the 1st row and going towards the nth row

	int i = 1;

	while(i <= n) {

		// print 'i' stars for the ith row

		int j = 1;

		while(j <= i) {
			cout << "*";
			j++;
		}

		i++;

		cout << endl;

	}

	cout << endl;

	return 0;
}