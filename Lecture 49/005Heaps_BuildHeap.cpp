/*

	Given an array of n integers, design a O(n) algorirthm to build a max_heap in-place.

*/

#include<iostream>
#include<vector>

using namespace std;

void heapify(vector<int>& v, int n, int i) {

	int max_idx = i;

	int left_idx = 2 * i + 1;
	if (left_idx < n and v[left_idx] > v[max_idx]) {
		max_idx = left_idx;
	}

	int right_idx = 2 * i + 2;
	if (right_idx < n and v[right_idx] > v[max_idx]) {
		max_idx = right_idx;
	}

	if (max_idx != i) {
		swap(v[i], v[max_idx]);
		heapify(v, n, max_idx);
	}

}

int main() {

	vector<int> v = {1, 3, 2, 7, 5, 4, 6, 9, 8};
	int n = v.size();

	// time : O(n)

	for (int i = n - 1; i >= 0; i--) {
		heapify(v, n, i);
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}





