#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main() {

	int arr[] = { -2, 0, -1, 2, -3, 1, 3};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	int i = 0;     // to store the start of the window
	int j = 0;     // to store the end of the window
	queue<int>  q; // to store negative numbers in a window
	vector<int> v; // to store first negative number for each k-sized window

	// find the first negative number in the 1st window

	// time : k steps

	while (j < k) {
		if (arr[j] < 0) q.push(arr[j]);
		j++;
	}

	// q.empty() ? v.push_back(0) : v.push_back(q.front());

	if (q.empty()) {
		// 1st window doesn't have a negative element
		v.push_back(0);
	} else {
		v.push_back(q.front());
	}

	// time : n-k steps

	// find the first negative number in the remaining windows

	while (j < n) {

		// slide the window

		if (arr[i] < 0) q.pop();
		i++;
		if (arr[j] < 0) q.push(arr[j]);

		q.empty() ? v.push_back(0) : v.push_back(q.front());

		j++;

	}

	// total steps k + (n-k) and each step takes constant time

	// time : O(n)

	// space : O(k) due to queue if all the elements of window are negative

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}

