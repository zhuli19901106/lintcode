// O(n ^ 4) solution using DP
class Solution {
public:
    /**
     * @param s1 A string
     * @param s2 Another string
     * @return whether s2 is a scrambled string of s1
     */
    bool isScramble(string &s1, string &s2) {
        int n = s1.length();
        if (n != s2.length()) {
            return false;
        }
        if (s1 == s2) {
            return true;
        }
        
        int i, j, k, ii;
        vector<vector<vector<bool> > > dp(n, vector<vector<bool> >(n, vector<bool>(n, false)));
        for (i = 0; i < n; ++i) {
            for (j = 0; j < n; ++j) {
                dp[0][i][j] = s1[i] == s2[j];
            }
        }
        for (i = 1; i < n; ++i) {
            for (j = 0; j + i < n; ++j) {
                for (k = 0; k + i< n; ++k) {
                    for (ii = 0; ii < i; ++ii) {
                        if (dp[ii][j][k] && dp[i - ii - 1][j + ii + 1][k + ii + 1]) {
                            dp[i][j][k] = true;
                        }
                        if (dp[ii][j][k + i - ii] && dp[i - ii - 1][j + ii + 1][k]) {
                            dp[i][j][k] = true;
                        }
                    }
                }
            }
        }
        return dp[n - 1][0][0];
    }
};