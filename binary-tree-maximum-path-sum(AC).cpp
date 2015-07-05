#include <algorithm>
#include <climits>
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
     * @return: An integer
     */
    int maxPathSum(TreeNode *root) {
        ans = INT_MIN;
        um.clear();
        if (root == NULL) {
            return ans;
        }
        um[NULL] = 0;
        singlePath(root);
        doublePath(root);
        return ans;
    }
private:
    int ans;
    unordered_map<TreeNode *, int> um;
    
    void singlePath(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        singlePath(root->left);
        singlePath(root->right);
        um[root] = max(um[root->left], um[root->right]) + root->val;
        um[root] = max(um[root], root->val);
    }
    
    void doublePath(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        ans = max(ans, um[root->left] + um[root->right] + root->val);
        ans = max(ans, root->val);
        doublePath(root->left);
        doublePath(root->right);
    }
};