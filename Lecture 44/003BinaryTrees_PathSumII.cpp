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


// vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

// 	// todo ...
// }

// void pathSum(TreeNode* root, int targetSum, vector<int>& path) {

// 	// base case

// 	if (root == NULL) {
// 		return;
// 	}

// 	if (root->left == NULL and root->right == NULL) {
// 		if (root->val == targetSum) {
// 			// you've found a valid path
// 			path.push_back(root->val);
// 			for (int node_val : path) {
// 				cout << node_val << " ";
// 			}
// 			cout << endl;
// 			path.pop_back();
// 		}
// 		return;
// 	}

// 	// recursive case

// 	path.push_back(root->val);

// 	pathSum(root->left, targetSum - root->val, path);
// 	pathSum(root->right, targetSum - root->val, path);

// 	path.pop_back(); // backtracking

// }

void pathSum(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& paths) {

	// base case

	if (root == NULL) {
		return;
	}

	if (root->left == NULL and root->right == NULL) {
		if (root->val == targetSum) {
			// you've found a valid path
			path.push_back(root->val);
			// for (int node_val : path) {
			// 	cout << node_val << " ";
			// }
			// cout << endl;
			paths.push_back(path);
			path.pop_back();
		}
		return;
	}

	// recursive case

	path.push_back(root->val);

	pathSum(root->left, targetSum - root->val, path, paths);
	pathSum(root->right, targetSum - root->val, path, paths);

	path.pop_back(); // backtracking

}


int main() {

	TreeNode* root = NULL;

	root = new TreeNode(5);

	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);

	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);

	int targetSum = 22;

	vector<int> path;

	// pathSum(root, targetSum, path);

	vector<vector<int>> paths;

	pathSum(root, targetSum, path, paths);

	for (vector<int> path : paths) {
		for (int node_val : path) {
			cout << node_val << " ";
		}
		cout << endl;
	}

	cout << endl;

	return 0;
}