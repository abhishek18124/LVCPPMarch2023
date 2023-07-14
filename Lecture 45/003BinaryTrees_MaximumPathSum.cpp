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

class Pair {

public :

	int maxPathSum;
	int maxRootStartPathSum;

};

Pair helper(TreeNode* root) {

	Pair p;

	// base case

	if (root == NULL) {
		p.maxPathSum = INT_MIN;
		p.maxRootStartPathSum = 0;
		return p;
	}

	// recursive case

	Pair left  = helper(root->left);
	Pair right = helper(root->right);

	// compute the maximum path sum for a path that goes through the root node

	int rootMaxPathSum = max({root->val,
	                          root->val + left.maxRootStartPathSum,
	                          root->val + right.maxRootStartPathSum,
	                          left.maxRootStartPathSum + root->val + right.maxRootStartPathSum
	                         });


	p.maxPathSum = max({left.maxPathSum,
	                    right.maxPathSum,
	                    rootMaxPathSum
	                   });

	p.maxRootStartPathSum = max({root->val,
	                             root->val + left.maxRootStartPathSum,
	                             root->val + right.maxRootStartPathSum
	                            });

	return p;
}

int maxPathSum(TreeNode* root) {

	Pair p = helper(root);
	return p.maxPathSum;

}

int main() {

	TreeNode* root = NULL;

	// root = new TreeNode(-5);

	// root->left = new TreeNode(1);
	// root->left->left = new TreeNode(2);
	// root->left->right = new TreeNode(3);

	// root->right = new TreeNode(4);

	// cout << maxPathSum(root) << endl;

	// root = new TreeNode(-7);

	// root->left = new TreeNode(3);

	// root->right = new TreeNode(4);
	// root->right->left = new TreeNode(5);
	// root->right->right = new TreeNode(6);

	// cout << maxPathSum(root) << endl;

	root = new TreeNode(7);

	root->left = new TreeNode(1);
	root->left->left = new TreeNode(2);
	root->left->right = new TreeNode(-3);

	root->right = new TreeNode(4);
	root->right->left = new TreeNode(-5);
	root->right->right = new TreeNode(6);

	cout << maxPathSum(root) << endl;

	return 0;
}