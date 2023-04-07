#include<iostream>
#include<climits>

using namespace std;

int main() {

	int n;
	cout << "Enter the value of n : ";
	cin >> n;

	int a = 0; // to store the unique number

	int x; 

	for(int i=1; i<=n; i++) {
		cin >> x;
		// a = a^x;
		a ^= x;
	}

	cout << "unique number : " << a << endl;
	
	return 0;
}