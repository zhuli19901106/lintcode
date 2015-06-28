#include <climits>
using namespace std;

typedef long long int LL;

class Solution {
public:
    /**
     * @param dividend the dividend
     * @param divisor the divisor
     * @return the result
     */
    int divide(int dividend, int divisor) {
        LL f = 1;
        LL a = dividend;
        LL b = divisor;
        LL base;
        
        if (a == 0) {
            return 0;
        }
        
        if (a < 0) {
            a = -a;
            f = -f;
        }
        if (b < 0) {
            b = -b;
            f = -f;
        }
        
        LL b2;
        base = b;
        b2 = 1;
        while ((base << 1) <= a) {
            base <<= 1;
            b2 <<= 1;
        }
        LL ans = 0;
        while (base >= b) {
            if (a >= base) {
                a -= base;
                ans += b2;
            }
            base >>= 1;
            b2 >>= 1;
        }
        ans *= f;
        if (ans < INT_MIN || ans > INT_MAX) {
            ans = INT_MAX;
        }
        return ans;
    }
};