/*

Design a recursive algorithm to build a binary tree given its pre-order traversal.

eg: preOrder : 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1

*/

#include<iostream>

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


void printPreOrder(TreeNode* root) {

	// base case
	if (!root) { // root == NULL
		cout << -1 << " ";
		return;
	}

	// recursive case

	// 1. process the root TreeNode
	cout << root->val << " ";

	// 2. do the preOrder traversal of the leftSubtree
	printPreOrder(root->left);

	// 3. do the preOrder traversal of the rightSubtree
	printPreOrder(root->right);

}

// 10 20 40 -1 -1 50 70 -1 -1 -1 30 -1 60 -1 -1

TreeNode* buildTree() {

	int val;
	cin >> val;

	if (val == -1) {
		return NULL;
	}

	// 1. create the root node

	TreeNode* root = new TreeNode(val);

	// 2. recursively, create the leftSubtree using the preOrder traversal of the leftSubtree

	root->left = buildTree();

	// 3. recursively, create the rightSubtree using the preOrder traversal of the rightSubtree

	root->right = buildTree();

	return root;

}

int main() {

	TreeNode* root = NULL;

	root = buildTree();

	printPreOrder(root);

	cout << endl;

	return 0;
}