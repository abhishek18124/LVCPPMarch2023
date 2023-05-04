#include<iostream>

using namespace std;

int main() {

	char str1[] = {'a', 'b', 'c', 'd', 'e', '\0'};

	cout << str1 << endl;

	char str2[] = "coding"; // '\0' is auto. added at the end of the string

	cout << str2 << endl;

	// char str3[5] = "hello"; // error

	return 0;
}