#include<iostream>
#define PI 3.14
#define PRINT cout << 
#define SEMICOLON ;
#define NEWLINE endl
#define F for(int i=1; i<=5; i++) {cout << i << " ";}
#define F2(n) for(int i=1; i<=n; i++) {cout << i << " ";}

using namespace std;

int main() {
	
	// int PI = 3.14; // error

	// cout << 2*PI << endl;
	
	PRINT 2*PI << NEWLINE SEMICOLON

	// F

	F2(100)

	return 0;
}