#include <algorithm>
using namespace std;

class Solution {
public:
  /**
     * param A: A string
     * param offset: Rotate string with offset.
     * return: Rotated string.
     */
    string rotateString(string A, int offset) {
        if (A == "") {
            return A;
        }
        offset %= A.length();
        if (offset == 0) {
            return A;
        }
        reverse(A.begin(), A.begin() + A.length() - offset);
        reverse(A.begin() + A.length() - offset, A.end());
        reverse(A.begin(), A.end());
        return A;
    }
};