#include<iostream>
#include<bitset>

using namespace std;

int main() {

	// int a = 25;
	// int b = 19;

	// cout << "a&b : " << (a&b) << endl;
	// cout << "a|b : " << (a|b) << endl;
	// cout << "a^b : " << (a^b) << endl;
	// cout << "~a  : " << (~a)  << endl;

	// cout << bitset<32>(a) << endl;
	// cout << bitset<32>(~a) << endl;

	int c = 1;

	// c = c<<1;
	// cout << "c<<1 : " << c << endl;

	// c = c<<1;
	// cout << "c<<1 : " << c << endl;

	// c = c<<1;
	// cout << "c<<1 : " << c << endl;

	cout << "c<<1 : " << (c<<1) << endl;
	cout << "c<<2 : " << (c<<2) << endl;
	cout << "c<<3 : " << (c<<3) << endl;

	cout << "c : " << c << endl;

	c = 8;

	cout << "c>>1 : " << (c>>1) << endl;
	cout << "c>>2 : " << (c>>2) << endl;
	cout << "c>>3 : " << (c>>3) << endl;

	cout << "c : " << c << endl;

	return 0;
}