#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class customer {

public:

	string name; 
	int age;
	char gender;
	double credits;
	
	customer(string name, int age, char gender, double credits) {
		this->name = name;
		this->age = age;
		this->gender = gender;
		this->credits = credits;
	}	
};

/* 
	return 'true' when a swap isn't required.

*/

bool myComparator(customer c1, customer c2) {
	// if(c1.credits > c2.credits) {
	// 	// no swap is needed if you want to sort the vector in the dec. order based on credits
	// 	return true;
	// }
	// // swap is needed 
	// return false;

	return c1.credits > c2.credits;
}

bool myNameComparator(customer c1, customer c2) {
	// if(c1.name < c2.name) {
	// 	// no swap is needed if you want to sort the vector in the inc. order based on names
	// 	return true;
	// }
	// // swap is needed 
	// return false;

	return c1.name < c2.name;
}

int main() {

	vector<customer> v;

	v.push_back(customer("unnati", 18, 'F', 1500));
	v.push_back(customer("aman", 19, 'M', 1000));
	v.push_back(customer("dinesh", 21, 'M', 500));
	v.push_back(customer("deepika", 20, 'F', 2000));
	
	for(customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	cout << endl;

	sort(v.begin(), v.end(), myComparator); // sort customers based on credits in the decreasing order

	for(customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	cout << endl;

	sort(v.begin(), v.end(), myNameComparator); // sort customers based on names in the increasing order

	for(customer c : v) {
		cout << c.name << " " << c.age << " " << c.gender << " " << c.credits << endl;
	}

	return 0;

}




