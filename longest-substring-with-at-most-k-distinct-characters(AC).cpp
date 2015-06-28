#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param s : A string
     * @return : The length of the longest substring 
     *           that contains at most k distinct characters.
     */
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int c[256];
        int n = s.length();
        
        if (n == 0 || k == 0) {
            return 0;
        }
        
        int ans = 0;
        memset(c, 0, sizeof(c));
        int cc = 0;
        int i, j;
        i = j = 0;
        while (j < n) {
            if (c[s[j]] == 0) {
                ++cc;
            }
            ++c[s[j]];
            if (cc <= k) {
                ans = max(ans, j - i + 1);
                ++j;
                continue;
            }
            while (cc > k) {
                --c[s[i]];
                if (c[s[i]] == 0) {
                    --cc;
                }
                ++i;
            }
            ++j;
        }
        return ans;
    }
};