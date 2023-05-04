#include<iostream>
#include<cstring>

using namespace std;

void copyString(char* str1, char* str2) {
	
	int i = 0; // to iterate over char. of str1
	int j = 0; // to iterate over char. of str2

	while(str2[j] != '\0') {
		str1[i] = str2[j];
		i++;
		j++;
	}

	// all the char. of str2 have been copied into str1 except for the null character

	str1[i] = '\0';

}

int main() {

	char str1[100] = "abcd";
	char str2[] = "xyz";

	cout << "Before copy : " << str1 << endl;

	// copyString(str1, str2); // str2 will be copied into str1

	strcpy(str1, str2); // str2 will be copied into str1
	
	cout << "After copy : " << str1 << endl;

	return 0;
}