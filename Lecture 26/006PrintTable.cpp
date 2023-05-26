#include<iostream>

using namespace std;

// f(n) : print nos. from 1 to n in the incr. order
// f(2) : print nos. from 1 to 2 in the incr. order -> 1 2
// f(1) : print nos. from 1 to 1 in the incr. order -> 1
// f(0) : print nos. from 1 to 0 in the incr. order ? not possible

void f(int x, int n) {

	// base case

	if (n == 0) {
		return;
	}

	// recursive case

	// 1. ask your friend to print nos. from x*1 to x*n-1 in the increasing order

	f(x, n - 1);

	cout << x*n << " ";
}


int main() {

	int x = 2;
	int n = 10;

	f(x, n);

	return 0;
}