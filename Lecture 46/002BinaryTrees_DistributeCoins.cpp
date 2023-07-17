#include<iostream>
#include<vector>

using namespace std;

class TreeNode {

public :

	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}

};

int numMoves = 0; // to track the minimum no. of moves required to distribute the coins

int helper(TreeNode* root) {

	// base case

	if (root == NULL) {
		return 0;
	}

	// recursive case

	int leftReq = helper(root->left);
	int rightReq = helper(root->right);

	numMoves += abs(leftReq) + abs(rightReq);

	return (leftReq + rightReq + 1) - root->val;

}

int distributeCoins(TreeNode* root) {

	helper(root);
	return numMoves;

}

int main() {

	TreeNode* root = NULL;

	root = new TreeNode(3);

	root->left = new TreeNode(0);
	root->right = new TreeNode(0);

	distributeCoins(root);

	cout << numMoves << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(3);
	// root->right = new TreeNode(0);

	// distributeCoins(root);

	// cout << numMoves << endl;

	return 0;
}