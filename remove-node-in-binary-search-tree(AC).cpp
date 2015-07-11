// The BST can be in reversed order
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
     * @param value: Remove the node with given value.
     * @return: The root of the binary search tree after removal.
     */
    TreeNode *removeNode(TreeNode *root, int value) {
        if (root == NULL) {
            return NULL;
        }
        
        TreeNode *par, *cur;
        bool invert = false;
        if (root->left != NULL && root->val < root->left->val) {
            invert = true;
        }
        if (root->right != NULL && root->val > root->right->val) {
            invert = true;
        }
        
        par = NULL;
        cur = root;
        while (cur != NULL && cur->val != value) {
            par = cur;
            if (value < cur->val && !invert) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
        if (cur == NULL) {
            // Value not found
            return root;
        }
        if (cur->left == NULL && cur->right == NULL) {
            // Removing a leaf node
            if (cur == root) {
                // The tree is empty now
                delete root;
                return NULL;
            }
            if (par->left == cur) {
                delete par->left;
                par->left = NULL;
            } else {
                delete par->right;
                par->right = NULL;
            }
            return root;
        }
        
        TreeNode *ptr;
        int newVal;
        if (cur->left != NULL) {
            ptr = cur->left;
            while (ptr->right != NULL) {
                ptr = ptr->right;
            }
        } else {
            ptr = cur->right;
            while (ptr->left != NULL) {
                ptr = ptr->left;
            }
        }
        newVal = ptr->val;
        removeNode(cur, newVal);
        cur->val = newVal;
        return root;
    }
};