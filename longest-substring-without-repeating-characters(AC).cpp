#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param s: a string
     * @return: an integer 
     */
    int lengthOfLongestSubstring(string s) {
        int c[256];
        int n = s.length();
        int i, j;
        int ans = 0;
        
        memset(c, 0, sizeof(c));
        i = j = 0;
        while (j < n) {
            if (c[s[j]]) {
                while (c[s[j]]) {
                    --c[s[i++]];
                }
                c[s[j]] = 1;
            } else {
                c[s[j]] = 1;
                ans = max(ans, j - i + 1);
            }
            ++j;
        }
        return ans;
    }
};