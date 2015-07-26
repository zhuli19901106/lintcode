#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<vector<int> > &a = triangle;
        int n = a.size();
        if (n == 0) {
            return 0;
        }
        
        int i, j;
        for (i = 1; i < n; ++i) {
            a[i][0] += a[i - 1][0];
            for (j = 1; j < i; ++j) {
                a[i][j] += min(a[i - 1][j - 1], a[i - 1][j]);
            }
            a[i][i] += a[i - 1][i - 1];
        }
        int ans = a[n - 1][0];
        for (i = 1; i < n; ++i) {
            ans = min(ans, a[n - 1][i]);
        }
        return ans;
    }
};