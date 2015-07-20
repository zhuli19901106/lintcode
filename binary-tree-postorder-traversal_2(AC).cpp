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
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ans;
        if (root == NULL) {
            return ans;
        }
        vector<TreeNode *> st;
        TreeNode *p = root, *oldp;
        while (true) {
            while (p != NULL) {
                st.push_back(p);
                p = p->left;
            }
            while (!st.empty() && st.back()->right == NULL) {
                ans.push_back(st.back()->val);
                oldp = st.back();
                st.pop_back();
            }
            while (!st.empty() && oldp == st.back()->right) {
                ans.push_back(st.back()->val);
                oldp = st.back();
                st.pop_back();
            }
            if (st.empty()) {
                break;
            }
            p = st.back()->right;
        }
        return ans;
    }
};