#include<iostream>

using namespace std;

class customer {
	public :
		char* name;
		int age;
		char gender;
		double credits;

		customer(char* n, int a, char g, double c) {
			cout << "I am inside the parameterised constructor of the customer class" << endl;
			name = new char[100];
			strcpy(name, n);
			age = a;
			gender = g;
			credits = c;
		}

		customer() {}

		void printCustomerInfo() {
			cout << "\nCustomer Information\n";
			cout << "Name : " << name << endl;
			cout << "Age : " << age << endl;
			cout << "Gender : " << gender << endl;
			cout << "Credits : " << credits << endl;
		}

};

int main() {
	
	customer c("aman", 19, 'M', 1000.5);

	c.printCustomerInfo();

	// customer c2(c); // default copy constructor is used here

	customer c2;
	c2 = c; // default copy assignment 

	c2.printCustomerInfo();

	c2.age = 21;
	c2.credits = 1001.5;

	cout << c.age << " " << c2.age << endl;
	cout << c.credits << " " << c2.credits << endl;

	strcpy(c2.name, "dinesh");

	cout << c.name << " " << c2.name << endl;


	return 0;
}