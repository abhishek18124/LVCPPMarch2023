#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a non-negative integer : ";
	cin >> n;

	int p;
	cout << "Enter no. of precision places : ";
	cin >> p;

	float sq_root = 0;
	float inc_factor = 1;

	int i = 0;
	while(i <= p) {
		while(sq_root*sq_root <= n) {
			sq_root = sq_root + inc_factor; 
		}
		sq_root = sq_root - inc_factor;
		i = i+1;
		inc_factor = inc_factor/10;
	}

	cout << sq_root << endl;
	
	return 0;
}