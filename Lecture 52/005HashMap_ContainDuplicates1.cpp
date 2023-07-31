#include<iostream>
#include<vector>
#include <unordered_map>
#include<unordered_set>

using namespace std;

int main() {

	vector<int> v = {1, 2, 3, 4, 1};

	bool flag = false; // assume no duplicates

	// // time : O(n)

	// // space : O(n)

	// unordered_map<int, int> freqMap;

	// for (int i = 0; i < v.size(); i++) {

	// 	freqMap[v[i]]++;

	// 	if (freqMap[v[i]] > 1) {
	// 		// you've found a duplicate
	// 		flag = true;
	// 		break;
	// 	}

	// }

	// // for (pair<int, int> p : freqMap) {
	// // 	int key = p.first; // key is element value
	// // 	int value = p.second; // frequency of element
	// // 	cout << key << " " << value << endl;

	// // 	if (value > 1) {
	// // 		flag = true;
	// // 		break;
	// // 	}

	// // }

	// time : O(n)

	// space : O(n)

	unordered_set<int> hashSet;

	for (int i = 0; i < v.size(); i++) {

		if (hashSet.find(v[i]) != hashSet.end()) {
			// you've found a duplicate
			flag = true;
			break;
		}

		hashSet.insert(v[i]);

	}

	flag ? cout << "duplicate found!" << endl : cout << "duplicate not found!" << endl;

	return 0;
}