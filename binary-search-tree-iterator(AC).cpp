// O(1) with hashing, which requires O(n) time for preprocessing
#include <unordered_map>
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
        if (root == NULL) {
            cur = NULL;
            return;
        }
        
        vector<TreeNode *> v;
        
        inorder(root, v);
        int n = v.size();
        int i;
        for (i = 1; i < n; ++i) {
            nextNode[v[i - 1]] = v[i];
        }
        nextNode[v[n - 1]] = NULL;
        cur = v[0];
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        return cur != NULL;
    }
    
    //@return: return next node
    TreeNode* next() {
        TreeNode *ptr = cur;
        cur = nextNode[cur];
        return ptr;
    }
    
    ~Solution() {
        nextNode.clear();
    }
private:
    unordered_map<TreeNode *, TreeNode *> nextNode;
    TreeNode *cur;
    
    void inorder(TreeNode *root, vector<TreeNode *> &v) {
        if (root == NULL) {
            return;
        }
        inorder(root->left, v);
        v.push_back(root);
        inorder(root->right, v);
    }
};