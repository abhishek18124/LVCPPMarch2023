#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "caaabbbaaaccabbabba";
	int n = s.size();
	int k = 2;

	int i = 0; // to store the start of the window
	int j = 0; // to store the end of the windw

	int max_len = 0; // to track the length of the longest substring
	// i.e. window that contain k unique characters

	int count = 0; // to keep track of no. of unique characters in the window

	unordered_map<char, int> freqMap; // to store a  mapping  between characters
	// present in a window & their frequencies

	// time : O(n)

	// space : O(n) due to freqMap e.g. assume all the characters in the i/p are non-repeating characters

	while (j < n) {

		// expand the window [include the jth character into the window]
		char ch = s[j];
		freqMap[ch]++;
		if (freqMap[ch] == 1) {
			// 'ch' is a unique character
			count++;
		}

		// check for the violation of the window property

		if (count > k) {
			// shrink the window
			while (count > k) {
				// exclude the ith character from the window
				freqMap[s[i]]--;
				if (freqMap[s[i]] == 0) {
					count--;
				}
				i++;
			}
		}

		// check for the validity of the window, and update the answer
		if (count == k) {
			max_len = max(max_len, j - i + 1);
		}

		// continue expansion of the window
		j++;
	}

	cout << max_len << endl;

	return 0;
}