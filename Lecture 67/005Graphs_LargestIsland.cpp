#include<iostream>
#include<vector>

using namespace std;

int dfsHelper(vector<vector<int>> grid,
              vector<vector<bool>>& visited,
              int m, int n,
              int i, int j) {

	// mark the (i, j)th vertex as visited

	visited[i][j] = true;

	int count = 1; // to track the count of vertices in the current component

	// visit the unvisited neighbours of the (i, j)th vertex

	// todo ...

	return count;

}

int largestIsland(vector<vector<int>> grid, int m, int n) {
	vector<vector<bool>> visited(m, vector<bool>(n, false)); // to keep track of visited vertices
	int maxArea = 0; // to keep track of the area of the largest island
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (grid[i][j] == 1 and !visited[i][j]) {
				maxArea = max(maxArea,
				              dfsHelper(grid, visited, m, n, i, j));
			}
		}
	}
	return maxArea;
}

int main() {

	vector<vector<int>> grid = {{1, 0, 0, 1, 0},
		{1, 0, 1, 0, 0},
		{0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1},
		{1, 0, 1, 1, 0}
	};

	int m = grid.size();
	int n = grid[0].size();

	cout << largestIsland(grid, m, n) << endl;

	return 0;
}