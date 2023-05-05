// strlen <= 100 

#include<iostream>
#include<cstring>

using namespace std;

int main() {

	int n;
	cout << "Enter the no. of strings : ";
	cin >> n;

	cin.ignore();

	// cin.get();

	char inp[101]; // based on the constraints
	cin.getline(inp, 101); // '\n' is the default delimiting
	// cin >> inp; // assume i/p string doesn't have whitespace

	// cout << inp << endl;

	char lsf[101]; // to track the largest of 'n' string
	strcpy(lsf, inp);

	for(int i=2; i<=n; i++) {
		cout << "." << endl;
		cin >> inp;
		if(strcmp(inp, lsf) > 0) {
			// inp that you've read is greather lsf
			strcpy(lsf, inp);
		}
	}

	cout << lsf << endl;

	return 0;
}
