/*

	Given a binary tree, design an algorithm to check if is a BST or not.

*/

#include<iostream>
#include<climits>

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

// int findMinimum(TreeNode* root) {

// 	// base case

// 	if (root == NULL) {
// 		return INT_MAX;
// 	}

// 	while (root->left != NULL) {
// 		root = root->left;
// 	}

// 	// root is pointing to the leftMost node / minimumValue node

// 	return root->val;
// }


// int findMaximum(TreeNode* root) {

// 	if (root == NULL) {
// 		return INT_MIN;
// 	}

// 	while (root->right != NULL) {
// 		root = root->right;
// 	}

// 	// root is pointing to the rightMost node / maximumValue node

// 	return root->val;

// }


// bool checkBST(TreeNode* root) {

// 	// base case

// 	if (root == NULL) {
// 		return true;
// 	}

// 	// recursive case

// 	// 1. recursively, check if the leftSubtree is a BST
// 	bool leftIsBST = checkBST(root->left);

// 	// 2. recursively, check if the rightSubtree is a BST
// 	bool rightIsBST = checkBST(root->right);

// 	// 3. check if the BST property is satisfied at the rootNode

// 	bool rootIsBST = root->val > findMaximum(root->left) and root->val < findMinimum(root->right);

// 	return leftIsBST and rightIsBST and rootIsBST;

// }

// class Triple {

// public :

// 	bool isBST;
// 	int minVal;
// 	int maxVal;

// };

// Triple checkBSTEfficient(TreeNode* root) {

// 	Triple t;

// 	// base case

// 	if (root == NULL) {
// 		t.isBST = true;
// 		t.maxVal = INT_MIN;
// 		t.minVal = INT_MAX;
// 		return t;
// 	}

// 	// recursive case

// 	Triple left = checkBSTEfficient(root->left);

// 	Triple right = checkBSTEfficient(root->right);

// 	// 3. check if the BST property is satisfied at the rootNode

// 	bool rootIsBST = root->val > left.maxVal and root->val < right.minVal;

// 	t.isBST = left.isBST and right.isBST and rootIsBST;
// 	t.minVal = min({left.minVal, right.minVal, root->val});
// 	t.maxVal = min({left.maxVal, right.maxVal, root->val});

// 	return t;


// }

bool checkBSTRange(TreeNode* root, int lo, int hi) {

	// base case

	if (root == NULL) {
		return true;
	}

	// recursive case

	return root->val > lo and root->val < hi and
	       checkBSTRange(root->left, lo, root->val) and
	       checkBSTRange(root->right, root->val, hi);

}


int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(0);

	// checkBST(root) ? cout << "true" << endl :
	//                       cout << "false" << endl;

	// Triple t = checkBSTEfficient(root);

	// t.isBST ? cout << "true" << endl :
	//                cout << "false" << endl;

	int lo = INT_MIN;
	int hi = INT_MAX;

	checkBSTRange(root, lo, hi) ? cout << "true" << endl : cout << "false" << endl;

	return 0;
}