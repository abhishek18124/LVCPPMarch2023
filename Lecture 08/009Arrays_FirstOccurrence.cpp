#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 10, 20};
	int n = sizeof(arr) / sizeof(int);

	int t = 100;

	int i;

	for(i=0; i<n; i++) {
		if(t == arr[i]) {
			// you've found the 't' at index 'i'
			cout << t << " found at index " << i << endl;
			break;
		}
	}
	
	if(i == n) {
		cout << t << " is not found!" << endl;
	}

	return 0;
}