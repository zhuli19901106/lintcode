// You gotta ask before you code, all about the edge cases.
#include <climits>
using namespace std;

typedef long long int LL;
class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
        int n = str.length();
        LL val = 0;
        int f = 1;
        bool sign = false;
        bool digit = false;
        int i = 0;
        i = 0;
        while (i < n) {
            if (str[i] == '-') {
                if (digit || sign) {
                    break;
                }
                sign = true;
                f = -1;
            } else if (str[i] == '+') {
                if (digit || sign) {
                    break;
                }
                sign = true;
                f = 1;
            } else if (isdigit(str[i])) {
                digit = true;
                val = val * 10 + (str[i] - '0');
                if (f * val < INT_MIN) {
                    return INT_MIN;
                }
                if (f * val > INT_MAX) {
                    return INT_MAX;
                }
            } else if (str[i] != ' ') {
                break;
            }
            ++i;
        }
        return f * val;
    }
};