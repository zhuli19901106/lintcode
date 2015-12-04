#include <string>
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
     * @param root the root of the binary tree
     * @return all root-to-leaf paths
     */
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == NULL) {
            return ans;
        }
        vector<int> path;
        
        path.push_back(root->val);
        DFS(root, path, ans);
        path.pop_back();
        
        return ans;
    }
protected:
    void DFS(TreeNode *root, vector<int> &path, vector<string> &ans) {
        if (root->left == NULL && root->right == NULL) {
            string s = to_string(path[0]);
            for (int i = 1; i < path.size(); ++i) {
                s += "->" + to_string(path[i]);
            }
            ans.push_back(s);
            return;
        }
        
        if (root->left != NULL) {
            path.push_back(root->left->val);
            DFS(root->left, path, ans);
            path.pop_back();
        }
        
        if (root->right != NULL) {
            path.push_back(root->right->val);
            DFS(root->right, path, ans);
            path.pop_back();
        }
    }
};
