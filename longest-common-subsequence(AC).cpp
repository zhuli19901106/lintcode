// O(n ^ 2) solution using DP
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
        dp.resize(la + 1, vector<int>(lb + 1, 0));
        
        int i, j;
        for (i = 1; i <= la; ++i) {
            for (j = 1; j <= lb; ++j) {
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        return dp[la][lb];
    }
};