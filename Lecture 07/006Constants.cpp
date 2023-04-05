#include<iostream>

using namespace std;

int main() {
	
	const int x = 10;

	cout << x << endl;

	cout << x+1 << endl;

	// x++; // x = x+1 // error since x is const, it cannot be modified

	// const int y; // error since y is not initialized

	return 0;
}