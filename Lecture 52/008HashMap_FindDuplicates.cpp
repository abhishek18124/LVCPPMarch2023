#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> v = {1, 0, 1, 2, 2, 2, 3, 3, 4};
	int n = v.size();

	// time : O(n)
	// space : O(1) but we modify the input arr[]

	for (int i = 0; i < v.size(); i++) {

		int x = v[i] % n;

		v[x] += n;

	}

	// for (int i = 0; i < n; i++) {
	// 	cout << v[i] << " ";
	// }

	for (int i = 0; i < n; i++) {

		if (v[i] / n > 1) {

			// i is a duplicate

			cout << i << endl;

		}

	}

	return 0;
}