#include<iostream>
#include<vector>

using namespace std;

int f(vector<int> A, int i, int j) {

	// base case

	if (i == j) {
		return 0;
	}

	// recursive case

	int ans = INT_MAX;

	for (int k = i; k < j; k++) {
		ans = min(ans, f(A, i, k) + f(A, k + 1, j) + A[i - 1] * A[k] * A[j]);
	}

	return ans;

}

// time : O(n^3)

// space : O(n^2) + function call stack ~ O(n^2)

int TD(vector<int> A, int i, int j, vector<vector<int>>& dp) {

	// lookup

	if (dp[i][j] != -1) {
		return dp[i][j];
	}

	// base case

	if (i == j) {
		return dp[i][j] = 0;
	}

	// recursive case

	int ans = INT_MAX;

	for (int k = i; k < j; k++) {
		ans = min(ans, TD(A, i, k, dp) + TD(A, k + 1, j, dp) + A[i - 1] * A[k] * A[j]);
	}

	return dp[i][j] = ans;

}

// time : O(n^3)

// space : O(n^2) due to dp[][]

int BU(vector<int> A, int n) {

	vector<vector<int>> dp(n + 1, vector<int>(n + 1)); // 0th row, and 0th column is not used

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 0;
	}

	for (int i = n - 1; i >= 1; i--) {
		for (int j = i + 1; j <= n; j++) {

			int ans = INT_MAX;

			for (int k = i; k < j; k++) {
				ans = min(ans, dp[i][k] + dp[k + 1][j] + A[i - 1] * A[k] * A[j]);
			}

			dp[i][j] = ans;

		}
	}

	return dp[1][n];

}

// dp[i][j] -> dp[i][k] and dp[k+1][j]

// k = i    : dp[i][j] -> dp[i][i] and dp[i+1][j]
// k = i+1  : dp[i][j] -> dp[i][i+1] and dp[i+2][j]
// k = i+2  : dp[i][j] -> dp[i][i+2] and dp[i+3][j]
// ...
// k = j-1  : dp[i][j] -> dp[i][j-1] and dp[j][j]


int main() {

	vector<int> A = {1, 2, 1, 4, 1};

	int n = A.size() - 1;

	cout << f(A, 1, n) << endl;

	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

	cout << TD(A, 1, n, dp) << endl;

	cout << BU(A, n) << endl;

	return 0;
}