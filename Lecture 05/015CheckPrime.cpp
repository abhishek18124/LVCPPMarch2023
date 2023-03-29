#include<iostream>
#include<cmath>

using namespace std;

int main() {

	int n;
	cout << "Enter a positive integer : ";
	cin >> n;

	int rn = sqrt(n);

	// int i = 2;
	// while(i <= rn) {
	// 	if(n%i == 0) {
	// 		// you've found a factor of 'n' in the range [2, rn]
	// 		cout <<  n << " is not a prime number " << endl;
	// 		break; // or use "return 0" if you don't want to write condition outside the while loop to print if n is prime
	// 	}
	// 	i = i+1;
	// }

	// if(i > rn) {
	// 	cout << n << " is a prime number " << endl;
	// }

	bool flag = true; // assume 'n' is a prime number

	int i = 2;
	while(i <= rn) {
		if(n%i == 0) {
			// you've found a factor 'n' in the range [2, rn] i.e. your intial assumption that n is prime is incorrect
			flag = false;
			break;
		}
		i = i+1;
	}

	// if(flag) { // flag == true
	// 	cout << n << " is a prime number " << endl; 
	// } else {
	// 	cout << n << " is not a prime numnber" << endl;
	// }i = i+1;

	flag ? cout << n << " is prime number " << endl :
	       cout << n << " is not a prime number" << endl;

	return 0;
}