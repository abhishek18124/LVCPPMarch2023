#include<iostream>

using namespace std;

int main() {

	int p;
	cout << "Enter the value of principle : ";
	cin >> p;

	int r;
	cout << "Enter the value of rate :" ;
	cin >> r;

	int t;
	cout << "Enter the value of time : ";
	cin >> t;

	// int p, r, t;
	// cin >> p >> r >> t;

	cout << "simple interest = " << p*r*t/100 << endl;
	cout << "simple interest = " << p*r*t*1.0/100 << endl;
	cout << "simple interest = " << p*r*t/100.0 << endl;
	cout << "simple interest = " << (float)p*r*t/100 << endl;
	cout << "simple interest = " << p*r*t/(float)100 << endl;
	cout << "simple interest = " << float(p*r*t)/100 << endl;
	cout << "simple interest = " << p*r*t/float(100) << endl;
	
	float si = p*r*t/(float)100; // you need to do type-casting to get the correct output
	cout << "simple interest = " << si << endl;

	// cout << "simple interest = " << float(p*r*t/100) << endl;



	return 0;
}