#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:    
    /**
     * @param word1 & word2: Two string.
     * @return: The minimum number of steps.
     */
    int minDistance(string word1, string word2) {
        int n1 = word1.length();
        int n2 = word2.length();
        vector<vector<int> > dp;
        int i, j;
        int f, nf;
        dp.resize(2, vector<int>(n2 + 1));
        
        for (j = 1; j <= n2; ++j) {
            dp[0][j] = j;
        }
        f = 1;
        nf = !f;
        for (i = 1; i <= n1; ++i) {
            dp[f][0] = i;
            for (j = 1; j <= n2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[f][j] = dp[nf][j - 1];
                } else {
                    dp[f][j] = min(dp[nf][j], dp[f][j - 1]);
                    dp[f][j] = min(dp[f][j], dp[nf][j - 1]) + 1;
                }
            }
            f = !f;
            nf = !f;
        }
        return dp[nf][n2];
    }
};