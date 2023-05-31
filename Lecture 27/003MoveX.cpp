/*

Given a string str, design a recursive algorithm to move all the occurrence of letter x
to the end of the string str.

Example
	Input : str = "axbcxdxfx"
	Output: str = "abcdfxxxx"

	Input : str = "xabcxdxfx"
	Output: str = "abcdfxxxx"

*/

#include<iostream>

using namespace std;

string movex(string str) {

	// base case

	if (str == "") { // or str.size() == 0 or str.empty()
		return str;
	}

	// recursive case

	// 1. extract the substring of the given string that starts at the 1st index

	string subString = str.substr(1);

	// 2. ask your friend to move-x in the subString

	string subStringFromMyFriend = movex(subString);

	if (str[0] == 'x') {
		return subStringFromMyFriend + string(1, str[0]);
	}

	return string(1, str[0]) + subStringFromMyFriend;

}

int main() {

	string str = "bxxcxx";

	cout << movex(str) << endl;

	return 0;
}