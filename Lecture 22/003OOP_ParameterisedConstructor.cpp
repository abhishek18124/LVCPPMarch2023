#include<iostream>

using namespace std;

class customer {
	public :
		char name[100];
		int age;
		char gender;
		double credits;

		customer(char* n, int a, char g, double c) {
			cout << "\nI am inside the parameterised constructor of the customer class\n" << endl;
			strcpy(name, n);
			age = a;
			gender = g;
			credits = c;
		}

		customer() {
			cout << "I am inside the default constructor of the customer class" << endl;
		}

		void printCustomerInfo() {
			cout << "\nCustomer Information\n";
			cout << "Name : " << name << endl;
			cout << "Age : " << age << endl;
			cout << "Gender : " << gender << endl;
			cout << "Credits : " << credits << endl;
		}

};

int main() {

	customer c1("abhishek", 20, 'M', 1000.51);

	c1.printCustomerInfo();

	customer c2("aman", 21, 'M', 500.19);

	c2.printCustomerInfo();

	customer c3;

	return 0;
}