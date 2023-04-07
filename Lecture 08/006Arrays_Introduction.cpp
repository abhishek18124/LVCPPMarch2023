#include<iostream>

using namespace std;

int main() {

	int arr[10]; // array declaration

	cout << "sizeof(arr) = " << sizeof(arr) << "B" << endl;
	cout << sizeof(arr) / sizeof(int) << endl;

	float brr[5];

	cout << "sizeof(brr) = " << sizeof(brr) << "B" << endl;
	cout << sizeof(brr) / sizeof(float) << endl;

	char chrr[30];

	cout << "sizeof(chrr)= " << sizeof(chrr) << "B" << endl;
	cout << sizeof(chrr) / sizeof(char) << endl;

	double drr[20];

	cout << "sizeof(drr) = " << sizeof(drr) << "B" << endl;
	cout << sizeof(drr) / sizeof(double) << endl;
	
	return 0;
}