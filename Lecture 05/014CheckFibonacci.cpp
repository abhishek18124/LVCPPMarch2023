#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	if(n == 0 || n == 1) {
		// n is either the 0th or the 1st fibonacci no.
		cout << "true"  << endl;
		return 0;
	}

	int a = 0; // to store the 0th fib. no.
	int b = 1; // to store the 1st fib. no.

	while(true) {
		
		// generate the next fibonacci no.
		
		int c = a+b;

		// if(c == n) {
		// 	// n is part of fibonacci sequence
		// 	cout << "true" << endl;
		// 	break;
		// }

		// if(c > n) {
		// 	// n is not part of the fibonacci sequence
		// 	cout << "false" << endl;
		// 	break;
		// }

		// a = b;
		// b = c;

		if(c == n) {
			cout <<  "true" << endl;
			break;
		} else if(c > n) {
			cout << "false" << endl;
			break;
		} else {
			// the current fibonacci no. is < n
			a = b;
			b = c;
		}
	}
	
	return 0;
}