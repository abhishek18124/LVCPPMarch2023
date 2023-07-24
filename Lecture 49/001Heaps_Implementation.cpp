/*

	Implementation of the heap/priority_queue data structure.

*/

#include<iostream>
#include<vector>

using namespace std;

class minHeap {

	vector<int> v;

	void heapify(int i) {

		int min_idx = i;

		int left_idx = 2 * i + 1;
		if (left_idx < v.size() and v[left_idx] < v[min_idx]) {
			min_idx = left_idx;
		}

		int right_idx = 2 * i + 2;
		if (right_idx < v.size() and v[right_idx] < v[min_idx]) {
			min_idx = right_idx;
		}

		if (min_idx != i) {
			swap(v[i], v[min_idx]);
			heapify(min_idx);
		}

	}

public :

	// time : O(logn)

	void push(int val) {
		v.push_back(val);
		int childIdx = v.size() - 1;
		int parentIdx = childIdx % 2 == 0 ? childIdx / 2 - 1 : childIdx / 2;
		while (childIdx != 0 and v[childIdx] < v[parentIdx]) {
			swap(v[childIdx], v[parentIdx]);
			childIdx = parentIdx;
			parentIdx = childIdx % 2 == 0 ? childIdx / 2 - 1 : childIdx / 2;
		}

	}

	// time : O(logn)

	void pop() {
		swap(v[0], v[v.size() - 1]);
		v.pop_back();
		heapify(0);
	}

	// time : O(1)

	int top() {
		return v[0];
	}

	int size() {
		return v.size();
	}

	bool empty() {
		return v.empty();
	}


};

int main() {

	minHeap m;

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl;

	while (!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}



