#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;
	bool flag = false; // assume 't' is not present

	for(int i=0; i<n; i++) {
		if(arr[i] == t) {
			flag = true;
			cout << i << " ";
		}
	}

	// if(flag == false) {
	// 	cout << t << " is not present!" << endl;
	// }

	if(!flag) {
		cout << t << " is not present!" << endl;
	}

	return 0;
}