#include <cstring>
using namespace std;

class Solution {
public:
    /**
     * @param A: A string includes Upper Case letters
     * @param B: A string includes Upper Case letter
     * @return:  if string A contains all of the characters in B return true 
     *           else return false
     */
    bool compareStrings(string A, string B) {
        int c[256];
        
        memset(c, 0, sizeof(c));
        int len = A.length();
        int i;
        for (i = 0; i < len; ++i) {
            ++c[A[i]];
        }
        len = B.length();
        for (i = 0; i < len; ++i) {
            --c[B[i]];
            if (c[B[i]] < 0) {
                return false;
            }
        }
        return true;
    }
};