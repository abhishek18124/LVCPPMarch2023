/*

Example :
	Input : N = 5, W = 4
			weights[] = {1, 2, 3, 2, 2}
			profits[] = {8, 4, 1, 5, 3}
	Output: 13

*/


#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int> weights, vector<int> profits,
              int N, int i, int w) {

	// base case

	if (i == N) {
		return 0;
	}

	if (w == 0) {
		return 0;
	}

	// recursive case

	// take a sequence of decisions for the objects starting at the ith index such that current capacity of the knapsack is 'w'

	// make a decision for the ith object

	if (weights[i] > w) {
		// exclude the ith object from the knapsack
		return maxProfit(weights, profits, N, i + 1, w);
	}

	// 1. include the ith object into the knapsack
	int X = maxProfit(weights, profits, N, i + 1, w - weights[i]);

	// 2. exclude the ith object from the knapsack
	int Y = maxProfit(weights, profits, N, i + 1, w);

	return max(profits[i] + X, Y);

}

// time : (N+1).(W+1).c ~ O(N.W)

// space : (N+1).(W+1) due to dp[][] + N+1 due to function call stacck
//       : N.W + N ~ O(N.W)

int maxProfitTopDown(vector<int>& weights, vector<int>& profits,
                     int N, int i, int w, vector<vector<int>>& dp) {

	// lookup
	if (dp[i][w] != -1) {
		return dp[i][w];
	}

	// base case

	if (i == N) {
		return dp[i][w] = 0;
	}

	if (w == 0) {
		return dp[i][w] = 0;
	}

	// recursive case

	// take a sequence of decisions for the objects starting at the ith index such that current capacity of the knapsack is 'w'

	// make a decision for the ith object

	if (weights[i] > w) {
		// exclude the ith object from the knapsack
		return dp[i][w] = maxProfitTopDown(weights, profits, N, i + 1, w, dp);
	}

	// 1. include the ith object into the knapsack
	int X = maxProfitTopDown(weights, profits, N, i + 1, w - weights[i], dp);

	// 2. exclude the ith object from the knapsack
	int Y = maxProfitTopDown(weights, profits, N, i + 1, w, dp);

	return dp[i][w] = max(profits[i] + X, Y);

}

// time : O(N.W)
// space : O(N.W) due to dp[][]

int maxProfitBottomUp(vector<int>& weights, vector<int>& profits,
                      int N, int W) {

	vector<vector<int>> dp(N + 1, vector<int>(W + 1));

	for (int i = 0; i <= N; i++) {
		dp[i][0] = 0;
	}

	for (int w = 0; w <= W; w++) {
		dp[N][w] = 0;
	}

	for (int i = N - 1; i >= 0; i--) {

		for (int w = 1; w <= W; w++) {

			// dp[i][w] = f(i, w)

			if (weights[i] > w) {

				// exclude the ith object from the knapsack
				dp[i][w] = dp[i + 1][w];

			} else {

				// 1. include the ith object into the knapsack
				int X = dp[i + 1][w - weights[i]];

				// 2. exclude the ith object from the knapsack
				int Y = dp[i + 1][w];

				dp[i][w] = max(profits[i] + X, Y);

			}

		}

	}

	return dp[0][W]; // at the (0, W)th index of dp[][], we store f(0, W)

}


int main() {

	int N = 5;
	int W = 4;

	vector<int> weights = {1, 2, 3, 2, 2};
	vector<int> profits = {8, 4, 1, 5, 3};

	cout << maxProfit(weights, profits, N, 0, W) << endl;

	vector<vector<int>> dp(N + 1, vector<int>(W + 1, -1));

	cout << maxProfitTopDown(weights, profits, N, 0, W, dp) << endl;

	cout << maxProfitBottomUp(weights, profits, N, W) << endl;

	return 0;
}