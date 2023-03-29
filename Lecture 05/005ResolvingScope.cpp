#include<iostream>

using namespace std;

int x = 100;

int main() {

	cout << x << endl;

	int x = 10;

	cout << x << endl;

	// {
	// 	int y = 20;

	// 	cout << x << " " << y << endl;
		
	// }

	// // cout << y << endl; // 'y' is out of scope therefore this statement will lead to an error
	
	{
		int y = 20;
		int x = 30;

		cout << x << " " << y << endl;
	}

	return 0;
}