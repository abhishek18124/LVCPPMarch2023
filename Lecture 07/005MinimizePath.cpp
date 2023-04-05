#include<iostream>

using namespace std;

int main() {

	int x = 0; // to track the net movement along the x-axis
	int y = 0; // to track the net movement along the y-axis

	char ch;

	while(true) {
		ch = cin.get();
		if(ch == '\n') {
			break;
		}

		if(ch == 'E') {
			x++;
		} else if(ch == 'W') {
			x--;
		} else if(ch == 'N') {
			y++;
		} else { // ch == 'S'
			y--;
		}
	}

	cout << "(" << x << ", " << y << ")" << endl;

	if(x > 0) {
		// print 'E' x times
		for(int i=1; i<=x; i++) {
			cout << 'E';
		}
	}

	if(y > 0) {
		// print 'N' y times
		for(int i=1; i<=y; i++) {
			cout << 'N';
		}
	}

	if(y < 0) {
		// print 'S' -y times
		for(int i=1; i<=-y; i++) { // instead of -y, you can use abs(y)
			cout << 'S';
		}
	}

	if(x < 0) {
		// print 'W' -x times
		for(int i=1; i<=-x; i++) {
			cout << 'W';
		}
	}
	
	return 0;
}