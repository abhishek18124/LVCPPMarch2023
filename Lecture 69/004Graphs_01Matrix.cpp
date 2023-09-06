// https://leetcode.com/problems/01-matrix/

#include<iostream>
#include<vector>
#include<queue>
#include<climits>

using namespace std;

// // 1. brute-force approach - time : O(m^2.n^2)

// vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

// 	int m = mat.size();
// 	int n = mat[0].size();

// 	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

// 	for (int i = 0; i < m; i++) {
// 		for (int j = 0; j < n; j++) {
// 			if (mat[i][j] == 0) {
// 				for (int ii = 0; ii < m; ii++) {
// 					for (int jj = 0; jj < n; jj++) {
// 						dist[ii][jj] = min(dist[ii][jj], abs(ii - i) + abs(jj - j));
// 					}
// 				}
// 			}
// 		}
// 	}

// 	return dist;

// }

// 2. multisource BFS : time : O(m.n) : each vertex is visited only once

vector<vector<int>> multisourceBFS(vector<vector<int>>& mat) {

	int m = mat.size();
	int n = mat[0].size();

	vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

	queue<pair<int, int>> q;

	// initialisation of multi-source BFS

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 0) {
				// (i, j)th cell corresponds to a source vertex
				q.push({i, j});
				dist[i][j] = 0;
			}
		}
	}

	vector<int> dx = {0, 0, -1, 1};
	vector<int> dy = {1, -1, 0, 0};

	while (!q.empty()) {

		pair<int, int> front = q.front();
		q.pop();

		int i = front.first;
		int j = front.second;

		for (int k = 0; k < 4; k++) {

			int ii = i + dx[k];
			int jj = j + dy[k];

			if (ii >= 0 and ii < m and jj >= 0 and jj < n and dist[ii][jj] == INT_MAX) {
				// vertex {ii, jj} is not yet visited
				dist[ii][jj] = dist[i][j] + 1;
				q.push({ii, jj});
			}

		}


	}

	return dist;

}

int main() {

	vector<vector<int>> mat = {
		{0, 1, 1, 1, 0},
		{1, 1, 1, 1, 1},
		{1, 1, 0, 1, 1},
		{1, 1, 1, 1, 1},
		{0, 1, 1, 1, 0}
	};

	// vector<vector<int>> dist = updateMatrix(mat);

	vector<vector<int>> dist = multisourceBFS(mat);

	for (vector<int> row : dist) {
		for (int col : row) {
			cout << col << " ";
		}
		cout << endl;
	}

	return 0;
}