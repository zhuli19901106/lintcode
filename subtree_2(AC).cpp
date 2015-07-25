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
     * @param T1, T2: The roots of binary tree.
     * @return: True if T2 is a subtree of T1, or false.
     */
    bool isSubtree(TreeNode *T1, TreeNode *T2) {
        height.clear();
        height[NULL] = 0;
        calcHeight(T1);
        calcHeight(T2);
        return subtree(T1, T2);
    }
private:
    unordered_map<TreeNode *, int> height;
    
    bool subtree(TreeNode *T1, TreeNode *T2) {
        if (sameTree(T1, T2)) {
            return true;
        }
        if (T1 == NULL) {
            return false;
        }
        return subtree(T1->left, T2) || subtree(T1->right, T2);
    }
    
    void calcHeight(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        calcHeight(root->left);
        calcHeight(root->right);
        height[root] = max(height[root->left], height[root->right]) + 1;
    }
    
    bool sameTree(TreeNode *r1, TreeNode *r2) {
        if (height[r1] != height[r2]) {
            // No need to go further
            return false;
        }
        if (r1 == NULL) {
            if (r2 == NULL) {
                return true;
            }
            return false;
        }
        if (r2 == NULL) {
            return false;
        }
        if (r1->val != r2->val) {
            return false;
        }
        return sameTree(r1->left, r2->left) && sameTree(r1->right, r2->right);
    }
};