/*
	Given N cartesian points in a 2D plane, count the number of right-angled triangles that
	can be formed such that the base or perpendicular is parallel to the x-axis or y-axis.

	Examples

	Input : {(0, 0),
	         (2, 0),
	         (0, 1)}

	Output: 1

	Input : {(1, 2),
			 (2, 0),
			 (2, 2),
			 (2, 3),
			 (4, 2)}

	Output: 4
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Point {
public:
	int x;
	int y;

	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int main() {

	vector<Point> points = {
		Point(1, 2),
		Point(2, 0),
		Point(2, 2),
		Point(2, 3),
		Point(4, 2)
	};

	// int count = 0;

	// // time : O(n^2)

	// for (Point pivot : points)  {

	// 	// compute the no. of axis parallel rightAngledTriangles around 'pivot'

	// 	int a = 0; // to store the #points in the 2D plane with same x-coordinate as 'pivot'
	// 	int b = 0; // to store the #points in the 2D plane with same y-coordinate as 'pivot'

	// 	for (Point p : points) {
	// 		if (p.x == pivot.x) {
	// 			a++;
	// 		}

	// 		if (p.y == pivot.y) {
	// 			b++;
	// 		}
	// 	}

	// 	count += (a - 1) * (b - 1);
	// }

	// cout << "count : " << count << endl;

	int count = 0;

	unordered_map<int, int> xFreqMap;
	unordered_map<int, int> yFreqMap;

	// time : O(n)

	for (Point p : points) {
		xFreqMap[p.x]++;
		yFreqMap[p.y]++;
	}

	// time : O(n)

	for (Point pivot : points)  {

		// compute the no. of axis parallel rightAngledTriangles around 'pivot'

		int a = xFreqMap[pivot.x];
		int b = yFreqMap[pivot.y];

		count += (a - 1) * (b - 1);
	}

	// time : O(n+n) ~ O(n)
	// spacce : O(n)

	cout << "count : " << count << endl;

	return 0;
}