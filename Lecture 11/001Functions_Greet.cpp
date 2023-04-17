#include<iostream>

using namespace std;

void greet() {
	cout << "hello world" << endl;
	return; // optional
}

int main() {

	cout << "inside the main() : before greet()" << endl;

	greet();

	cout << "inside the main() : after greet()" << endl;
	
	return 0;
}