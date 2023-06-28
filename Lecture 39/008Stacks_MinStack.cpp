#include<iostream>
#include<stack>

using namespace std;

// space : O(n) due to min_stack
// in the worst case, it is possible each element we push into the custom stack is smaller
// or equal to the last element therefore min stack will also have n elements

// hw : try to implement custom_stack using O(1) space

class custom_stack {

	stack<int> main_stack;
	stack<int> min_stack; // to track minimum so far

public :

	void push(int data) {
		main_stack.push(data);
		if (min_stack.empty() or data <= min_stack.top()) {
			min_stack.push(data);
		}
	}

	void pop() {
		if (empty()) {
			// stack is empty, underflow
			return;
		}

		int temp = main_stack.top();
		main_stack.pop();
		if (min_stack.top() == temp) {
			min_stack.pop();
		}
	}

	int size() {
		return main_stack.size();
	}

	bool empty() {
		return main_stack.empty();
	}

	int top() {
		return main_stack.top();
	}

	int getMin() {
		return min_stack.top();
	}

};

int main() {

	custom_stack cs;

	cs.push(10);
	cs.push(20);

	cout << "top : " << cs.top() << endl;
	cout << "min : " << cs.getMin() << endl;

	cs.push(0);
	cs.push(30);

	cout << "top : " << cs.top() << endl;
	cout << "min : " << cs.getMin() << endl;

	cs.push(0);

	cout << "top : " << cs.top() << endl;
	cout << "min : " << cs.getMin() << endl;

	cs.pop();

	cout << "top : " << cs.top() << endl;
	cout << "min : " << cs.getMin() << endl;

	cs.pop();
	cs.pop();

	cout << "top : " << cs.top() << endl;
	cout << "min : " << cs.getMin() << endl;

	return 0;
}
