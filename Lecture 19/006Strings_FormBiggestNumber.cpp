#include<iostream>
#include<algorithm>

using namespace std;

/*

	assume 'a' is before 'b' in the array
	return true when swap is not needed
	return false when swap is needed

*/

// bool myCompartor(int a, int b) {

// 	string s_a = to_string(a);
// 	string s_b = to_string(b);

// 	if(s_a > s_b) {
// 		// no swap is needed since we are sorting the array lexicographically in the decreasing order
// 		return true;
// 	}

// 	// swap is needed
// 	return false;

// }

bool myCompartor2(int a, int b) {

	string s_a = to_string(a);
	string s_b = to_string(b);

	string s_ab = s_a + s_b;
	string s_ba = s_b + s_a;

	if(s_ab > s_ba) {
		// no swap is needed since we are sorting the array lexicographically in the decreasing order
		return true;
	}

	// swap is needed
	return false;

}


int main() {

	int arr[] = {98, 9, 78, 7};
	int n = sizeof(arr) / sizeof(int);

	sort(arr, arr+n, myCompartor2);

	for(int i=0; i<n; i++) {
		cout << arr[i] << " ";
	}

	cout << endl;

	return 0;
}