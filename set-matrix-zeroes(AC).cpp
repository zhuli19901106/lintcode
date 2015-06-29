class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @return: Void
     */
    void setZeroes(vector<vector<int> > &matrix) {
        vector<vector<int> > &a = matrix;
        int n, m;
        n = a.size();
        if (n == 0) {
            return;
        }
        m = a[0].size();
        if (m == 0) {
            return;
        }
        
        int i, j;
        int r0 = 1, c0 = 1;
        for (i = 0; i < n; ++i) {
            if (a[i][0] == 0) {
                c0 = 0;
                break;
            }
        }
        for (i = 0; i < m; ++i) {
            if (a[0][i] == 0) {
                r0 = 0;
                break;
            }
        }
        for (i = 1; i < n; ++i) {
            for (j = 1; j < m; ++j) {
                if (a[i][j] == 0) {
                    a[i][0] = 0;
                    a[0][j] = 0;
                }
            }
        }
        for (i = 1; i < n; ++i) {
            for (j = 1; j < m; ++j) {
                if (a[i][0] && a[0][j]) {
                    continue;
                }
                a[i][j] = 0;
            }
        }
        if (r0 == 0) {
            for (i = 0; i < m; ++i) {
                a[0][i] = 0;
            }
        }
        if (c0 == 0) {
            for (i = 0; i < n; ++i) {
                a[i][0] = 0;
            }
        }
    }
};