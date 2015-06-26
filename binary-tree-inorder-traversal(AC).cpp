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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
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
		traverse(root->left);
		ans.push_back(root->val);
		traverse(root->right);
	}
};