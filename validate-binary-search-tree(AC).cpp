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
     * @return: True if the binary tree is BST, or false
     */
    bool isValidBST(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        int lmin, rmax;
        return validate(root, lmin, rmax);
    }
private:
    bool validate(TreeNode *root, int &lmin, int &rmax) {
        int ll, lr, rl, rr;
        if (root->left != NULL) {
            if (!validate(root->left, ll, lr) || lr >= root->val) {
                return false;
            }
        } else {
            ll = lr = root->val;
        }
        lmin = ll;
        if (root->right != NULL) {
            if (!validate(root->right, rl, rr) || rl <= root->val) {
                return false;
            }
        } else {
            rl = rr = root->val;
        }
        rmax = rr;
        
        return true;
    }
};