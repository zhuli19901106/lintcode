// The brute-force solution
class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        string ans = "";
        int n = s.length();
        if (n == 0) {
            return ans;
        }
        ans.push_back(s[0]);
        
        int maxlen = 1;
        int i, j;
        for (i = 0; i <= n - 1; ++i) {
            j = 1;
            while (i - j >= 0 && i + j <= n - 1 && s[i - j] == s[i + j]) {
                ++j;
            }
            --j;
            if (2 * j + 1 > maxlen) {
                maxlen = 2 * j + 1;
                ans = s.substr(i - j, 2 * j + 1);
            }
        }
        for (i = 0; i <= n - 1; ++i) {
            j = 0;
            while (i - j >= 0 && i + 1 + j <= n - 1 && s[i - j] == s[i + 1 + j]) {
                ++j;
            }
            --j;
            if (2 * j + 2 > maxlen) {
                maxlen = 2 * j + 2;
                ans = s.substr(i - j, 2 * j + 2);
            }
        }
        return ans;
    }
};