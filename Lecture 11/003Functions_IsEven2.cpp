#include<iostream>

using namespace std;

bool isEven(int n) {
	return n%2 == 0;
}

int main() {

	bool answer = isEven(5);

	cout << answer << endl;

	answer = isEven(6);

	cout << answer << endl;

	cout << isEven(7) << endl;

	cout << isEven(8) << endl;

	if(isEven(9)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}

	if(isEven(10)) {
		cout << "true" << endl;
	} else {
		cout << "false" << endl;
	}
	
	isEven(11) ? cout << "true" << endl : cout << "false" << endl;

	isEven(12) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}