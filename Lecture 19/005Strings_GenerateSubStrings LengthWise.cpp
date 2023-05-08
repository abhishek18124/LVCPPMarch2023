#include<iostream>
#include<algorithm>

using namespace std;

int main() {

	string str = "abcde";
	int n = str.size();

	for(int l=1; l<=n; l++) {

		// generate all the subString of the given string 'str' of length 'l'

		// iterate over all the possible starting indices for subString of length 'l'

		for(int i=0; i<=n-l; i++) {

			cout << str.substr(i, l) << endl;

		}

		cout << endl;

	}
	
	return 0;
}