#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cout << i << " ";
	}
	cout << endl;

	// cout << i << endl; // error since scope of 'i' is limited to the body of for-loop

	// for(int i=0, j=0; i<n && j<n; i++, j++) {
	// 	cout << i << " " << j << endl;
	// }

	// int i = 0;
	// for(; i<n; i++) {
	// 	cout << i << " ";
	// }

	// int i;
	// for(i=0; i<n; i++) {
	// 	cout << i << " ";
	// }
	// cout << endl;
	// cout << "i = " << i << endl;

	// infinite loop
	// for(;;) {
	// 	cout << ".";
	// }

	return 0;
}