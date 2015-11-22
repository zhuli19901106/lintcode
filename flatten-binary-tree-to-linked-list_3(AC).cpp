// What a magic, I couldn't figure it out on my own.
// http://n00tc0d3r.blogspot.com/2013/03/flatten-binary-tree-to-linked-list-in.html
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        TreeNode *cur = root;
        TreeNode *pre;
        
        while (cur != NULL) {
            if (cur->right == NULL) {
                cur->right = cur->left;
            } else if (cur->left != NULL) {
                pre = cur->left;
                while (pre->right != NULL) {
                    pre = pre->right;
                }
                pre->right = cur->right;
                cur->right = cur->left;
            }
            cur->left = NULL;
            cur = cur->right;
        }
    }
};
