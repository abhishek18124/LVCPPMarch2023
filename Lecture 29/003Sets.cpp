/*

	https://cplusplus.com/reference/set/set/?kw=set
	https://cplusplus.com/reference/set/multiset/?kw=multiset

	> insert/erase/find is logarithmic i.e. O(logn)
	> values are inserted in the sorted order
	> set contains only distinct values
	> multiset allows duplicate values

*/

#include<iostream>
#include<set>

using namespace std;

int main() {

	set<int> s;

	s.insert(5); // {5}
	s.insert(4); // {4, 5}
	s.insert(3); // {3, 4, 5}
	s.insert(2); // {2, 3, 4, 5}
	s.insert(1); // {1, 2, 3, 4, 5}
	s.insert(1); // {1, 2, 3, 4, 5}

	cout << "size : " << s.size() << endl; // 5

	s.erase(5); // {1, 2, 3, 4}

	cout << "size : " << s.size() << endl;

	for (auto it = s.begin(), end = s.end(); it != end; it++) {
		cout << *it << " ";
	}

	cout << endl;

	for (int x : s) {
		cout << x << " "; // {1, 2, 3, 4}
	}

	cout << endl;

	// s.erase(2); // {1, 3, 4}

	// for (int x : s) {
	// 	cout << x << " "; // {1, 3, 4}
	// }

	if (s.find(3) != s.end()) {
		cout << "3 is present" << endl;
	} else {
		cout << "3 is absent" << endl;
	}

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.erase(s.find(3));

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	s.erase(s.begin()); // or erase the 1st element of the set

	for (int x : s) {
		cout << x << " ";
	}

	cout << endl;

	if (s.count(1)) {
		cout << "1 is present" << endl;
	} else {
		cout << "1 is absent" << endl;
	}

	s.clear();

	cout << "size : " << s.size() << endl;

	return 0;
}