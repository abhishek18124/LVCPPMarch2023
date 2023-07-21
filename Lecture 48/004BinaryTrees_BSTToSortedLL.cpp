/*

	Given a BST, design an algorithm transform it into a sorted linked list in-place.

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

class Pair {

public :

	TreeNode* head;
	TreeNode* tail;

};

// time : O(n) space : O(h) due to height of function call-stack

Pair convert(TreeNode* root) {

	Pair p;

	// base case

	if (root == NULL) {
		p.head = p.tail = NULL;
		return p;
	}

	// recursive case

	// 1. recursively, convert the leftSubtree which is a BST into a sorted linkedList

	Pair left = convert(root->left);

	if (left.head != NULL) {
		left.tail->right = root;
		p.head = left.head;
	} else {
		p.head = root;
	}

	// 2. recursively, convert the rightSubtree which is a BST into a sorted linkedList

	Pair right = convert(root->right);

	if (right.head != NULL) {
		root->right = right.head;
		p.tail = right.tail;
	} else {
		p.tail = root;
	}

	return p;

}


void printLinkedList(TreeNode* head) {
	while (head != NULL) {
		cout << head->val << " ";
		head = head->right;
	}

	cout << endl;
}


int main() {

	TreeNode* root = new TreeNode(10);

	root->left = new TreeNode(5);
	root->left->left  = new TreeNode(3);
	root->left->right = new TreeNode(7);

	root->right = new TreeNode(15);
	root->right->left  = new TreeNode(13);
	root->right->right = new TreeNode(17);

	Pair p = convert(root);

	printLinkedList(p.head);

	return 0;
}