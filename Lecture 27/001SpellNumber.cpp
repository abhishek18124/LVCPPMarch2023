#include<iostream>

using namespace std;

string spellingMap[] = { "zero", "one", "two", "three",
                         "four", "five", "six", "seven",
                         "eight", "nine"
                       };

void spellNumber(int n) {

	// base case
	if (n == 0) {
		return;
	}

	// recursive case

	// ask your friend to print the spelling of n/10

	spellNumber(n / 10);

	int d = n % 10;

	cout << spellingMap[d] << " ";

}

int main() {

	int n = 12345;

	spellNumber(n);

	return 0;
}