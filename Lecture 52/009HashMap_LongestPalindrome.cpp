#include<iostream>
#include<unordered_set>

using namespace std;

int main() {

	string str = "aabbccccddef";
	unordered_set<int> seen;
	int len = 0;

	for (char ch : str) {
		if (seen.find(ch) != seen.end()) {
			// you've seen 'ch' previously
			len += 2;
			seen.erase(ch);
		} else {
			seen.insert(ch);
		}
	}

	if (seen.size() > 0) {
		// we are left with characters in the set which could not be paired
		// so you can use any one of them to form an odd length palindrome
		len++;
	}

	cout << len << endl;


	return 0;
}