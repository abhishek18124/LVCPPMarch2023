/*

	Implement a phonebook storing mapping between person's name and
	their phone numbers using an unordered_map.

*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int main() {

	unordered_map<string, vector<string>> phoneMap;

	phoneMap["Dinesh"].push_back("1234");
	phoneMap["Dinesh"].push_back("5678");

	phoneMap["Gautam"].push_back("9090");
	phoneMap["Gautam"].push_back("1010");
	phoneMap["Gautam"].push_back("4567");

	for (pair<string, vector<string>> p : phoneMap) {
		string key = p.first; // name of the person
		vector<string> value = p.second;  // phone numbers corr. to the person's name
		cout << key << " : ";
		for (string phoneNum : value) {
			cout << phoneNum << " ";
		}
		cout << endl;
	}



	return 0;
}