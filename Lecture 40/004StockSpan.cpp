#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// vector<int> f(int* A, int n) {

// 	stack<pair<int, int>> s; // {val, idx}
// 	vector<int> span;

// 	for (int i = 0; i < n; i++) {

// 		// find the 'index' of the nearest greater element to the left of A[i]

// 		while (!s.empty() and s.top().first <= A[i]) {
// 			s.pop();
// 		}

// 		int j; // to track the index of the nearest greater element to the left of A[i]

// 		if (s.empty()) {
// 			// A[i] doesn't have nearest greater element to its left
// 			j  = -1;
// 		} else {
// 			j = s.top().second;
// 		}

// 		span.push_back(i - j); // span of the ith day is i-j

// 		s.push({A[i], i}); // s.push(make_pair(A[i], i))

// 	}

// 	return span;

// }

vector<int> f(int* A, int n) {

	stack<int> s; // we are pushing indices of element of A[] in the stack
	vector<int> span;

	for (int i = 0; i < n; i++) {

		// find the 'index' of the nearest greater element to the left of A[i]

		while (!s.empty() and A[s.top()] <= A[i]) {
			s.pop();
		}

		int j; // to track the index of the nearest greater element to the left of A[i]

		if (s.empty()) {
			// A[i] doesn't have nearest greater element to its left
			j  = -1;
		} else {
			j = s.top();
		}

		span.push_back(i - j); // span of the ith day is i-j

		s.push(i); // s.push(make_pair(A[i], i))

	}

	return span;

}


int main() {

	int A[] = {100, 80, 60, 70, 60, 75, 85};
	int n = sizeof(A) / sizeof(int);

	vector<int> span = f(A, n);

	for (int i = 0; i < span.size(); i++) {
		cout << span[i] << " ";
	}

	cout << endl;

	return 0;
}