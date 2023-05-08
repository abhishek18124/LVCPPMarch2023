#include<iostream>
#include<algorithm>

using namespace std;

bool isGoodString(string str) {

	for(int i=0; i<str.size(); i++) {

		// check if the ith character of the given string 'str' is a consonant

		if(!(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')) {

			// ith character of str is a consonant

			return false;

		}

	}

	return true;

}

// for each subString, in the worst we do <= n compuations

// since we have ~n^2 subString

// total computations ~ n^2.n = O(n^3)

int computeLongestLengthOfGoodSubstring(string str) {

	int n = str.size();

	int maxLen = 0; // to track the length of the longest goodSubtring

	// iterate over all the possible subString of the given string 'str'

	for(int i=0; i<n; i++) {

		for(int j=i; j<n; j++) {

			// check if the subString that starts at the ith index and ends at the jth index is a good subString or not

			string subString = str.substr(i, j-i+1);
			if(isGoodString(subString)) {
				maxLen = max(maxLen, j-i+1);
			}

		}

	}

	return maxLen;

}

// total work : n.c ~ O(n)

int computeLongestLengthOfGoodSubstringEfficient(string str) {

	int n = str.size();

	int maxLen = 0; // to track the length of the longest goodSubtring
	int count  = 0;

	for(int i=0; i<n; i++) {

		char ch = str[i];

		if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
			// ith character of str[] is a vowel
			count++;
			maxLen = max(maxLen, count);
		} else {
			// ith character of str[] is a consonant
			count = 0;
		}

	}

	return maxLen;

}

int main() {

	string str = "cbaeicdeiou";
		
	// cout << computeLongestLengthOfGoodSubstring(str) << endl;

	cout << computeLongestLengthOfGoodSubstringEfficient(str) << endl;
		
	return 0;
}