#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        v.clear();
        dl.clear();
        dr.clear();
        
        n = matrix.size();
        if (n == 0) {
            return 0;
        }
        m = matrix[0].size();
        if (m == 0) {
            return 0;
        }
        v.resize(m, 0);
        dl.resize(m);
        dr.resize(m);
        int i, j;
        int ans = 0;
        for (i = 0; i < n; ++i) {
            for (j = 0; j < m; ++j) {
                v[j] = matrix[i][j] ? v[j] + matrix[i][j] : 0;
            }
            ans = max(ans, largestHistogram());
        }
        return ans;
    }
private:
    vector<int> v;
    vector<int> dl, dr;
    int n, m;
    
    int largestHistogram() {
        int i;
        for (i = 0; i <= m - 1; ++i) {
            dl[i] = dr[i] = i;
        }
        for (i = 1; i <= m - 1; ++i) {
            while (dl[i] - 1 >= 0 && v[dl[i] - 1] >= v[i]) {
                dl[i] = dl[dl[i] - 1];
            }
        }
        for (i = m - 2; i >= 0; --i) {
            while (dr[i] + 1 <= m - 1 && v[dr[i] + 1] >= v[i]) {
                dr[i] = dr[dr[i] + 1];
            }
        }
        int ans = 0;
        int len;
        for (i = 0; i <= m - 1; ++i) {
            len = min(v[i], dr[i] - dl[i] + 1);
            ans = max(ans, len * len);
        }
        return ans;
    }
};