/*

Given a string (sequence of characters) of length n, generate all of its permutations.

Example

	Input : inp[] = "aabc"
	Output: ["aabc", "aacb", "abac", "abca", "acba", "acab", "baac", "baca", "bcaa", "cbaa", "caba", "caab"]

*/

#include<iostream>
#include<set>

using namespace std;

set<string> s;

void f(char* inp, int i) {

	// base case
	if (inp[i] == '\0') { // or i == n
		// cout << inp << endl;
		s.insert(string(inp));
		return;
	}

	// recursive case

	// generate permutations of inp[i...] or take decisions for the remaining position [i...n-1]

	// make a decision for the ith position that which character is assigned to it

	int n = strlen(inp);
	for (int j = i; j <= n - 1; j++) {
		swap(inp[i], inp[j]);
		f(inp, i + 1);
		swap(inp[i], inp[j]); // backtracking step
	}

}


int main() {

	char inp[] = "aabc";

	f(inp, 0);

	for (string permutation : s) {
		cout << permutation << " ";
	}

	cout << endl;

	return 0;
}
