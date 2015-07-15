// O(log ^ 2(n)) solution, using RMQ
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
        
        st.clear();
        calcSparseTable(A);
        
        return maxTreeRecur(A, 0, A.size() - 1);
    }
private:
    // Needed for RMQ
    vector<vector<int> > st;
    
    TreeNode *maxTreeRecur(vector<int> &a, int ll, int rr) {
        if (ll > rr) {
            return NULL;
        }
        int i, mi;
        
        mi = RMQ(a, ll, rr);
        TreeNode *root = new TreeNode(a[mi]);
        root->left = maxTreeRecur(a, ll, mi - 1);
        root->right = maxTreeRecur(a, mi + 1, rr);
        return root;
    }
    
    void calcSparseTable(vector<int> &a) {
        int n = a.size();
        int b = 1;
        int m = 1;
        while (b << 1 <= n) {
            b <<= 1;
            ++m;
        }
        st.resize(m, vector<int>(n));
        int i;
        for (i = 0; i < n; ++i) {
            st[0][i] = i;
        }
        b = 1;
        int j;
        for (i = 1; i < m; ++i) {
            for (j = 0; j + (b << 1) <= n; ++j) {
                if (a[st[i - 1][j]] > a[st[i - 1][j + b]]) {
                    st[i][j] = st[i - 1][j];
                } else {
                    st[i][j] = st[i - 1][j + b];
                }
            }
            b <<= 1;
        }
    }
    
    int RMQ(vector<int> &a, int ll, int rr) {
        int b = 1;
        int i = 0;
        while (b << 1 <= rr - ll + 1) {
            b <<= 1;
            ++i;
        }
        if (a[st[i][ll]] > a[st[i][rr - b + 1]]) {
            return st[i][ll];
        } else {
            return st[i][rr - b + 1];
        }
    }
};