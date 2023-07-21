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

TreeNode* previous = NULL;
TreeNode* first = NULL;
TreeNode* second = NULL;

void printInOrder(TreeNode* root) {

    // base case

    if (root == NULL) {
        return;
    }

    // recursive case

    // 1. recursively, print the inOrder traversal of the leftSubtree

    printInOrder(root->left);

    // 2. process the root node

    cout << root->val << " ";

    // 3. recursively, print the inOrder traversal fo the rightSubtree

    printInOrder(root->right);

}

void helper(TreeNode* root) {

    // base case

    if (root == NULL) {
        return;
    }

    // recursive case

    helper(root->left);

    if (previous != NULL and root->val < previous->val) {

        // you've found a violation of the BST property

        if (first == NULL) {
            first = previous; // previous is (i-1)th index
        }

        second = root; // root is ith index

    }

    previous = root;

    helper(root->right);

}

void recoverTree(TreeNode* root) {

    helper(root);
    swap(first->val, second->val);

}


int main() {

    TreeNode* root = new TreeNode(7);

    root->left = new TreeNode(3);

    root->left->left = new TreeNode(1);
    root->left->left->left = new TreeNode(0);
    root->left->left->right = new TreeNode(2);

    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(6);

    root->right = new TreeNode(8);
    root->right->right = new TreeNode(10);
    root->right->right->left = new TreeNode(4);
    root->right->right->right = new TreeNode(15);

    printInOrder(root); cout << endl;

    recoverTree(root);

    printInOrder(root);

    return 0;
}