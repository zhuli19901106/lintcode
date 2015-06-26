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
     * @return: Postorder in vector which contains node values.
     */
    vector<int> postorderTraversal(TreeNode *root) {
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
		traverse(root->right);
		ans.push_back(root->val);
	}
};