#include<iostream>

using namespace std;

// void printPath(char maze[][10], char path[][10], int m, int n, int i, int j) {

// 	// base case

// 	if (i == -1 || i == m || j == -1 || j == n) {
// 		return;
// 	}

// 	if (i == m - 1 and j == n - 1) {
// 		// you've reached the destination
// 		path[i][j] = '1';
// 		for (int i = 0; i < m; i++) {
// 			for (int j = 0; j < n; j++) {
// 				cout << path[i][j] << " ";
// 			}
// 			cout << endl;
// 		}
// 		cout << endl;
// 		path[i][j] = '0';
// 		return;
// 	}

// 	if (maze[i][j] == 'X') {
// 		return;
// 	}

// 	// recursive case

// 	if (path[i][j] == '1') {
// 		// (i, j)th is already part of the path we are building
// 		return;
// 	}

// 	path[i][j] = '1';

// 	// 1. move right
// 	printPath(maze, path, m, n, i, j + 1);

// 	// 2. move left
// 	printPath(maze, path, m, n, i, j - 1);

// 	// 3. move up
// 	printPath(maze, path, m, n, i - 1, j);

// 	// 4. move down
// 	printPath(maze, path, m, n, i + 1, j);

// 	path[i][j] = '0';

// }


// void printPath(char maze[][10], char path[][10], int m, int n, int i, int j) {

// 	// base case

// 	if (i == -1 || i == m || j == -1 || j == n) {
// 		return;
// 	}

// 	if (i == m - 1 and j == n - 1) {
// 		// you've reached the destination
// 		path[i][j] = '1';
// 		for (int i = 0; i < m; i++) {
// 			for (int j = 0; j < n; j++) {
// 				cout << path[i][j] << " ";
// 			}
// 			cout << endl;
// 		}
// 		cout << endl;
// 		path[i][j] = '0';
// 		return;
// 	}

// 	if (maze[i][j] == 'X') {
// 		return;
// 	}

// 	// recursive case

// 	path[i][j] = '1';
// 	maze[i][j] = 'X'; // block the (i, j)th cell

// 	// 1. move right
// 	printPath(maze, path, m, n, i, j + 1);

// 	// 2. move left
// 	printPath(maze, path, m, n, i, j - 1);

// 	// 3. move up
// 	printPath(maze, path, m, n, i - 1, j);

// 	// 4. move down
// 	printPath(maze, path, m, n, i + 1, j);

// 	path[i][j] = '0';
// 	maze[i][j] = '0'; // unblock the (i, j)th cell

// }


void printPath(char maze[][10], char path[][10], int m, int n, int i, int j) {

	// base case

	if (i == -1 || i == m || j == -1 || j == n) {
		return;
	}

	if (i == m - 1 and j == n - 1) {
		// you've reached the destination
		path[i][j] = '1';
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << path[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		path[i][j] = '0';
		return;
	}

	if (maze[i][j] == 'X') {
		return;
	}

	// recursive case

	path[i][j] = '1';
	maze[i][j] = 'X'; // block the (i, j)th cell

	int dx[] = {0, 0, -1, 1};
	int dy[] = {1, -1, 0, 0};

	for (int k = 0; k < 4; k++) {
		printPath(maze, path, m, n, i + dx[k], j + dy[k]);
	}

	path[i][j] = '0';
	maze[i][j] = '0'; // unblock the (i, j)th cell

}


int main() {

	char maze[][10] = {"0X00",
	                   "000X",
	                   "X0X0",
	                   "X00X",
	                   "XX00"
	                  };

	char path[][10] = {"0000",
	                   "0000",
	                   "0000",
	                   "0000",
	                   "0000"
	                  };
	int m = 5;
	int n = 4;

	printPath(maze, path, m, n, 0, 0);

	return 0;
}
