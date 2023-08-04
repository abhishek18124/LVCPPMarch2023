#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int main() {

	int arr[] = {1, 4, 0, 1, 2, 3, 5};
	int n = sizeof(arr) / sizeof(int);
	int k = 4;

	int i = 0;     // to store the start of the window
	int j = 0;     // to store the end of the window
	deque<int> d;  // to store numbers of interest in a window
	vector<int> v; // to store the maximum element for each k-sized window

	// time : O(n) ? n push + n-1 pops in the worst-case e.g. 1 2 3 4 5 6 ....

	// find the maximum element in the 1st window

	while (j < k) {

		while (!d.empty() and d.back() <= arr[j]) {
			d.pop_back();
		}

		d.push_back(arr[j]);
		j++;
	}

	v.push_back(d.front()); // d.front() == d[0]

	// find the maximum element in the remaining windows

	while (j < n) {

		// slide the window
		if (d.front() == arr[i]) {
			// arr[i] was the maximum element of the previous window
			d.pop_front();
		}
		i++;
		while (!d.empty() and d.back() <= arr[j]) {
			d.pop_back();
		}
		d.push_back(arr[j]);

		v.push_back(d.front());

		j++;

	}


	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	cout << endl;

	return 0;
}

