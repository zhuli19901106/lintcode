// The Manacher solution
// Man... that was really tough.
class Solution {
public:
    /**
     * @param s input string
     * @return the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        string ans = "";
        int n = s.length();
        if (n <= 1) {
            return s;
        }
        ans.push_back(s[0]);
        
        string ss;
        vector<int> r;
        alignStr(s, ss);
        r.resize(ss.length(), 1);
        
        int i, j;
        int mi, pos;
        
        mi = pos = r[0] = 0;
        for (i = 1; i < 2 * n; ++i) {
            r[i] = 1;
            if (pos > i) {
                // Within the palindromic radius
                // Possibly so
                r[i] = r[2 * mi - i];
                if (i + r[i] > pos) {
                    // Beyond the unknown
                    r[i] = pos - i;
                }
            }
            while (ss[i - r[i]] == ss[i + r[i]]) {
                ++r[i];
            }
            if (i + r[i] > pos) {
                pos = i + r[i];
                mi = i;
            }
        }
        
        int maxlen = 1;
        int len;
        string tmp;
        for (i = 1; i < 2 * n; ++i) {
            len = i % 2 ? (r[i] - 1) / 2 * 2 + 1 : r[i] / 2 * 2;
            if (len <= maxlen) {
                continue;
            }
            maxlen = len;
            tmp = "";
            if (i % 2) {
                for (j = i - (r[i] - 1) / 2 * 2; j <= i + (r[i] - 1) / 2 * 2; j += 2) {
                    tmp.push_back(ss[j]);
                }
            } else {
                for (j = i - r[i] / 2 * 2 + 1; j <= i + r[i] / 2 * 2 - 1; j += 2) {
                    tmp.push_back(ss[j]);
                }
            }
            ans = tmp;
        }
        return ans;
    }
private:
    const char UNDEF1 = '\254';
    const char UNDEF2 = '\253';
    
    void alignStr(string &s, string &ss) {
        ss.clear();
        ss.push_back(UNDEF2);
        int n = s.length();
        int i;
        
        for (i = 0; i < n; ++i) {
            ss.push_back(s[i]);
            ss.push_back(UNDEF1);
        }
        ss[2 * n] = 0;
    }
};