// Recursive solution
#include <algorithm>
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
     * @param root: a TreeNode, the root of the binary tree
     * @return: nothing
     */
    void flatten(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        
        TreeNode *left, *right;
        preorder(root, left, right);
    }
private:
    void preorder(TreeNode *root, TreeNode *&left, TreeNode *&right) {
        left = right = root;
        
        TreeNode *ll, *lr, *rl, *rr;
        if (root->left != NULL) {
            preorder(root->left, ll, lr);
        } else {
            ll = lr = NULL;
        }
        
        if (root->right != NULL) {
            preorder(root->right, rl, rr);
        } else {
            rl = rr = NULL;
        }
        
        left->left = NULL;
        if (ll != NULL) {
            right->right = ll;
            right = lr;
        }
        if (rl != NULL) {
            right->right = rl;
            right = rr;
        }
    }
};
