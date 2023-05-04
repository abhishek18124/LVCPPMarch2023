// n <= 5

#include<iostream>

using namespace std;

void readString(char str[], char dlim = '\n') {
	char ch;
	int i=0;
	while(true) {
		ch = cin.get();
		if(ch == dlim) { // '\n' is the delimiting char
			break;
		}
		
		// str[i] = ch;
		// i++;

		str[i++] = ch;
	}

	str[i] = '\0';
}

int main() {

	char str[101];

	cout << "Enter a string : ";
	
	// cin >> str;

	// readString(str, '$');

	cin.getline(str, 5, '$'); // '\n' is a default argument

	cout << "You've entered : " << str << endl;

	return 0;
}