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
        dp.resize(n1 + 1, vector<int>(n2 + 1));
        
        for (i = 1; i <= n1; ++i) {
            dp[i][0] = i;
        }
        for (j = 1; j <= n2; ++j) {
            dp[0][j] = j;
        }
        for (i = 1; i <= n1; ++i) {
            for (j = 1; j <= n2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = dp[i - 1][j - 1];
                    dp[i][j] = min(dp[i][j], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                }
            }
        }
        return dp[n1][n2];
    }
};