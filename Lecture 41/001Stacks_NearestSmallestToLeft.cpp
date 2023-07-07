#include<iostream>
#include<stack>
#include<vector>

using namespace std;
void f(int* A, int n) {

	stack<pair<int, int>> s; // {val, idx}
	vector<int> out;

	for (int i = 0; i < n ; i++) {

		// find the nearest smaller element to the the left of arr[i]

		while (!s.empty() and s.top().first >= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have a nearest smaller element to its left
			out.push_back(-1);
		} else {
			// top of the stack is the nearest smaller element to the left for A[i]
			// cout << s.top() << " ";
			out.push_back(s.top().second);
		}

		s.push({A[i], i});

	}

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

}


int main() {

	int A[] = {0, 3, 5, 4, 1, 6, 2};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}