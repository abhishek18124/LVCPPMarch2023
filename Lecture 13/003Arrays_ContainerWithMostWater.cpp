#include<iostream>

using namespace std;

// // approach 1 - time : O(n^2) space : O(1)

// int maximumArea(int height[], int n) {

// 	int maxArea = 0; // or INT_MIN

// 	for(int i=0; i<=n-2; i++) {

// 		for(int j=i+1; j<=n-1; j++) {

// 			// compute the area of the container formed using the ith and jth vertical line

// 			int w_ij = j-i;
// 			int h_ij = min(height[i], height[j]);
// 			int a_ij = w_ij * h_ij;

// 			maxArea = max(maxArea, a_ij);

// 		}

// 	}

// 	return maxArea;

// }


// approach 2 - time : O(n) space : O(1)

int maximumAreaOptimised(int height[], int n) {

	int maxArea = 0; // or INT_MIN

	int i = 0;
	int j = n-1;

	while(i < j) {

		// compute the area of the container formed using the ith and jth line

		maxArea = max(maxArea, (j-i) * min(height[i], height[j]));
		if(height[i] < height[j]) {
			i++;
		} else { // height[i] >= height[j]
			j--;
		}

	}

	return maxArea;

}

int main() {	

	int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	int n = sizeof(height)/sizeof(int);

	cout << maximumAreaOptimised(height, n) << endl;

	return 0;
}