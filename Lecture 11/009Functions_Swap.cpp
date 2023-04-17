#include<iostream>

using namespace std;

// void mySwap(int a, int b) {

// 	cout << "inside mySwap() : before swapping : a = " << a << " b = " << b << endl;

// 	int temp = a;
// 	a = b;
// 	b = temp;

// 	cout << "inside mySwap() : after swapping : a = " << a << " b = " << b << endl;

// }

void mySwap(int& a, int& b) {

	cout << "inside mySwap() : before swapping : a = " << a << " b = " << b << endl;

	int temp = a;
	a = b;
	b = temp;

	cout << "inside mySwap() : after swapping : a = " << a << " b = " << b << endl;

}

int main() {

	int a = 10;
	int b = 20;

	cout << "inside main() : before mySwap() : a = " << a << " b = " << b << endl;

	mySwap(a, b);

	cout << "inside main() : after mySwap() : a = " << a << " b = " << b << endl;

	return 0;
}