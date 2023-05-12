#include<iostream>

using namespace std;

int main() {

	int* xptr = new int;

	*xptr = 1000;

	cout << *xptr << endl;

	delete xptr; // to avoid memory leak

	xptr = new int;

	*xptr = 2000;

	cout << *xptr << endl;

	delete xptr;

	return 0;
}