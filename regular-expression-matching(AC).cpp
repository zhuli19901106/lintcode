#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        if (s == NULL || p == NULL) {
            return false;
        }
        int ls = strlen(s);
        int lp = strlen(p);
        if (lp == 0) {
            return ls == 0;
        }
        
        int i;
        for (i = 0; i < lp - 1; ++i) {
            if (p[i] == '*' && (i == 0 || p[i + 1] == '*')) {
                // Invalid pattern
                return false;
            }
        }
        
        vector<int> ai, aj;
        int j;
        
        i = j = 0;
        while (i < ls) {
            if (j + 1 < lp && p[j + 1] == '*') {
                ai.push_back(i);
                aj.push_back(j);
                j += 2;
            } else if (p[j] == '.' || s[i] == p[j]) {
                ++i;
                ++j;
            } else if (!aj.empty()) {
                while (!aj.empty()) {
                    if (p[aj.back()] == '.' || p[aj.back()] == s[ai.back()]) {
                        i = ++ai.back();
                        j = aj.back() + 2;
                        break;
                    }
                    ai.pop_back();
                    aj.pop_back();
                }
            } else {
                return false;
            }
        }
        while (j + 1 < lp && p[j + 1] == '*') {
            j += 2;
        }
        return j == lp;
    }
};