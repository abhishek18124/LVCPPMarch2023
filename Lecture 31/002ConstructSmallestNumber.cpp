// n <= 8

#include<iostream>

using namespace std;

bool used[10] = {false}; // to track the digits used in the construction of the
// smallest number corresponding to the given pattern.

// string out = "999999999"; // smallest so far ; 999999999 == INT_MAX

bool flag = false; // you've not yet found the lexicographically smallest num

void construct(string pattern, string& num, int i) {

	// base case

	if (num.size() == pattern.size() + 1) { // i == n (pattern.size())
		cout << num << endl;
		flag = true;
		// out = min(out, num);
		return;
	}

	// recursive case

	// decide the next digit in 'num'

	if (num.size() == 0) {
		for (int d = 1; d <= 9; d++) {
			used[d] = true;
			num.push_back(d + '0');
			construct(pattern, num, i);

			if (flag == true) {
				// you've found the lexicographically smallest num
				return;
			}

			used[d] = false;
			num.pop_back();
		}
		return;
	}

	int x = num.back() - '0'; // or num[num.size()-1] - '0'
	if (pattern[i] == 'I') {
		// next digit should be greater than x [x+1, x+2 ... 9]
		for (int d = x + 1; d <= 9; d++) {
			if (used[d] == false) {
				num.push_back(d + '0');
				used[d] = true;
				construct(pattern, num, i + 1);

				if (flag == true) {
					// you've found the lexicographically smallest num
					return;
				}

				used[d] = false;
				num.pop_back();
			}
		}


	} else { // pattern[i] == 'D'
		// next digit should eb less than x [1, 2, ... , x-1]
		for (int d = 1; d <= x - 1; d++) {
			if (used[d] == false) {
				num.push_back(d + '0');
				used[d] = true;
				construct(pattern, num, i + 1);

				if (flag == true) {
					// you've found the lexicographically smallest num
					return;
				}

				used[d] = false;
				num.pop_back();
			}
		}
	}

}

int main() {

	string pattern = "IID";
	string num = "";

	construct(pattern, num, 0);

	// cout << out << endl;

	return 0;
}