#include<iostream>
#include<cmath>

using namespace std;

bool isPrime(int n) {

	for(int i=2; i<=sqrt(n); i++) {
		if(n%i == 0) {
			// we've found a factor of 'n' in the range [2, rootn] therefore 'n' is a composite number
			return false;
		}
	}

	// n is definitely a prime number
	return true;
	
}


void printPrimes(int m) {

	for(int n=2; n<=m; n++) {
		// check if 'n' is prime
		if(isPrime(n)) {
			cout << n << " ";
		}
	}

}

int main() {

	int m;
	cout << "Enter the value of m : ";
	cin >> m;

	printPrimes(m);
	
	return 0;
}