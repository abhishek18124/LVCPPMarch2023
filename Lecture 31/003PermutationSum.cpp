#include<iostream>
#include<vector>

using namespace std;

void generatePermutations(int t, vector<int> c, vector<int>& perm) {

	// base case

	if (t == 0) {
		for (int candidate : perm) {
			cout << candidate << " ";
		}
		cout << endl;
		return;
	}

	// recursion case

	// generate permutations of 'c' that sums up to 't' or choose candidates that sum up to 't'

	// decide the next candidate

	int n = c.size();
	for (int j = 0; j < n; j++) {
		if (t - c[j] >= 0) {
			perm.push_back(c[j]);
			generatePermutations(t - c[j], c, perm);
			perm.pop_back(); // backtracking
		}
	}

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> perm; // to track the permutation that sums up to 't'

	generatePermutations(t, c, perm);

	return 0;
}