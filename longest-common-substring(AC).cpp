class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int la = A.size();
        int lb = B.size();
        vector<vector<int> > dp;
        dp.resize(la + 1, vector<int>(lb + 1, 0));
        int i, j;
        int ans = 0;
        for (i = 1; i <= la; ++i) {
            for (j = 1; j <= lb; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};