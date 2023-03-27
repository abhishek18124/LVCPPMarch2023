#include<iostream>

using namespace std;

int main() {

	int marks;
	cout << "enter your marks : ";
	cin >> marks;

	if(marks >= 91 and marks <= 100) {
		cout << "grade A" << endl;
	} else if(marks >= 81 and marks <= 90) {
		cout << "grade B" << endl;
	} else if(marks >= 71 and marks <= 80) {
		cout << "grade C" << endl;
	} else {
		cout << "grade D" << endl;
	}

	cout << "you are outside if-else-if block" << endl;
	
	return 0;
}