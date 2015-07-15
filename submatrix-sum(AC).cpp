// O(n ^ 4) solution
class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int> > submatrixSum(vector<vector<int> > &matrix) {
        vector<vector<int> > &a = matrix;
        int n, m;
        n = a.size();
        m = n ? a[0].size() : 0;
        vector<vector<int> > ans(2, vector<int>(2));
        vector<vector<int> > s(n + 1, vector<int>(m + 1, 0));
        int i, j;
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= m; ++j) {
                s[i][j] = s[i - 1][j] + s[i][j - 1] + a[i - 1][j - 1] - s[i - 1][j - 1];
            }
        }
        int i1, j1;
        int sum;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                for (i1 = i + 1; i1 <= n; ++i1) {
                    for (j1 = j + 1; j1 <= m; ++j1) {
                        sum = 0;
                        sum += s[i][j] + s[i1][j1];
                        sum -= s[i][j1] + s[i1][j];
                        if (sum != 0) {
                            continue;
                        }
                        ans[0][0] = i;
                        ans[0][1] = j;
                        ans[1][0] = i1 - 1;
                        ans[1][1] = j1 - 1;
                        return ans;
                    }
                }
            }
        }
        return ans;
    }
};