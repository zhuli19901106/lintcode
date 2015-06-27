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
     * @param node: insert this node into the binary search tree
     * @return: The root of the new binary search tree.
     */
    TreeNode* insertNode(TreeNode* root, TreeNode* node) {
        if (root == NULL) {
            return node;
        }
        TreeNode *ptr = root;
        while (true) {
            if (node->val < ptr->val) {
                if (ptr->left == NULL) {
                    ptr->left = node;
                    break;
                } else {
                    ptr = ptr->left;
                }
            } else if (node->val > ptr->val) {
                if (ptr->right == NULL) {
                    ptr->right = node;
                    break;
                } else {
                    ptr = ptr->right;
                }
            } else {
                break;
            }
        }
        return root;
    }
};