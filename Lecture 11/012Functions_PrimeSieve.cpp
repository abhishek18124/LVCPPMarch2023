// constraints : m <= 99

#include<iostream>

using namespace std;

int main() {

	int m;
	cout << "Enter the value of m : ";
	cin >> m;

	int sieve[100];

	for(int i=0; i<=m; i++) {
		sieve[i] = 1;
	}

	sieve[0] = 0;
	sieve[1] = 0;

	// // approach - 1

	// for(int i=2; i<=m; i++) {

	// 	if(sieve[i] == 1) {
	// 		// 'i' is a prime number therefore cancel out (mark as non-primes) all the multiples of i <= m i.e. part of the sieve
	// 		for(int j=2*i; j<=m; j=j+i) {
	// 			sieve[j] = 0;
	// 		}
	// 	}

	// }

	// // approach - 2

	// for(int i=2; i<=m; i++) {

	// 	if(sieve[i] == 1) {
	// 		// 'i' is a prime number therefore cancel out (mark as non-primes) all the multiples of i <= m i.e. part of the sieve
	// 		for(int j=i*i; j<=m; j=j+i) {
	// 			sieve[j] = 0;
	// 		}
	// 	}

	// }

	// approach - 3

	for(int i=2; i*i<=m; i++) { // i <= sqrt(m)

		if(sieve[i] == 1) {
			// 'i' is a prime number therefore cancel out (mark as non-primes) all the multiples of i <= m i.e. part of the sieve
			for(int j=i*i; j<=m; j=j+i) {
				sieve[j] = 0;
			}
		}

	}

	for(int i=2; i<=m; i++) {
		if(sieve[i] == 1) {
			cout << i << " ";
		}
	}

	cout << endl;

	return 0;
}