#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param grid: a list of lists of integers.
     * @return: An integer, minimizes the sum of all numbers along its path
     */
    int minPathSum(vector<vector<int> > &grid) {
        vector<vector<int> > &a = grid;
        int n, m;
        n = a.size();
        if (n == 0) {
            return 0;
        }
        m = a[0].size();
        if (m == 0) {
            return 0;
        }
        int i, j;
        
        for (i = 1; i < n; ++i) {
            a[i][0] += a[i - 1][0];
        }
        for (i = 1; i < m; ++i) {
            a[0][i] += a[0][i - 1];
        }
        for (i = 1; i < n; ++i) {
            for (j = 1; j < m; ++j) {
                a[i][j] += min(a[i][j - 1], a[i - 1][j]);
            }
        }
        return a[n - 1][m - 1];
    }
};