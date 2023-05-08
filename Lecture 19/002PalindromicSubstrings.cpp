#include<iostream>

using namespace std;

bool isPalindrome(string s) {
	int i = 0;
	int j= s.size()-1;

	while(i < j) {
		if(s[i] != s[j]) {
			return false;
		}
		i++;
		j--;
	}

	return true;
}

// time : O(n^3)

int countPalindromicSubstrings(string s) {

	int n = s.size();
	int count = 0; // to track the no. of palindromic substrings in the given string

	for(int i=0; i<n; i++) {
		for(int j=i; j<n; j++) {
			// check if the substring that starts at the ith index and ends at the jth index is a palindrome or not
			string subString = s.substr(i, j-i+1);
			if(isPalindrome(subString)) {
				count++;
			}
		}
	}

	return count;

}

int countPalindromicSubstringsEfficient(string s) {

	int n = s.size();
	int count = 0; // to track the no. of palindromic substrings in the given string

	// 1. count the no. of odd length palindromic substrings in the given string

	for(int i=0; i<=n-1; i++) {

		// count the no. of odd length palindromic substrings centred around the ith character

		int j = 0;

		while(i-j >= 0 and i+j <= n-1 and s[i-j] == s[i+j]) {
			count++;
			j++;
		}

	}

	// 2. count eh no. of even length palindromic substrings in the given string

	for(double i=0.5; i<=n-1; i++) {

		// count the no. of even length palindromic substrings centred around the ith potential even center

		double j = 0.5;

		while(i-j >= 0 and i+j <= n-1 and s[int(i-j)] == s[int(i+j)]) {
			count++;
			j++;
		}

	}

	return count;

}

int main() {

	string s = "abaaba";
	
	// cout << countPalindromicSubstrings(s) << endl;

	cout << countPalindromicSubstringsEfficient(s) << endl;
	
	return 0;
}