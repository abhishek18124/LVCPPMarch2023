/*

Suppose there is a ladder with n steps.  A person standing at the
bottom of the  ladder and  wants to reach to its top. Assume the
person can take a jump of size 1 to k at a time. Then, count the
number of ways, the person can reach the top of the ladder.

Example
	Input : n = 4, k = 3
	Output: 7
	Explanation : [1, 1, 1, 1],
	              [1, 1, 2],
	              [1, 2, 1],
	              [2, 1, 1],
	              [2, 2],
	              [1, 3],
	              [3, 1]

*/
#include<iostream>
#include<vector>

using namespace std;

int numOfWays(int n, int k) {

	// base case
	if (n == 0) {
		return 1;
	}

	// recursive case

	int count = 0;

	for (int j = 1; j <= k; j++) {

		if (n - j >= 0) {

			// you can reach the nth step from the n-jth step by taking a jump of size j

			// recursively, count no. of ways to reach n-jth step from the bottom

			count += numOfWays(n - j, k);
		}
	}

	return count;
}

// time : O(n.k)

// space : n+1 (due to the dp[]) + n+1 (due to function stack) ~ O(n)

int numOfWaysTopDown(int n, int k, vector<int>& dp) {

	// lookup
	if (dp[n] != -1) {
		return dp[n];
	}

	// base case
	if (n == 0) {
		return dp[n] = 1;
	}

	// recursive case

	int count = 0;

	for (int j = 1; j <= k; j++) {

		if (n - j >= 0) {

			// you can reach the nth step from the n-jth step by taking a jump of size j

			// recursively, count no. of ways to reach n-jth step from the bottom

			count += numOfWaysTopDown(n - j, k, dp);
		}
	}

	return dp[n] = count;
}

// time : O(n.k)

// space : O(n) due to dp[]

int numOfWaysBottomUp(int n, int k) {

	vector<int> dp(n + 1);

	dp[0] = 1; // at the 0th index of dp[], we store f(0)

	for (int i = 1; i <= n; i++) {

		// f(i) : count no. of ways to reach the ith step of the ladder from the bottom

		int count = 0;

		for (int j = 1; j <= k; j++) {
			if (i - j >= 0) {
				count += dp[i - j];
			}
		}

		dp[i] = count;

	}

	return dp[n]; // at the nth index of dp[], we store f(n)

}

// time : O(n)
// space : O(n) due to dp[]

int numOfWaysBottomUpTimeOptimised(int n, int k) {

	vector<int> dp(n + 1);

	dp[0] = 1; // at the 0th index of dp[], we store f(0)
	dp[1] = dp[0];

	for (int i = 2; i <= k; i++) {
		dp[i] = 2 * dp[i - 1];
	}

	for (int i = k + 1; i <= n; i++) {
		dp[i] = 2 * dp[i - 1] - dp[i - k - 1];
	}

	return dp[n]; // at the nth index of dp[], we store f(n)

}


int main() {

	int n = 4;
	int k = 3;

	cout << numOfWays(n, k) << endl;

	vector<int> dp(n + 1, -1);

	cout << numOfWaysTopDown(n, k, dp) << endl;

	cout << numOfWaysBottomUp(n, k) << endl;

	cout << numOfWaysBottomUpTimeOptimised(n, k) << endl;

	return 0;
}