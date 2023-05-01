#include<iostream>

using namespace std;

int main() {

	char ch = 'A';
	int* ptr = (int*)&ch;

	cout << "ch = " << ch << endl;
	cout << "&ch = " << &ch << endl;
	cout << "ptr = " << ptr << endl;

	int x = 10;
	char* chptr = (char*)&x;

	cout << "x = " << x << endl;
	cout << "&x = " << &x << endl;
	cout << "chptr = " << chptr << endl;
	
	return 0;
}