/*

=============
Edit Distance
=============

Given two strings s1 and s2, return the min. no. of edit operations required to convert
s1 to s2.

You have the following three operations permitted on a word:

	> Insert a character
	> Delete a character
	> Replace a character

The min. no. of edits required to convert s1 to s2 is also known as the edit distance
between s1 & s2.

Examples

Example 1:

	Input: s1 = "food", s2 = "money"
	Output: 4

Example 2:

	Input: s1 = "horse", s2 = "ros"
	Output: 3

	Explanation:
	horse -> rorse (replace 'h' with 'r')
	rorse -> rose (remove 'r')
	rose -> ros (remove 'e')

Example 3:

	Input: s1 = "intention", s2 = "execution"
	Output: 5

	Explanation:
	intention -> inention (remove 't')
	inention -> enention (replace 'i' with 'e')
	enention -> exention (replace 'n' with 'x')
	exention -> exection (replace 'n' with 'c')
	exection -> execution (insert 'u')

*/

#include<iostream>
#include<vector>

using namespace std;

int editDistance(string s1, string s2, int m, int n, int i, int j) {

	// base case

	if (i == m) {
		// compute the edit distance b/w s1[m...m-1] and s2[j...n-1]
		return n - j;
	}

	if (j == n) {
		// compute the edit distance b/w s1[i...m-1] and s2[n...n-1]
		return m - i;
	}

	// recursive case

	// compute the edit distance b/w s1[i...m-1] and s2[j...n-1]

	// 1. letter insertion

	// recursively, compute the edit distance b/w s1[i...m-1] and s2[j+1...n-1]

	int X = editDistance(s1, s2, m, n, i, j + 1);

	// 2. letter deletion

	// recursively, compute the edit distance b/w s1[i+1...m-1] and s2[j...n-1]

	int Y = editDistance(s1, s2, m, n, i + 1, j);

	// 3. letter subsitution

	// recursively, compute the edit distance b/w s1[i+1...m-1] and s2[j+1...n-1]

	int Z = editDistance(s1, s2, m, n, i + 1, j + 1);

	return min({1 + X, 1 + Y, (int)(s1[i] != s2[j]) + Z});

}

// time : O(m.n)
// space : (m+1)x(n+1) due dp[][] + m+n due to function call stack ~ O(m.n)

int editDistanceTopDown(string s1, string s2, int m, int n, int i, int j, vector<vector<int>>& dp) {

	// lookup
	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	// base case

	if (i == m) {
		// compute the edit distance b/w s1[m...m-1] and s2[j...n-1]
		return dp[i][j] = n - j;
	}

	if (j == n) {
		// compute the edit distance b/w s1[i...m-1] and s2[n...n-1]
		return dp[i][j] = m - i;
	}

	// recursive case

	// compute the edit distance b/w s1[i...m-1] and s2[j...n-1]

	// 1. letter insertion

	// recursively, compute the edit distance b/w s1[i...m-1] and s2[j+1...n-1]

	int X = editDistanceTopDown(s1, s2, m, n, i, j + 1, dp);

	// 2. letter deletion

	// recursively, compute the edit distance b/w s1[i+1...m-1] and s2[j...n-1]

	int Y = editDistanceTopDown(s1, s2, m, n, i + 1, j, dp);

	// 3. letter subsitution

	// recursively, compute the edit distance b/w s1[i+1...m-1] and s2[j+1...n-1]

	int Z = editDistanceTopDown(s1, s2, m, n, i + 1, j + 1, dp);

	return dp[i][j] = min({1 + X, 1 + Y, (int)(s1[i] != s2[j]) + Z});

}

int editDistanceBottomUp(string s1, string s2, int m, int n) {

	vector<vector<int>> dp(m + 1, vector<int>(n + 1));

	for (int j = 0; j <= n; j++) {
		dp[m][j] = n - j;
	}

	for (int i = 0; i <= m; i++) {
		dp[i][n] = m - i;
	}

	for (int i = m - 1; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			dp[i][j] = min(

			{
				1 + dp[i][j + 1],
				1 + dp[i + 1][j],
				(int)(s1[i] != s2[j]) + dp[i + 1][j + 1]

			});
		}
	}

	return dp[0][0]; // at the (0, 0)th index of dp[][], we store f(0, 0)

}


int main() {

	string s1("intention");
	int m = s1.size();

	string s2("execution");
	int n = s2.size();

	cout  << editDistance(s1, s2, m, n, 0, 0) << endl;

	vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

	cout << editDistanceTopDown(s1, s2, m, n, 0, 0, dp) << endl;

	cout << editDistanceBottomUp(s1, s2, m, n) << endl;

	return 0;
}