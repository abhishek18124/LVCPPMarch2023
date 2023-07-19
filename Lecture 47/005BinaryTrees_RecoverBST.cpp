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

// void printInOrder(TreeNode* root) {

//     // base case

//     if (root == NULL) {
//         return;
//     }

//     // recursive case

//     // 1. recursively, print the inOrder traversal of the leftSubtree

//     printInOrder(root->left);

//     // 2. process the root node

//     cout << root->val << " ";

//     // 3. recursively, print the inOrder traversal fo the rightSubtree

//     printInOrder(root->right);

// }


// void storeInOrder(TreeNode* root, vector<TreeNode*>& inOrder) {

//     // base case

//     if (root == NULL) {
//         return;
//     }

//     // recursive case

//     // 1. recursively, print the inOrder traversal of the leftSubtree

//     storeInOrder(root->left, inOrder);

//     // 2. process the root node

//     inOrder.push_back(root);

//     // 3. recursively, print the inOrder traversal fo the rightSubtree

//     storeInOrder(root->right, inOrder);

// }

// void recoverTree(TreeNode* root) {

//     vector<TreeNode*> inOrder;

//     storeInOrder(root, inOrder);

//     TreeNode* first = NULL;
//     TreeNode* second = NULL;

//     int n = inOrder.size();

//     for (int i = 1; i < n; i++) {

//         if (inOrder[i]->val < inOrder[i - 1]->val) {

//             if (first == NULL) {

//                 // we've found the first violation of BST property at the (i-1)th index

//                 first = inOrder[i - 1];

//             }

//             second = inOrder[i];

//         }

//     }

//     swap(first->val, second->val);

// }


TreeNode* prev = NULL;
TreeNode* first = NULL;
TreeNode* second = NULL;

void helper(TreeNode* root) {

    // base case

    if (root == NULL) {
        return;
    }

    // recursive case

    helper(root->left);

    if (prev != NULL and root->val < prev->val) {

        // you've found a violation of the BST property

        if (first == NULL) {
            first = prev;
        }

        second = root;

    }

    prev = root;

    helper(root->right);

}

void recoverTree(TreeNode* root) {

    helper(root);
    swap(first->val, second->val);

}


int main() {

    // TreeNode* root = new TreeNode(7);

    // root->left = new TreeNode(3);

    // root->left->left = new TreeNode(1);
    // root->left->left->left = new TreeNode(0);
    // root->left->left->right = new TreeNode(2);

    // root->left->right = new TreeNode(5);
    // root->left->right->left = new TreeNode(9);
    // root->left->right->right = new TreeNode(6);

    // root->right = new TreeNode(8);
    // root->right->right = new TreeNode(10);
    // root->right->right->left = new TreeNode(4);
    // root->right->right->right = new TreeNode(15);

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);


    printInOrder(root); cout << endl;

    recoverTree(root);

    printInOrder(root);

    return 0;
}