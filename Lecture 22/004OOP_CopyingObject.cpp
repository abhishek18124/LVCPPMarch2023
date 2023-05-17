#include<iostream>

using namespace std;

class customer {
	public :
		char name[100];
		int age;
		char gender;
		double credits;

		customer(char* n, int a, char g, double c) {
			cout << "I am inside the parameterised constructor of the customer class" << endl;
			strcpy(name, n);
			age = a;
			gender = g;
			credits = c;
		}

		customer() {
			cout << "\nI am inside the default constructor of the customer class\n";
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

	c1.printCustomerInfo();

	customer c2 = c1; // default copy constructor

	c2.printCustomerInfo();

	c2.age = 22;

	cout << c1.age << " " << c2.age << endl;

	strcpy(c2.name, "dinesh");

	cout << c1.name << " " << c2.name << endl;

	customer c3; // default constructed

	c3 = c1; // default copy assignment operator

	c3.printCustomerInfo();

	c3.age = 18;

	cout << c1.age  << " " << c3.age << endl;

	return 0;
}


 


