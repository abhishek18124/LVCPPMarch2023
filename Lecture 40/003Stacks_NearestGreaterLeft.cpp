#include<iostream>
#include<stack>
#include<vector>

using namespace std;

void f(int* A, int n) {

	stack<int> s;
	vector<int> out;

	for (int i = 0; i < n; i++) {

		// find the nearest greater elment to the the left of arr[i]

		while (!s.empty() and s.top() <= A[i]) {
			s.pop();
		}

		if (s.empty()) {
			// A[i] doesn't have a nearest greater element to left
			// cout << -1 << " ";
			out.push_back(-1);
		} else {
			// top of the stack is the nearest greater element to the left for A[i]
			// cout << s.top() << " ";
			out.push_back(s.top());
		}

		s.push(A[i]);

	}

	for (int i = 0; i < out.size(); i++) {
		cout << out[i] << " ";
	}

	cout << endl;

}


int main() {

	int A[] = {5, 2, 0, 4, 1, 3, 6};
	int n = sizeof(A) / sizeof(int);

	f(A, n);

	return 0;
}