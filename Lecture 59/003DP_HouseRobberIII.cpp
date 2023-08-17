#include<iostream>
#include<unordered_map>

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

// recursive implementation

// int helper(TreeNode* root) {

//     // base case

//     if (root == NULL) {
//         return 0;
//     }

//     // recursive case

//     // make a decision for the root node

//     // 1. do not rob at the root node

//     int donotRobAtRoot = helper(root->left) + helper(root->right);

//     // 2. rob at the root node

//     int robAtRoot = root->val;

//     if (root->left != NULL) {
//         robAtRoot += helper(root->left->left) + helper(root->left->right);
//     }

//     if (root->right != NULL) {
//         robAtRoot += helper(root->right->left) + helper(root->right->right);
//     }

//     return max(donotRobAtRoot, robAtRoot);

// }

int helper(TreeNode* root, unordered_map<TreeNode*, int>& profitMap) {

    // lookup
    if (profitMap.find(root) != profitMap.end()) {
        return profitMap[root];
    }

    // base case

    if (root == NULL) {
        return profitMap[root] = 0;
    }

    // recursive case

    // make a decision for the root node

    // 1. do not rob at the root node

    int donotRobAtRoot = helper(root->left, profitMap) + helper(root->right, profitMap);

    // 2. rob at the root node

    int robAtRoot = root->val;

    if (root->left != NULL) {
        robAtRoot += helper(root->left->left, profitMap) + helper(root->left->right, profitMap);
    }

    if (root->right != NULL) {
        robAtRoot += helper(root->right->left, profitMap) + helper(root->right->right, profitMap);
    }

    return profitMap[root] = max(donotRobAtRoot, robAtRoot);

}


int rob(TreeNode* root) {

    // return helper(root);

    unordered_map<TreeNode*, int> profitMap;

    return helper(root, profitMap);

}

int main() {

    TreeNode* root = new TreeNode(3);

    root->left = new TreeNode(4);
    root->right = new TreeNode(5);


    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);


    root->right->right = new TreeNode(1);

    cout << rob(root) << endl;

    return 0;
}