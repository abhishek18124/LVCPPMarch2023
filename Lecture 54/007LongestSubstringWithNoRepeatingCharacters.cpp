#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "abcabcbb";
	int n = s.size();

	int i=0; // to store the start of the window
	int j=0; // to store the end of the windw

	int max_len = 0; // to track the  length of the longest substring
	                 // i.e. window that contain no unique characters
	
	unordered_map<char, int> freqMap; // to store a  mapping  between characters 
								      // present in a window & their frequencies
	
	while(j < n) {

		// expand the window

		// check for the violation of the window property
		
		// update the answer

		// continue expansion of the window
		j++;
	}

	cout << max_len << endl;

	return 0;
}