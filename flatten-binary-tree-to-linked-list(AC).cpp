// The straight-forward solution
#include <vector>
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
        
        vector<TreeNode *> pre;
        preorder(root, pre);
        
        int n = pre.size();
        pre.push_back(NULL);
        int i;
        for (i = 0; i < n; ++i) {
            pre[i]->left = NULL;
            pre[i]->right = pre[i + 1];
        }
    }
private:
    void preorder(TreeNode *root, vector<TreeNode *> &pre) {
        if (root == NULL) {
            return;
        }
        pre.push_back(root);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
};
