#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

// time : ~n/2 steps is O(n)

void reverseString(char* str) {

	int i = 0;
	int j = strlen(str)-1;

	while(i < j) {
		swap(str[i], str[j]);
		i++;
		j--;
	}

}

int main() {

	char str[] = "hello";
	int n = strlen(str);

	cout << "Original string : " << str << endl;

	// reverseString(str);

	// reverse(str+1, str+3);

	cout << "Reversed  string after 1st reverse : " << str << endl; 


	return 0;
}