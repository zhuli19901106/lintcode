#include <unordered_map>
using namespace std;
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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        um.clear();
        if (root == NULL) {
            return true;
        }
        um[NULL] = 0;
        height(root);
        return balance(root);
    }
private:
    unordered_map<TreeNode *, int> um;
    
    int height(TreeNode *root) {
        if (root == NULL) {
            return 0;
        }
        return um[root] = max(height(root->left), height(root->right)) + 1;
    }
    
    bool balance(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        return balance(root->left) && balance(root->right) && 
               abs(um[root->left] - um[root->right]) <= 1;
    }
};