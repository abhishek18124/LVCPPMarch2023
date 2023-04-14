#include<iostream>

using namespace std;

int main() {

	int arr[] = {10, 20, 30, 40};
	int n = sizeof(arr) / sizeof(int);

	for(int i=0; i<(1<<n); i++) {
		cout << i << " : ";
		for(int j=0; j<n; j++) {
			if((i>>j)&1) {
				// jth bit of  'i'  is set therefore include arr[j] in the subsequence
				cout << arr[j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}
