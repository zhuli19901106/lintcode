// O(k * n) DP with O(n) space, yes!
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        vector<int> &a = nums;
        int n = a.size();
        if (k <= 0 || k > n) {
            return 0;
        }
        vector<vector<int> > dp(2, vector<int>(n, 0));
        vector<int> mx(n, 0);
        int i, j;
        int f, nf;
        
        mx[0] = dp[0][0] = a[0];
        for (i = 1; i < n; ++i) {
            dp[0][i] = max(dp[0][i - 1], 0) + a[i];
        }
        mx[0] = dp[0][0];
        for (i = 1; i < n; ++i) {
            mx[i] = max(mx[i - 1], dp[0][i]);
        }
        
        f = 1;
        nf = !f;
        for (i = 1; i < k; ++i) {
            dp[f][i] = dp[nf][i - 1] + a[i];
            for (j = i + 1; j < n; ++j) {
                dp[f][j] = max(dp[f][j - 1], mx[j - 1]) + a[j];
            }
            mx[i] = dp[f][i];
            for (j = i + 1; j < n; ++j) {
                mx[j] = max(mx[j - 1], dp[f][j]);
            }
            f = !f;
            nf = !f;
        }
        return mx[n - 1];
    }
};