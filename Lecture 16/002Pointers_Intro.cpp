#include<iostream>

using namespace std;

int main() {

	int x = 10;

	int* xptr; // pointer declaration
	xptr = &x; // pointer assignment
	
	cout << "x = " << x << endl;
	cout << "sizeof(x) = " << sizeof(x) << endl;
	cout << "&x = " << &x << endl;
	cout << "xptr = " << xptr << endl;
	cout << "sizeof(xptr) = " << sizeof(xptr) << "B" << endl;

	cout << endl;

	double z = 3.14;

	double* dptr = &z; // pointer initialisation

	cout << "z = " << z << endl;
	cout << "sizeof(z) = " << sizeof(z) << endl;
	cout << "&z = " << &z << endl;
	cout << "dptr = " << dptr << endl;
	cout << "sizeof(dptr) = " << sizeof(dptr) << "B" << endl;

	cout << endl;

	char ch = 'A';

	char* chptr = &ch; // pointer initialisation

	cout << "ch = " << ch << endl;
	cout << "sizeof(ch) = " << sizeof(ch) << endl;
	cout << "&ch = " << &ch << endl;
	cout << "chptr = " << chptr << endl;
	cout << "sizeof(chptr) = " << sizeof(chptr) << "B" << endl;

	cout << endl;

	return 0;
}