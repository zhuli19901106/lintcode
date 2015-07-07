// Space optimized to O(n)
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
        
        dp.resize(2, vector<int>(m + 1));
        int i, j;
        int f, nf;
        
        dp[0][0] = 1;
        for (j = 1; j <= m; ++j) {
            dp[0][j] = 0;
        }
        f = 1;
        nf = !f;
        for (i = 1; i <= n; ++i) {
            dp[f][0] = 1;
            for (j = 1; j <= m; ++j) {
                if (S[i - 1] == T[j - 1]) {
                    dp[f][j] = dp[nf][j - 1] + dp[nf][j];
                } else {
                    dp[f][j] = dp[nf][j];
                }
            }
            f = !f;
            nf = !f;
        }
        return dp[nf][m];
    }
};