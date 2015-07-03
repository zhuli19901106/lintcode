// Space optimized to O(n)
class Solution {
public:    
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
        int la = A.size();
        int lb = B.size();
        if (la == 0 || lb == 0) {
            return 0;
        }
        
        vector<vector<int> > dp;
        dp.resize(2, vector<int>(lb + 1, 0));
        int i, j;
        int ans = 0;
        int f = 1;
        int nf = !f;
        for (i = 1; i <= la; ++i) {
            for (j = 1; j <= lb; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[f][j] = dp[nf][j - 1] + 1;
                } else {
                    dp[f][j] = 0;
                }
                ans = max(ans, dp[f][j]);
            }
            f = !f;
            nf = !f;
        }
        return ans;
    }
};