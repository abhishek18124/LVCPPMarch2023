#include<iostream>
#include<vector>

using namespace std;

// bool flag = false; // assume 't' in not in the x[]

// void f(int* x, int n, int t, int i) {

// 	// base case

// 	if (i == n) {
// 		// find the idx of the 1st occ. of the 't' in x[n...n-1] = {}
// 		if (flag == false) cout << -1 << " ";
// 		return;
// 	}

// 	// recursive case

// 	// find the idx of the 1st occ. of the 't' in x[i...n-1]

// 	if (x[i] == t) {
// 		flag = true;
// 		cout << i << " ";
// 	}

// 	// recursively find the idx of the 1st occ. of the 't' in x[i+1...n-1]

// 	f(x, n, t, i + 1);

// }

vector<int> indices;

void f(int* x, int n, int t, int i) {

	// base case

	if (i == n) {
		// find the idx of the 1st occ. of the 't' in x[n...n-1] = {}
		return;
	}

	// recursive case

	// find the idx of the 1st occ. of the 't' in x[i...n-1]

	if (x[i] == t) {
		indices.push_back(i);
	}

	// recursively find the idx of the 1st occ. of the 't' in x[i+1...n-1]

	f(x, n, t, i + 1);

}


int main() {

	int x[] = {10, 20, 30, 20, 30};
	int n = sizeof(x) / sizeof(int);
	int t = 100;

	f(x, n, t, 0);

	if (indices.empty()) { // indices.size() == 0
		cout << -1 << " ";
	} else {
		for (int index : indices) {
			cout << index << " ";
		}
		cout << endl;
	}

	return 0;
}