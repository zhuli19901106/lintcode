// O(n ^ 3) solution
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param matrix an integer matrix
     * @return the coordinate of the left-up and right-down number
     */
    vector<vector<int> > submatrixSum(vector<vector<int> > &matrix) {
        vector<vector<int> > &a = matrix;
        int n = a.size();
        int m = n ? a[0].size() : 0;
        vector<vector<int> > s(n + 1, vector<int>(m, 0));
        int i, j, k;
        unordered_map<int, int> um;
        
        for (i = 1; i <= n; ++i) {
            for (j = 0; j < m; ++j) {
                s[i][j] = s[i - 1][j] + a[i - 1][j];
            }
        }
        int sum;
        vector<vector<int> > ans(2, vector<int>(2));
        for (i = 0; i < n; ++i) {
            for (j = i + 1; j <= n; ++j) {
                um.clear();
                um[0] = -1;
                sum = 0;
                for (k = 0; k < m; ++k) {
                    sum += s[j][k] - s[i][k];
                    if (um.find(sum) != um.end()) {
                        ans[0][0] = i;
                        ans[0][1] = um[sum] + 1;
                        ans[1][0] = j - 1;
                        ans[1][1] = k;
                        return ans;
                    }
                    um[sum] = k;
                }
            }
        }
        return ans;
    }
};