/*

Given an array of non-negative integers of size n, find the maximum possible XOR between
any two numbers present in the array.

Example:
	Input : x[] = {25, 10, 2, 8, 5, 3}
	Output: 28
	Explaination: The maximum result is 5 ^ 25 = 28

	Input: x[] = {1, 2, 3, 4, 5, 6, 7}
	Output: 7
	Explaination: The maximum result is 1 ^ 6 = 7

*/

#include<iostream>
#include<climits>

using namespace std;

class node {
public:

	node* left;  // indicates if node has a child that represents bit 0
	node* right; // indicates if node has a child that represents bit 1

	node() {
		this->left = NULL;
		this->right = NULL;
	}
};

class trie {

	node* root;

public:

	trie() {
		root = new node();
	}

	void insert(int n) {
		node* temp = root;
		for (int i = 31; i >= 0; i--) {
			int bit = (1 << i)&n;
			if (!bit) {
				// ith bit of n is 0, check if temp node has a left child or not
				if (!temp->left) {
					node* n = new node();
					temp->left = n;
				}
				temp = temp->left;
			} else {
				// ith bit of n is 1, check if temp node has a right child or not
				if (!temp->right) {
					node* n = new node();
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

	int helper(int n) {

		// find the maximum possible XOR involving 'n' in single XOR operation using trie

		node* cur = root;
		int XOR = 0;

		for (int i = 31; i >= 0; i--) {

			int ith_bit = (n >> i) & 1;
			if (ith_bit == 0) {
				// check if cur node has right child
				if (cur->right != NULL) {
					// ith bit of XOR can set
					XOR += (1 << i); // 1 * 2^i = 2^i
					cur = cur->right;
				} else {
					// ith bit of XOR cannot set
					cur = cur->left;
				}

			} else { // ith_bit == 1
				// check if cur node has left child
				if (cur->left != NULL) {
					// ith bit of XOR can set
					XOR += (1 << i);
					cur = cur->left;
				} else {
					// ith bit of XOR cannot set
					cur = cur->right;
				}
			}

		}

		cout <<  n << "^" << (n ^ XOR) << " = " << XOR << endl;

		return XOR;
	}

	int maximumXOR(int* x, int n) {
		int out = 0;
		for (int i = 0; i < n; i++) {
			out = max(out, helper(x[i]));
		}
		return out;
	}
};

int main() {

	int x[] = {10, 2, 8, 5, 4};
	int n = sizeof(x) / sizeof(int);

	trie t;

	for (int i = 0; i < n; i++) {
		t.insert(x[i]);
	}

	cout << t.maximumXOR(x, n) << endl;

	return 0;

}