#include <cctype>
using namespace std;

class Solution {
public:
    /** 
     * @param chars: The letters array you should sort.
     */
    void sortLetters(string &letters) {
        string &s = letters;
        int n = s.length();
        int i = 0;
        int j = n - 1;
        while (true) {
            while (i <= j && islower(s[i])) {
                ++i;
            }
            while (i <= j && isupper(s[j])) {
                --j;
            }
            if (i >= j) {
                break;
            }
            swap(s[i++], s[j--]);
        }
    }
};