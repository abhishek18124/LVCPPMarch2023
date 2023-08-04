#include<iostream>
#include<unordered_map>

using namespace std;

int main() {

	string s = "aabacbebebe";
	int n = s.size();
	int k = 3;

	int i=0; // to store the start of the window
	int j=0; // to store the end of the windw

	int max_len = 0; // to track the length of the longest substring
	                 // i.e. window that contain k unique characters
	
	int count = 0; // to keep track of no. of unique characters in the window
	
	unordered_map<char, int> freqMap; // to store a  mapping  between characters 
								      // present in a window & their frequencies
	
	while(j < n) {

		// expand the window

		// check for the violation of the window property
		
		// check for the validity of the window, and update the answer

		// continue expansion of the window
		j++;
	}

	cout << max_len << endl;

	return 0;
}