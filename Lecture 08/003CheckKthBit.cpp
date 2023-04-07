#include<iostream>

using namespace std;

int main() {

	int n = 42;
	int k = 3;

	// if(((n>>k)&1) == 1) {
	// 	// kth bit of n is set
	// 	cout << k << "th bit is set" << endl;
	// } else {
	// 	// kth bit of n is not set
	// 	cout << k << "th bit is not set" << endl;
	// }

	// if((n>>k)&1) {
	// 	cout << "set" << endl;
	// } else {
	// 	cout << "not set" << endl;
	// }

	(n>>k)&1 ? cout << "set" << endl :
	           cout << "not set" << endl;

	// if(((1<<k)&n) > 0) {
	// 	cout << "set" << endl;
	// } else {
	// 	cout << "not set" << endl;
	// }

	if((1<<k)&n) {
		cout << "set" << endl;
	} else {
		cout << "not set" << endl;
	}
	
	return 0;
}