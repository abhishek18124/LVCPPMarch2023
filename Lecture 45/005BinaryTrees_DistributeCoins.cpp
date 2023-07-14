#include<iostream>

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

int distributeCoins(TreeNode* root) {

	// base case

	// todo ...

	// recursive case

	// todo ...

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