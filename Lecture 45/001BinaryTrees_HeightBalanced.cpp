
/*
given the pre-order traversal of a binary tree, check if it is height balanced or not

Example
	Input : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1
	Output: true

	Input : 10 20 40 -1 -1 50 -1 -1 30 60 -1 -1 70 -1 -1
	Output: true

	Input : 10 20 30 -1 -1 -1 -1
	Output: false

*/

#include<iostream>
#include<cmath>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};


TreeNode* buildTree() {

	int val;
	cin >> val;

	// base case

	if (val == -1) {
		// construct an empty tree and return pointer to its root TreeNode
		return NULL;
	}

	// recursive case

	// 1. construct the root val using the first value of the given preOrder traversal

	TreeNode* root = new TreeNode(val);

	// 2. ask your friend to construct the leftSubtree from the preOrder traversal of the leftSubtree

	root->left = buildTree();

	// 3. ask your friend to construct the rightSubtree from the preOrder traversal of the rightSubtree

	root->right = buildTree();

	return root;

}

int computeHeight(TreeNode* root) {

	// base case

	if (!root) { // root == NULL
		// height of empty tree is -1
		return -1;
	}

	// recursive case

	// 1. recursively, compute the height of the leftSubtree
	int x = computeHeight(root->left);

	// 2. recursively, compute the height of the rightSubtree
	int y = computeHeight(root->right);

	return 1 + max(x, y);

}

// time : O(n^2)

bool checkHeightBalanced(TreeNode* root) {

	// base case
	if (root == NULL) {
		return true;
	}

	// recursive case

	// check if the given binary tree 'root' is heightBalanced or not

	// 1. recursively, check if the leftSubtree is heightBalanced or not
	bool leftIsBalanced = checkHeightBalanced(root->left);

	// 2. recursively, check if the rightSubtree is heightBalanced or not
	bool rightIsBalanced = checkHeightBalanced(root->right);

	// 3. check if the root node satisfied the heightBalance property

	bool rootIsBalanced = abs(computeHeight(root->left) - computeHeight(root->right)) <= 1 ? true : false;

	return leftIsBalanced and rightIsBalanced and rootIsBalanced;

}

class Pair {

public :

	int height;
	bool isBalanced;

};

// time : O(n)

Pair checkHeightBalancedEfficient(TreeNode* root) {

	Pair p;

	// base case

	if (root == NULL) {
		p.height = -1;
		p.isBalanced = true;
		return p;
	}

	// recursive case

	// 1. ask your friend to compute the height of the leftSubtree and simultaneously check if the leftSubtree is heightBalanced or not
	Pair left = checkHeightBalancedEfficient(root->left);

	// 2. ask your friend to compute the height of the rightSubtree and simultaneously check if the rightSubtree is heightBalanced or not
	Pair right = checkHeightBalancedEfficient(root->right);

	// 3. check if the root node satisfied the heightBalance property

	bool rootIsBalanced = abs(left.height - right.height) <= 1 ? true : false;

	p.height = 1 + max(left.height, right.height);
	p.isBalanced = left.isBalanced and right.isBalanced and rootIsBalanced;

	return p;

}

int main() {

	TreeNode* root = buildTree();

	checkHeightBalanced(root) ? cout << "height-balanced!" << endl :
	                                 cout << "not height-balanced" << endl;


	Pair p = checkHeightBalancedEfficient(root);

	p.isBalanced ? cout << "height-balanced!" << endl :
	                    cout << "not height-balanced" << endl;

	return 0;
}