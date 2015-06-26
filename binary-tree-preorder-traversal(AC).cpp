/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
		ans.clear();
		traverse(root);
		return ans;
    }
private:
	vector<int> ans;
	
	void traverse(TreeNode *root) {
		if (root == NULL) {
			return;
		}
		ans.push_back(root->val);
		traverse(root->left);
		traverse(root->right);
	}
};