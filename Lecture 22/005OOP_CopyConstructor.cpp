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

		customer(customer& c) {
			cout << "\nI am inside the copy constructor of the customer class\n" << endl;
			strcpy(name, c.name);
			age = c.age;
			gender = c.gender;
			credits = c.credits;
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
	
	customer c1("naruto", 32, 'M', 5000);

	customer c2 = c1; // or customer c2(c1)

	c2.printCustomerInfo();

	customer c3(c1);

	c3.printCustomerInfo();

	return 0;
}