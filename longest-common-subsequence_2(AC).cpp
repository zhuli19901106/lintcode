// Space optimized to O(n)
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param A, B: Two strings.
     * @return: The length of longest common subsequence of A and B.
     */
    int longestCommonSubsequence(string A, string B) {
        int la = A.length();
        int lb = B.length();
        if (la == 0 || lb == 0) {
            return 0;
        }
        vector<vector<int> > dp;
        dp.resize(2, vector<int>(lb + 1, 0));
        
        int i, j;
        int f, nf;
        
        f = 1;
        nf = !f;
        for (i = 1; i <= la; ++i) {
            dp[f][0] = 0;
            for (j = 1; j <= lb; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[f][j] = dp[nf][j - 1] + 1;
                } else {
                    dp[f][j] = max(dp[f][j - 1], dp[nf][j]);
                }
            }
            f = !f;
            nf = !f;
        }
        return dp[nf][lb];
    }
};