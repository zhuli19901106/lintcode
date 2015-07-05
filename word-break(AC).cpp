#include <algorithm>
using namespace std;

typedef unordered_set<string> uss;
class Solution {
public:
    /**
     * @param s: A string s
     * @param dict: A dictionary of words dict
     */
    bool wordBreak(string s, uss &dict) {
        int n = s.length();
        if (n == 0) {
            return true;
        }
        vector<bool> dp(n + 1, false);
        int maxlen = 0;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            maxlen = max(maxlen, (int)it->length());
        }
        
        int i, j;
        dp[0] = true;
        for (i = 1; i <= n; ++i) {
            for (j = i - 1; j >= 0; --j) {
                if (i - j > maxlen) {
                    break;
                }
                if (dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};