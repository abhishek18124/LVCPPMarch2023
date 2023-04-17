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

int main() {

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	isPrime(n) ? cout << n << " is prime" << endl : 
	             cout << n << " is not prime" << endl;

	return 0;
}