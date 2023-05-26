#include<iostream>

using namespace std;

int f(int x, int y) {

	// base case

	if (y == 0) {
		// compute x*0
		return 0;
	}

	// recursive case

	// 1. recursively compute x*y-1 i.e. add 'x' (y-1) times i.e. ask your friend to find x*(y-1)

	// int A = f(x, y - 1);

	return x + f(x, y - 1);

}

int main() {

	int x = 7;
	int y = 2;

	cout << f(x, y) << endl;

	return 0;
}