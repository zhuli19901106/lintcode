#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
        sort(str.begin(), str.end());
        int n = str.length();
        int i;
        for (i = 0; i < n - 1; ++i) {
            if (str[i] == str[i + 1]) {
                return false;
            }
        }
        return true;
    }
};