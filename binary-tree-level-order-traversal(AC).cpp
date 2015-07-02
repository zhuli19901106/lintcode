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
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        ans.clear();
        if (root == NULL) {
            return ans;
        }
        preorder(root, 0);
        return ans;
    }
private:
    vector<vector<int> > ans;
    
    void preorder(TreeNode *root, int depth) {
        if (depth + 1 > ans.size()) {
            ans.push_back(vector<int>());
        }
        ans[depth].push_back(root->val);
        if (root->left != NULL) {
            preorder(root->left, depth + 1);
        }
        if (root->right != NULL) {
            preorder(root->right, depth + 1);
        }
    }
};