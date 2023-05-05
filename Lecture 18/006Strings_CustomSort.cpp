#include<iostream>
#include<algorithm>

using namespace std;

/*

	1. myComparator as a function will be used by the built-in sort
	   function	to decide when to do a swap or not do a swap

	2. at any point time, while sorting the given array of strings
	   you'll be comparing two string objects say a and b.

	3. always assume, that current 'a' is present at a position 
	   lower than the position 'b'


	4. this function should return 'true' when swap is NOT needed
	   otherwise it should return 'false' when swap is NEEDED.


*/


bool myComparator(string a, string b) {
	if(a > b) {
		// since 'a' is currently at a position lower than 'b'
		// and a > b and we want to sort the input array in
		// the decreasing order that means we don't need a swap
		return true;
	} else {
		// you need swap
		return false;
	}

	// return a > b
}

// assume 'a' is present at a lower position than 'b'
// return true when swap is not needed else return false

bool myLengthComparator(string a, string b) {
	if(a.length() < b.length()) {
		// you don't need a swap
		return true;
	}
	// you need a swap
	return false;

	// return a.length() < b.length()
}

// assume current 'a' is at a lower position than 'b'
// return true when swap is needed else return false

bool myGreaterComparator(int a, int b) {
	// if(a > b) {
	// 	// you don't need a swap when sorting the array in dec. order
	// 	return true;
	// }
	// // you need a swap
	// return false;

	return a > b;
}

int main() {

	// string arr[] = {"abc", "ghi", "jkl", "def"};
	// int n = 4;

	// sort(arr, arr+n); // [begin, end) -> sorts the entire array of strings in lexicographically increasing order

	// for(int i=0; i<n; i++) {
	// 	cout << arr[i] << " ";
	// }

	// cout << endl;

	// sort the given array of string in lexicographically decreasing order

	// string brr[] = {"abc", "def", "ghi", "jkl"};

	// int n = 4;

	// // sort(brr, brr+n);

	// // reverse(brr, brr+n);

	// sort(brr, brr+n, myComparator);
	// // sort(brr, brr+n, greater<string>());

	// for(int i=0; i<n; i++) {
	// 	cout << brr[i] << " ";
	// }

	// cout << endl;


	// string crr[] = {"abcd", "abc", "a", "de"};

	// int n = 4;

	// sort(crr, crr+n, myLengthComparator);

	// for(int i=0; i<n; i++) {
	// 	cout << crr[i] << " ";
	// }

	// cout << endl;

	int drr[] = {100, 20, 17, 250, 100};

	int n = 5;

	sort(drr, drr+n, myGreaterComparator);
	// sort(drr, drr+n, greater<int>());

	for(int i=0; i<n; i++) {
		cout << drr[i] << " ";
	}

	cout << endl;


	return 0;
}