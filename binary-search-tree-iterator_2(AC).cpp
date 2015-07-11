// O(h) time and O(1) space
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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        this->root = root;
        if (root == NULL) {
            cur = NULL;
            return;
        }
        cur = root;
        while (cur->left != NULL) {
            cur = cur->left;
        }
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        return cur != NULL;
    }
    
    //@return: return next node
    TreeNode* next() {
        TreeNode *ans = cur;
        if (cur->right != NULL) {
            cur = cur->right;
            while (cur->left != NULL) {
                cur = cur->left;
            }
            return ans;
        }
        
        TreeNode *p1 = root;
        TreeNode *p2 = NULL;
        while (p1->val != cur->val) {
            if (cur->val < p1->val) {
                p2 = p1;
                p1 = p1->left;
            } else {
                p1 = p1->right;
            }
        }
        cur = p2;
        return ans;
    }
private:
    TreeNode *root, *cur;
};