// O(n ^ 2) solution with DP
#include <vector>
using namespace std;

class Solution {
public:    
    /**
     * @param S, T: Two string.
     * @return: Count the number of distinct subsequences
     */
    int numDistinct(string &S, string &T) {
        int n = S.length();
        int m = T.length();
        vector<vector<int> > dp;
        
        dp.resize(n + 1, vector<int>(m + 1, 1));
        int i, j;
        
        for (j = 1; j <= m; ++j) {
            dp[0][j] = 0;
        }
        for (i = 1; i <= n; ++i) {
            for (j = 1; j <= m; ++j) {
                if (S[i - 1] == T[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};