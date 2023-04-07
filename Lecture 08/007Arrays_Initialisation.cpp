#include<iostream>

using namespace std;

int main() {

	// int A[5] = {10, 20, 30, 40, 50};

	// cout << "A[0] = " << A[0] << endl;
	// cout << "A[1] = " << A[1] << endl;
	// cout << "A[2] = " << A[2] << endl;
	// cout << "A[3] = " << A[3] << endl;
	// cout << "A[4] = " << A[4] << endl;

	// int B[] = {100, 200, 300, 400, 500};

	// cout << "B[0] = " << B[0] << endl;
	// cout << "B[1] = " << B[1] << endl;
	// cout << "B[2] = " << B[2] << endl;
	// cout << "B[3] = " << B[3] << endl;
	// cout << "B[4] = " << B[4] << endl;

	// int C[5] = {1000, 2000, 3000};

	// cout << "C[0] = " << C[0] << endl;
	// cout << "C[1] = " << C[1] << endl;
	// cout << "C[2] = " << C[2] << endl;
	// cout << "C[3] = " << C[3] << endl;
	// cout << "C[4] = " << C[4] << endl;

	// int D[10] = {0};

	// int E[10] = {};

	int F[10];

	memset(F, 0, sizeof(F));

	int n = sizeof(F) / sizeof(int);

	for(int i=0; i<n; i++) {
		cout << F[i] << " ";
	}

	cout << endl;

	for(int i=0; i<=n-1; i++) {
		cout << F[i] << " ";
	}

	cout << endl;

	return 0;
}