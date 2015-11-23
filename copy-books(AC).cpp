// O(K * N) DP, think it over, carefully
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int copyBooks(vector<int> &pages, int k) {
        vector<int> &a = pages;
        vector<vector<int> > dp;
        int n = a.size();
        k = min(k, n);
        
        dp.resize(k, vector<int>(n, INT_MAX));
        int i, j, ki;
        int sum = 0;
        for (i = 0; i < n; ++i) {
            sum += a[i];
            dp[0][i] = sum;
        }
        
        for (ki = 1; ki < k; ++ki) {
            sum = 0;
            j = ki - 1;
            for (i = ki; i < n; ++i) {
                sum += a[i];
                dp[ki][i] = max(dp[ki - 1][j], sum);
                while (sum >= dp[ki - 1][j]) {
                    sum -= a[++j];
                    dp[ki][i] = min(dp[ki][i], max(dp[ki - 1][j], sum));
                }
            }
        }
        return dp[k - 1][n - 1];
    }
};