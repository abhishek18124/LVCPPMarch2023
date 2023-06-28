#include<iostream>
#include<stack>

using namespace std;

void print(stack<int> s) {

	while (!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}

	cout << endl;

}

void insertAtBottom(stack<int>& s, int data) {

	// base case

	if (s.empty()) {
		s.push(data);
		return;
	}

	// recursive case

	int temp = s.top();
	s.pop();

	// recursively insert 'data' at the bottom of the resulting stack

	insertAtBottom(s, data);

	s.push(temp);

}

int main() {

	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);

	print(s);

	int data = 0;

	insertAtBottom(s, data);

	print(s);

	return 0;
}