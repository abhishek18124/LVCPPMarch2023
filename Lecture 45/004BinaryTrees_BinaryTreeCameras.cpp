#include<iostream>

using namespace std;


// pair<int, pair<int, int>> {numCamera = .first, isMonitored = .second.first, hasCamera = .second.second}

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

class Triple {
public :

	int numCameras;
	bool isMonitored;
	bool hasCamera;

};

// Triple helper(TreeNode* root) {

// 	Triple t;

// 	// base case

// 	// todo ...

// 	// recursive case

// 	Triple left = helper(root->left);
// 	Triple right = helper(root->right);

// 	// make a decision for the root node

// 	if (left.isMonitored == false or right.isMonitored == false) {

// 		// you've to install a camera at the root node

// 		t.numCameras = left.numCameras + right.numCameras + 1;
// 		t.hasCamera = true;
// 		t.isMonitored = true;

// 		return t;

// 	}

// 	// you've not installed a camera at the root node

// 	t.numCameras = left.numCameras + right.numCameras;
// 	t.hasCamera = false;
// 	t.isMonitored = left.hasCamera == true or right.hasCamera == true ? true : false;

// 	return t;
// }

Triple helper(TreeNode* root) {

	Triple t;

	// base case

	if (root == NULL) {
		t.numCameras = 0;
		t.isMonitored = true;
		t.hasCamera = false;
		return t;
	}

	// if(root->left ==  NULL and root->right == NULL) {
	// 	t.numCameras = 0;
	// 	t.isMonitored = true;
	// 	t.hasCamera = false;
	// 	return t;
	// }

	// recursive case

	Triple left = helper(root->left);
	Triple right = helper(root->right);

	// make a decision for the root node

	if (!left.isMonitored or !right.isMonitored) {

		// you've to install a camera at the root node

		t.numCameras = left.numCameras + right.numCameras + 1;
		t.hasCamera = true;
		t.isMonitored = true; // since you've installed camera at the root

		return t;

	}

	// you've not installed a camera at the root node

	t.numCameras = left.numCameras + right.numCameras;
	t.hasCamera = false;
	t.isMonitored = left.hasCamera or right.hasCamera ? true : false;

	return t;
}


int minCameraCover(TreeNode* root) {

	Triple t = helper(root);
	cout << t.numCameras << " " << t.isMonitored << " " << t.hasCamera << " " << endl;
	// return t.numCameras;

	if (!t.isMonitored) { // t.isMonitored == false
		// root node is not monitored, therefore it is imp. to install camera at the root
		return t.numCameras + 1;
	}

	return t.numCameras;

}

int main() {

	TreeNode* root = NULL;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->left->left = new TreeNode(0);
	// root->left->left->left->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	// root = new TreeNode(0);

	// root->left = new TreeNode(0);
	// root->left->left = new TreeNode(0);
	// root->left->right = new TreeNode(0);

	// root->right = new TreeNode(0);
	// root->right->left = new TreeNode(0);
	// root->right->right = new TreeNode(0);

	// cout << minCameraCover(root) << endl;

	root = new TreeNode(0);

	root->left = new TreeNode(0);

	root->left->left = new TreeNode(0);
	root->left->left->left = new TreeNode(0);
	root->left->left->right = new TreeNode(0);

	root->left->right = new TreeNode(0);
	root->left->right->left = new TreeNode(0);
	root->left->right->right = new TreeNode(0);

	cout << minCameraCover(root) << endl;

	return 0;
}