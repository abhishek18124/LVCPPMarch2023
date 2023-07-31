#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> v = {5, 5, 1, 5, 5, 1};

	int slow = v[0];
	int fast = v[0];

	while (true) {

		slow = v[slow];
		fast = v[v[fast]];

		if (slow == fast) {
			// meeting point
			break;
		}

	}

	slow = v[0];

	while (slow != fast) {
		slow = v[slow];
		fast = v[fast];
	}

	cout << slow << endl; // or cout << fast << endl;

	return 0;
}