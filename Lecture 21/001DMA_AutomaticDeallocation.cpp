#include<iostream>

using namespace std;

// int* f() {
// 	int x = 10;
// 	return &x;
// }

int* f() {
	int* xptr = new int;
	*xptr = 10;
	return xptr;
}

int main() {

	int* xptr = f();

	cout << *xptr << endl;
	
	return 0;
}