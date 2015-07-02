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
    /**
     * @param root : The root of binary tree.
     * @return : buttom-up level order a list of lists of integer
     */
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        if (root == NULL) {
            return ans;
        }
        maxDepth = 0;
        calcDepth(root, 1);
        ans.resize(maxDepth);
        preorder(root, 0);
        return ans;
    }
private:
    vector<vector<int> > ans;
    int maxDepth;
    
    void calcDepth(TreeNode *root, int depth) {
        maxDepth = max(maxDepth, depth);
        if (root->left != NULL) {
            calcDepth(root->left, depth + 1);
        }
        if (root->right != NULL) {
            calcDepth(root->right, depth + 1);
        }
    }
    
    void preorder(TreeNode *root, int depth) {
        ans[maxDepth - 1 - depth].push_back(root->val);
        if (root->left != NULL) {
            preorder(root->left, depth + 1);
        }
        if (root->right != NULL) {
            preorder(root->right, depth + 1);
        }
    }
};