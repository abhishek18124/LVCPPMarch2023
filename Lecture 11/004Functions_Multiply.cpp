#include<iostream>

using namespace std;

// int multiply(int a, int b) {
// 	int c = a*b;
// 	return c;
// }

int multiply(int a, int b) {
	return a*b;
}

int main() {

	cout << multiply(2, 3) << endl;

	cout << 10+multiply(2, 3) << endl;

	int product = multiply(2, 3);

	cout << product << endl;

	return 0;
}