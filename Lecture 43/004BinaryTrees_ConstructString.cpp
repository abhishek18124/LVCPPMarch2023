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

string tree2str(TreeNode* root) {

	// base case

	if (root == NULL) {
		// tree is empty
		return "";
	}

	// recursive case

	// 1. recursively, construct the string corresponding to the leftSubtree
	string leftRepr = tree2str(root->left);

	// 2. recursively, construct the string corresponding to the rightSubtree
	string rightRepr = tree2str(root->right);

	if (leftRepr != "" and rightRepr != "") {
		return to_string(root->val) + "(" + leftRepr + ")(" + rightRepr + ")";
	}

	if (leftRepr != "") { // rightRepr == ""
		return to_string(root->val) + "(" + leftRepr + ")";
	}

	if (rightRepr != "") {
		return to_string(root->val) + "(?)(" + rightRepr + ")";
	}

	return to_string(root->val);

}


int main() {

	TreeNode* root = buildTree();
	cout << tree2str(root) << endl;

	return 0;
}