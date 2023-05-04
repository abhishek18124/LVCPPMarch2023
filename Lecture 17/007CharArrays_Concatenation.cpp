// n : strlen(str1) <= 50 and m : strlen(str1) <= 50

#include<iostream>
#include<cstring>

using namespace std;

void concatString(char* str1, char* str2) {
	
	int i = strlen(str1); // to iterate over char. of str1
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

	char str1[101] = "hello";
	char str2[] = "world";

	cout << "Before concat : " << str1 << endl;

	// concatString(str1, str2);
	strcat(str1, str2);

	cout << "After concat : " << str1 << endl;

	return 0;
}