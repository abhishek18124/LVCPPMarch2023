/*

Given a m x n grid filled with non-negative numbers, find a path from (0, 0) to (m-1, n-1), 
which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example : 
	Input: grid = [[1,3,1],
	               [1,5,1],
	               [4,2,1]]

	Output: 7
	Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Constraints :
	1 <= m, n <= 200
	0 <= grid[i][j] <= 100

*/

#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int minSumPath(vector<vector<int>> grid, int i, int j) {

	// base case
	if(i == 0 and j == 0) {
		// compute the sum of nos. along the minSum path 
		// to reach the (0,0)th cell from (0,0)th cell.
		
		return grid[0][0];
	}

	// recursive cases

	if(i == 0) {
		// compute the sum of nos. along the minSum path to 
		// reach a cell in (i, j)th cell which is in the 0th 
		// row
		return grid[i][j] + minSumPath(grid, i, j-1);
	}

	if(j == 0) {
		// compute the sum of nos. along the minSum path to 
		// reach a cell in (i, j)th cell which is in the 0th 
		// column
		return grid[i][j] + minSumPath(grid, i-1, j);
	}

	// compute the sum of nos. along the minSum path to 
	// reach a cell in (i, j)th cell which is neither in
	// the 0th row or in the 0th column

	int X = minSumPath(grid, i, j-1);
	int Y = minSumPath(grid, i-1, j);

	return grid[i][j] + min(X, Y);
}

int main() {

	vector<vector<int>> grid = {{1, 3, 1},
   								{1, 5, 1},
   								{4, 2, 1}};

   	int m = grid.size();
   	int n = grid[0].size();

   	cout << minSumPath(grid, m-1, n-1) << endl;

	return 0;
}