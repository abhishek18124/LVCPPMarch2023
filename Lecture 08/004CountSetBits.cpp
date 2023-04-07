#include<iostream>
#include<cmath>
#include<bit>

using namespace std;

int main() {

	int n = 15;
	int count = 0;

	// for(int k=0; k<=31; k++) {
	// 	// check if kth bit of n is set
		
	// 	// if((n>>k)&1) {
	// 	// 	// kth bit of n is set
	// 	// 	count++;
	// 	// }

	// 	if((1<<k)&n) {
	// 		// kth bit of n is set
	// 		count++;
	// 	}
	// }

	for(int k=0; k<ceil(log2(n+1)); k++) {
		// check if kth bit of n is set
		
		if((1<<k)&n) {
			// kth bit of n is set
			count++;
		}
	}

	cout << count << endl; 

	cout << __builtin_popcount(n) << endl;
	
	return 0;
}