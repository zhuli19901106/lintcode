// The KMP solution.
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
        if (target[0] == 0) {
            return 0;
        }
        
        ls = strlen(source);
        lt = strlen(target);
        s = source;
        t = target;
        
        if (lt > ls) {
            return -1;
        }
        
        next = new int[lt + 1];
        memset(next, 0, (lt + 1) * sizeof(int));
        getNext();
        
        int ans = KMPMatch();
        delete[] next;
        
        return ans;
    }
private:
    int* next;
    int ls;
    int lt;
    const char *s;
    const char *t;
    
    void getNext() {
        int i, j;
        i = 0;
        j = -1;
        
        next[0] = -1;
        while (i < lt) {
            if (j == -1 || t[i] == t[j]) {
                ++i;
                ++j;
                next[i] = j;
            } else {
                j = next[j];
            }
        }
    }
    
    int KMPMatch() {
        int i, j;
        
        i = j = 0;
        while (i < ls) {
            if (j == -1 || s[i] == t[j]) {
                ++i;
                ++j;
            } else {
                j = next[j];
            }
            if (j == lt) {
                return i - lt;
            }
        }
        return -1;
    }
};