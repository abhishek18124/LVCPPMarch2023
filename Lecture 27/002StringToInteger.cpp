#include<iostream>

using namespace std;

int stringToInteger(string str, int n) {

	// base case

	if (str == "") { // or str.empty() or n == 0
		return 0;
	}

	// if (n == 1) {
	// 	return str[0] - '0';
	// }

	// recursive case

	// 1. extract the substring of size n-1 starting from the 0th index
	string subString = str.substr(0, n - 1);

	// 2. ask your friend to convert this subString into an integer
	int integerFromMyFriend = stringToInteger(subString, n - 1);

	return integerFromMyFriend * 10  + str[n - 1] - '0';

}

int main() {

	string str = "1234";
	int n = str.size();

	int x = stringToInteger(str, n);

	cout << x + 10 << endl;

	return 0;
}