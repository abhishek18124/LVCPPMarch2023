/*
	https://leetcode.com/problems/find-duplicate-subtrees/
*/

class Solution {
public:

	set<TreeNode*> s; // to track duplicate subtrees
	unordered_map<string, TreeNode*> hm;

	string dfs(TreeNode* root) {

		// base case

		if (root == NULL) {
			return "X";
		}

		// recursive case

		// construct a unique representation for the subTree rooted at the 'root' node

		string leftRepr = dfs(root->left);
		string rightRepr = dfs(root->right);

		string uniqueTreeRepr = to_string(root->val) + " " + leftRepr + " " + rightRepr;

		if (hm.find(uniqueTreeRepr) != hm.end()) {

			// you've found a duplicate subtree

			s.insert(hm[uniqueTreeRepr]);

		} else {

			hm[uniqueTreeRepr] = root;

		}

		return uniqueTreeRepr;

	}

	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		dfs(root);
		return vector<TreeNode*>(s.begin(), s.end());
	}
};