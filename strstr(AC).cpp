// The brute-force solution.
#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
    int strStr(const char *source, const char *target) {
        if (source == NULL || target == NULL) {
            return -1;
        }
        int ls = strlen(source);
        int lt = strlen(target);
        
        if (lt > ls) {
            return -1;
        }
        
        int i, j;
        for (i = 0; i + lt <= ls; ++i) {
            for (j = 0; j < lt; ++j) {
                if (source[i + j] != target[j]) {
                    break;
                }
            }
            if (j == lt) {
                return i;
            }
        }
        
        return -1;
    }
};