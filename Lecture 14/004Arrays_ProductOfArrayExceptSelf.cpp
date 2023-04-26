// contraints : n <= 100

#include<iostream>

using namespace std;

int main() {

	int nums[] = {1, 2, 3, 4, 5};
	int n = sizeof(nums) / sizeof(int);

	int answer[100]; // based on the contraints

	// // approach 1 : time : O(n^2) 

	// for(int i=0; i<n; i++) {

	// 	// compute answer[i] = li * ri

	// 	// li : it is the product of all the elements in nums in the range 0 to i-1

	// 	int li = 1;
	// 	for(int j=0; j<=i-1; j++) {
	// 		li *= nums[j];
	// 	}

	// 	// ri : it is the product of all the elements in nums in the range i+1 to n-1

	// 	int ri = 1;
	// 	for(int j=i+1; j<=n-1; j++) {
	// 		ri *= nums[j];
	// 	}

	// 	answer[i] = li * ri;

	// }

	// approach 2 : time n(to compute l[]) + n(to compute r[]) + n(to compute ans[]) = 3n ~ O(n)
	// space : n (for l[]) + n (for r[]) = 2n extra space is needed as compared to prev. approach ~ O(n)

	int l[100]; // based on contraints

	l[0] = 1;
	for(int i=1; i<=n-1; i++) {
		l[i] = l[i-1]*nums[i-1];
	}

	int r[100]; // based on contraints
	r[n-1] = 1;
	for(int i=n-2; i>=0; i--) {
		r[i] = r[i+1]*nums[i+1];
	}

	for(int i=0; i<=n-1; i++) {

		answer[i] = l[i] * r[i];

	}

	for(int i=0; i<n; i++) {
		cout << answer[i] << " ";
	}

	cout << endl;
	
	return 0;
}