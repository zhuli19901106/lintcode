#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
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
        
        int i, j;
        int star_s, star_p;
        
        i = j = 0;
        star_s = star_p = -1;
        while (i < ls) {
            if (p[j] == '?' || s[i] == p[j]) {
                ++i;
                ++j;
            } else if (p[j] == '*') {
                star_p = j++;
                star_s = i;
            } else if (star_p != -1) {
                i = ++star_s;
                j = star_p + 1;
            } else {
                return false;
            }
        }
        while (j < lp && p[j] == '*') {
            ++j;
        }
        return j == lp;
    }
};