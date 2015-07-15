// Cartesian Tree, make it O(n)
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
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        int n = A.size();
        if (n == 0) {
            return NULL;
        }
        stack<TreeNode *> st;
        TreeNode *p, *p1, *p2;
        int i;
        for (i = 0; i < n; ++i) {
            p = new TreeNode(A[i]);
            if (!st.empty() && A[i] > st.top()->val) {
                p1 = st.top();
                st.pop();
                while (!st.empty() && A[i] > st.top()->val) {
                    p2 = st.top();
                    st.pop();
                    p2->right = p1;
                    p1 = p2;
                }
                p->left = p1;
            }
            st.push(p);
        }
        
        TreeNode *r = st.top();
        st.pop();
        while (!st.empty()) {
            st.top()->right = r;
            r = st.top();
            st.pop();
        }
        return r;
    }
};