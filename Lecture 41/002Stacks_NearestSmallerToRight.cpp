#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>

using namespace std;

void f(int* A, int n) {

	stack<pair<int, int>> s; // {val, idx}
	vector<int> out;

	for (int i = n - 1; i >= 0; i--) {

		// find the nearest smaller elment to the the right of arr[i]

		while (!s.empty() and s.top().first >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have a nearest smaller element to its right
			out.push_back(n);
		} else {
			// top of the stack is the nearest smaller element to the right for A[i]
			// cout << s.top() << " ";
			out.push_back(s.top().second);
		}

		s.push({A[i], i});

	}

	reverse(out.begin(), out.end());

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

}


int main() {

	int A[] = {2, 5, 1, 3, 6, 4, 0};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}