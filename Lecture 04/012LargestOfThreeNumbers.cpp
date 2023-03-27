#include<iostream>

using namespace std;

int main() {

	int a;
	cout << "Enter the first number : ";
	cin >> a;

	int b;
	cout << "Enter the second number : ";
	cin >> b;

	int c;
	cout << "Enter the third number : ";
	cin >> c;

	if(a > b and a > c) {
		cout << a  << " is the largest " << endl;
	} else {
		// 'a' is not the largest, either 'b' is the largest or 'c' is largest
		if(b > c) {
			cout <<  b << " is the largest" << endl;
		} else {
			cout << c << " is the largest" << endl;
		}
	}


	return 0;
}