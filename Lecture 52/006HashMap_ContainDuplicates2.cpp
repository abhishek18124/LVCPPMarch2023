#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {

	vector<int> v = {1, 2, 3, 1, 2, 3};
	int k = 2;

	unordered_map<int, int> indexMap;

	bool flag = false; // assume you've not found required pair

	for (int i = 0; i < v.size(); i++) {

		if (indexMap.find(v[i]) != indexMap.end()) {

			// you've seen v[i] previously

			int j = indexMap[v[i]];

			if (i - j <= k) {

				flag = true;
				break;

			}

		}

		indexMap[v[i]] = i;

	}

	flag ? cout << "pair found!" << endl : cout << "pair not found!" << endl;

	return 0;
}