#include<iostream>
#include<cstring>

using namespace std;

int compareString(char* str1, char* str2) {
	int i = 0; // to iterate over str1
	int j = 0; // to iterate over str2

	while(str1[i] != '\0' and str2[j] != '\0') {
		if(str1[i] == str2[j]) {
			i++;
			j++;
		}

		if(str1[i] > str2[j]) {
			// str1 > str2
			return 1;
		}

		if(str1[i] < str2[j]) {
			// str1 < str2 {
			return -1;
		}
	}

	if(str1[i] == '\0' and str2[j] == '\0') {
		// str1 is equal to str2, why ? since all their characters match and they have same number of characters
		return 0;
	}

	if(str1[i] != '\0') {
		// str1 is not yet exhausted i.e. its length is greater than length of str2 : str1 > str2
		return 1;
	}

	// str2 is not yet exhausted i.e. its length is greater than length of str1 : str2 > str1

	return -1;


}

int main() {

	char str1[] = "zzx";
	char str2[] = "zzz";

	// int res = compareString(str1, str2);

	int res = strcmp(str1, str2);

	if(res == 0) {
		cout << str1 << " is equal to " << str2 << endl;
	} else if(res > 0) { // res == +1
		cout << str1 << " is greater than " << str2 << endl;
	} else { // res < 0 or res == -1
		cout << str2 << " is greater than " << str1 << endl;
	}

	return 0;
}