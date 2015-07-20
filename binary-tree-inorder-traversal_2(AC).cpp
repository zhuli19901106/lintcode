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
    /**
     * @param root: The root of binary tree.
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        stack<TreeNode *> st;
        TreeNode *p;
        p = root;
        while (true) {
            while (p != NULL) {
                st.push(p);
                p = p->left;
            }
            while (!st.empty() && st.top()->right == NULL) {
                ans.push_back(st.top()->val);
                st.pop();
            }
            if (st.empty()) {
                break;
            }
            p = st.top()->right;
            ans.push_back(st.top()->val);
            st.pop();
        }
        return ans;
    }
};