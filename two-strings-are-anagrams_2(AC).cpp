#include <cstring>
using namespace std;

class Solution {
public:
	/**
	 * @param s: The first string
	 * @param b: The second string
	 * @return true or false
	 */
	bool anagram(string s, string t) {
        int c[256];
        memset(c, 0, sizeof(c));
        int len = s.length();
        int i;
        for (i = 0; i < len; ++i) {
            ++c[s[i]];
        }
        len = t.length();
        for (i = 0; i < len; ++i) {
            --c[t[i]];
        }
        for (i = 0; i < 256; ++i) {
            if (c[i]) {
                return false;
            }
        }
		return true;
	}
};