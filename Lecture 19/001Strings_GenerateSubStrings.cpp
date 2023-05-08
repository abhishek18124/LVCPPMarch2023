#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	string str = "abcde";
	int n = str.size();

	// iterate over all the possible starting indices for a substring 'i'

	for(int i=0; i<=n-1; i++) {

		// for a given starting index 'i', iterate over all the possible ending indices 'j'

		for(int j=i; j<=n-1; j++) {

			// extract the subString that starts at index 'i' and ends at index 'j'

			// for(int k=i; k<=j; k++) {
			// 	cout << str[k];
			// }

			// cout << endl;

			cout << str.substr(i, j-i+1) << endl;


		}

		cout << endl;

	}
	
	return 0;
}