// The iterative version
#include <stack>
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
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        
        stack<TreeNode *> st;
        TreeNode *p;
        p = root;
        while (true) {
            while (p != NULL) {
                ans.push_back(p->val);
                st.push(p);
                p = p->left;
            }
            while (!st.empty() && st.top()->right == NULL) {
                st.pop();
            }
            if (st.empty()) {
                break;
            }
            p = st.top()->right;
            st.pop();
        }
        return ans;
    }
};