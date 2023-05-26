#include<iostream>

using namespace std;

// f(n) : print nos. from 1 to n in the incr. order
// f(2) : print nos. from 1 to 2 in the incr. order -> 1 2
// f(1) : print nos. from 1 to 1 in the incr. order -> 1
// f(0) : print nos. from 1 to 0 in the incr. order ? not possible

void f(int n) {

	// base case

	if (n == 0) {
		return;
	}

	// recursive case

	// 1. ask your friend to print nos. from 1 to n-1 in the increasing order

	f(n - 1);

	cout << n << " ";
}


int main() {

	int n = 1;

	f(n);

	return 0;
}