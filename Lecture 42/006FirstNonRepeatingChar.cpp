#include<iostream>
#include<queue>

using namespace std;

int main() {

	int freqMap[26] = {};
	queue<char> q;

	char ch;

	while (true) {

		cin >> ch;

		freqMap[ch - 'a']++;
		if (freqMap[ch - 'a'] == 1) {
			// 'ch' is currently a non-repeating char
			q.push(ch);
		}

		// find the 1st non-repeating char. in the stream after reading ch

		while (!q.empty() and freqMap[q.front() - 'a'] > 1) {
			// char. at the front of the queue is no longer non-repeating
			q.pop();
		}

		if (q.empty()) {
			// stream doesn't have a non-repeating char
			cout << -1 << " ";
		} else {
			// front of the queue is the first non-repeating char. in the stream after reading ch
			cout << q.front() << " ";
		}

	}

	return 0;
}