#include<iostream>
#include<vector>

using namespace std;

void generateCombinations(int t, vector<int> c, vector<int>& comb, int i) {

	// base case

	if (t == 0) {
		for (int candidate : comb) {
			cout << candidate << " ";
		}
		cout << endl;
		return;
	}

	// recursion case

	// generate the combinations of c[i...n-1] that sum up to 't' or choose candidates that sum up to 't'

	// decide the next candidate

	int n = c.size();
	for (int j = i; j < n; j++) {
		if (t - c[j] >= 0) {
			comb.push_back(c[j]);
			generateCombinations(t - c[j], c, comb, j); // pass 'j+1' is you want to use the candidate c[j] exactly once in a combination
			comb.pop_back();
		}
	}

}

int main() {

	vector<int> c = {2, 3, 5, 7};
	int t = 7;

	vector<int> comb; // to track the combination that sums up to 't'

	generateCombinations(t, c, comb, 0);

	return 0;
}