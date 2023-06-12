/*

Given a m x n maze with some blocked cells (marked with 'X'), and rat that wants to
go from the src (0, 0) to the dst (m-1, n-1) design a recursive algorithm to

	> check if there exists a path from src to dst

such at each step the rat can only move in the right or down direction.

Constraint

 1 <= m, n < 10

Example
	Input :

		maze = {"0000",
	            "00X0",
	            "000X",
	            "0X00"}

	Output :

		true (Yes, a path exist from src to dst)

*/

#include<iostream>

using namespace std;

// bool checkPath(char maze[][10], int m, int n, int i, int j) {

// 	// base case

// 	if (i == m - 1 and j == n - 1) {

// 		// you've reached the destination

// 		return true;

// 	}

// 	if (maze[i][j] == 'X') {

// 		// you've reached a blocked cell

// 		return false;

// 	}

// 	// recursive case

// 	// check if the rat can go from (i, j)th cell to the (m-1, n-1)th cell

// 	if (i == m - 1) {

// 		// you've to move to right

// 		// recursively check if the rat can go from (i, j+1)th to the (m-1, n-1)th cell

// 		return checkPath(maze, m, n, i, j + 1);

// 	}

// 	if (j == n - 1) {

// 		// you've to move down

// 		// check if the rat can go from (i+1, j)th cell to the (m-1, n-1)th cell

// 		return checkPath(maze, m, n, i + 1, j);

// 	}

// 	// decide the next step

// 	// 1. move right

// 	// recursively check if the rat can go from (i, j+1)th to the (m-1, n-1)th cell

// 	bool X = checkPath(maze, m, n, i, j + 1);

// 	// 2. move down

// 	// check if the rat can go from (i+1, j)th cell to the (m-1, n-1)th cell

// 	bool Y = checkPath(maze, m, n, i + 1, j);

// 	return X or Y;

// }

// bool checkPath(char maze[][10], int m, int n, int i, int j) {

// 	// base case

// 	if(i == m || j == n) {

// 		return false;

// 	}

// 	if (i == m - 1 and j == n - 1) {

// 		// you've reached the destination

// 		return true;

// 	}

// 	if (maze[i][j] == 'X') {

// 		// you've reached a blocked cell

// 		return false;

// 	}

// 	// recursive case

// 	// check if the rat can go from (i, j)th cell to the (m-1, n-1)th cell

// 	// decide the next step

// 	// 1. move right

// 	// recursively check if the rat can go from (i, j+1)th to the (m-1, n-1)th cell

// 	bool X = checkPath(maze, m, n, i, j + 1);

// 	// 2. move down

// 	// check if the rat can go from (i+1, j)th cell to the (m-1, n-1)th cell

// 	bool Y = checkPath(maze, m, n, i + 1, j);

// 	return X or Y;

// }

bool checkPath(char maze[][10], int m, int n, int i, int j) {

	// base case

	if (i == m || j == n) {

		return false;

	}

	if (i == m - 1 and j == n - 1) {

		// you've reached the destination

		return true;

	}

	if (maze[i][j] == 'X') {

		// you've reached a blocked cell

		return false;

	}

	// recursive case

	// check if the rat can go from (i, j)th cell to the (m-1, n-1)th cell

	return checkPath(maze, m, n, i, j + 1) or checkPath(maze, m, n, i + 1, j);

}

int main() {

	char maze[][10] = {"0000",
	                   "00X0",
	                   "0X0X",
	                   "0X00"
	                  };
	int m = 4;
	int n = 4;

	checkPath(maze, m, n, 0, 0) ? cout << "path found!" << endl :
	                                   cout << "path not found!" << endl;

	return 0;
}