#include<iostream>

using namespace std;

int main() {

	int arr[] = {-10, -20, 1, 2, 3};

	int n = sizeof(arr) / sizeof(int);

	int fL = INT_MIN;
	int sL = INT_MIN;
	int tL = INT_MIN;

	int fS = INT_MAX;
	int sS = INT_MAX;

	for(int i=0; i<n; i++) {

		if(arr[i] > fL) {
			tL = sL;
			sL = fL;
			fL = arr[i];
		} else if(arr[i] > sL) {
			tL = sL;
			sL = arr[i];
		} else if(arr[i] > tL) {
			tL = arr[i];
		} 

		if(arr[i] < fS) {
			sS = fS;
			fS = arr[i];
		} else if(arr[i] < sS) {
			sS = arr[i];
		}

	}

	int p1 = fL*sL*tL;
	int p2 = fS*sS*fL;

	// if(p1 > p2) {
	// 	cout << p1 <<  endl;
	// } else {
	// 	cout << p2 << endl;
	// }

	cout << max(p1, p2) << endl;
	cout << max(fL*sL*tL, fS*sS*fL) << endl;

	cout << max(10, 20) << endl;
	cout << min(-200, -500) << endl;

	cout << max({10, 20, 30}) << endl;
	cout << max(10, max(20, 30)) << endl;

	cout << min({-10, -20, -30, -40}) << endl;
	cout << min(-10, min(-20, min(-30, -40))) << endl;

	return 0;
}