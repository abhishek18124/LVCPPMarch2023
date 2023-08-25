/*
	https://leetcode.com/problems/palindrome-partitioning/
*/

#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(string str) {
	int i = 0;
	int j = str.size() - 1;
	while (i < j) {
		if (str[i] != str[j]) {
			return false;
		}
		i++;
		j--;
	}
	return true;
}

vector<string> p;
vector<vector<string>> all_p;

int countPalindromicPartitioning(string str, int n, int i) {

	// base case

	if (i == n) {
		// for (string s : p) {
		// 	cout << s << " ";
		// }
		// cout << endl;
		all_p.push_back(p);
		return 1;
	}

	// recursive case

	// count the number of palindromic partitioning of str[i...n-1]

	// decide the next cut

	int count = 0;

	for (int j = i; j < n; j++) {
		string subString = str.substr(i, j - i + 1);
		if (isPalindrome(subString)) {
			// you can make a cut at the jth index
			// recursively, count the number of palindromic partitioning of str[j+1...n-1]
			p.push_back(subString);
			count += countPalindromicPartitioning(str, n, j + 1);
			p.pop_back();
		}
	}

	return count;

}

// time : O(n^3)

// space : O(n)

int countPalindromicPartitioningBottomUp(string str, int n) {

	vector<int> dp(n + 1);

	dp[n] = 1; // at the nth index of dp[], we store f(n)

	for (int i = n - 1; i >= 0; i--) {

		int count = 0;

		for (int j = i; j < n; j++) {
			string subString = str.substr(i, j - i + 1);
			if (isPalindrome(subString)) {
				// you can make a cut at the jth index
				// recursively, count the number of palindromic partitioning of str[j+1...n-1]
				count += dp[j + 1];
			}
		}

		dp[i] = count;

	}

	return dp[0];

}

int main() {

	string str = "abaaa";
	int n = str.size();

	cout << countPalindromicPartitioning(str, n, 0) << endl;

	cout << countPalindromicPartitioningBottomUp(str, n) << endl;

	return 0;
}