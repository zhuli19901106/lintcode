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
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        ans.clear();
        ll = k1;
        rr = k2;
        
        inorder(root);
        return ans;
    }
private:
    vector<int> ans;
    int ll;
    int rr;
    
    void inorder(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        if (root->val > ll) {
            inorder(root->left);
        }
        if (root->val >= ll && root->val <= rr) {
            ans.push_back(root->val);
        }
        if (root->val < rr) {
            inorder(root->right);
        }
    }
};