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

int numCameras = 0;

int helper(TreeNode* root) {

	// base case

	if (root == NULL) {
		return 1;
	}

	// recursive case

	int leftStatus  = helper(root->left);
	int rightStatus = helper(root->right);

	if (leftStatus == 0 or rightStatus == 0) {
		// install a camera at the root node
		numCameras++;
		return 2;
	}

	// do not install camera at the root node

	return leftStatus == 2 or rightStatus == 2 ? 1 : 0;

}

void minCameraCover(TreeNode* root) {

	int rootStatus = helper(root);

	if (rootStatus == 0) {
		// root node is not monitored, therefore install a camera at the root
		numCameras++;
	}

	cout << numCameras << endl;

}

int main() {

	TreeNode* root = NULL;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// minCameraCover(root);

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->left->left = new TreeNode(0);
	// root->left->left->left->right = new TreeNode(0);

	// minCameraCover(root);

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// root->right = new TreeNode(0);
	// root->right->left = new TreeNode(0);
	// root->right->right = new TreeNode(0);

	// minCameraCover(root);

	root = new TreeNode(0);

	root->left = new TreeNode(0);

	root->left->left = new TreeNode(0);
	root->left->left->left = new TreeNode(0);
	root->left->left->right = new TreeNode(0);

	root->left->right = new TreeNode(0);
	root->left->right->left = new TreeNode(0);
	root->left->right->right = new TreeNode(0);

	minCameraCover(root);

	return 0;
}