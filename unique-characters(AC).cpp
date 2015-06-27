#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        char a[256];
        memset(a, 0, sizeof(a));
        int n = str.length();
        int i;
        for (i = 0; i < n; ++i) {
            if (a[str[i]]) {
                return false;
            }
            a[str[i]] = 1;
        }
        return true;
    }
};