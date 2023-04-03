#include<iostream>

using namespace std;

int main() {

	int n;
	cout << "Enter a non-negative integer : ";
	cin >> n;

	float sq_root = 0;

	while(sq_root*sq_root <= n) {
		sq_root = sq_root + 1;
	}

	sq_root = sq_root - 1;

	while(sq_root*sq_root <= n) {
		sq_root = sq_root + 0.1;
	}

	sq_root = sq_root - 0.1;	

	while(sq_root*sq_root <= n) {
		sq_root = sq_root + 0.01;
	}

	sq_root = sq_root - 0.01;

	while(sq_root*sq_root <= n) {
		sq_root = sq_root + 0.001;
	}

	sq_root = sq_root - 0.001;

	cout << sq_root << endl;
	
	return 0;
}