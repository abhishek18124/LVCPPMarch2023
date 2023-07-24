/*

	STL implementation of the min_heap data structure with custom comparator.


*/

#include<iostream>
#include<queue>

using namespace std;

class myGreaterComparator {

public :

	/*
		assume 'b' to be the newly inserted node and 'a' to be its parent in the CBT

		return true when swap is needed

		return false when swap is not needed

	*/

	bool operator()(int a, int b) {
		if (b < a) {
			// you need a swap for a minHeap
			return true;
		}
		// you don't need a swap for a minHeap
		return false;
	}

};

class customer {

public :

	int age;
	double balance;

	customer(int age, double balance) {
		this->age = age;
		this->balance = balance;
	}
};

class myCustomerAgeComparator {
public :

	/*
		assume 'b' to be the newly inserted node in the CBT and 'a' to be its parent

		return true when swap is needed

		otherwise return false

	*/

	bool operator()(customer a, customer b) {

		if (b.age < a.age) {
			// you need a swap for a minHeap based on customer age
			return true;
		}

		// you don't a swap for a minHeap based on customer age
		return false;

	}
};


class myCustomerBalanceComparator {

public :

	bool operator()(customer a, customer b) {
		if (b.balance > a.balance) {
			// you need a swap for a maxHeap based on customerBalance
			return true;
		}
		// you don't need a swap for a maxHeap based on customerBalance
		return false;
	}

};

int main() {

	// priority_queue<int, vector<int>, myGreaterComparator> m;

	// m.push(9);
	// m.push(7);
	// m.push(8);
	// m.push(5);
	// m.push(4);
	// m.push(6);
	// m.push(3);
	// m.push(2);
	// m.push(1);

	// cout << m.size() << endl;

	// while (!m.empty()) {
	// 	cout << m.top() << " ";
	// 	m.pop();
	// }

	// cout << endl;

	// cout << m.size() << endl;

	// priority_queue<customer, vector<customer>, myCustomerAgeComparator> customerHeap; // minHeap based on customerAge

	priority_queue<customer, vector<customer>, myCustomerBalanceComparator> customerHeap; // maxHeap based on customerBalance

	customerHeap.push(customer(25, 1000));
	customerHeap.push(customer(21, 500));
	customerHeap.push(customer(18, 750));
	customerHeap.push(customer(29, 5000));
	customerHeap.push(customer(14, 100));

	while (!customerHeap.empty()) {
		customer c = customerHeap.top();
		cout << c.age << " " << c.balance << endl;
		customerHeap.pop();
	}

	cout << endl;

	return 0;
}