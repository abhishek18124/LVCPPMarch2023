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

		customer(customer& c) {
			cout << "I am inside the copy constructor of the customer class" << endl;
			name = new char[100]; // ensures we do deep copy
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
		
	customer c("aman", 19, 'M', 1000.5);

	customer c2(c);

	strcpy(c2.name, "dinesh");

	cout << c.name << " " << c2.name << endl;
		
	return 0;
}