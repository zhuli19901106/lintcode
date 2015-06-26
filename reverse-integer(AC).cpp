#include <climits>
using namespace std;

typedef long long int LL;

class Solution {
public:
    /**
     * @param n the integer to be reversed
     * @return the reversed integer
     */
    int reverseInteger(int n) {
		if (n == 0) {
			return 0;
		}
		
		LL ans;
		int sign = n > 0 ? 1 : -1;
		
		ans = 0;
		if (n < 0) {
			n = -n;
		}
		while (n != 0) {
			ans = ans * 10 + n % 10;
			n /= 10;
		}
		ans *= sign;
		if (ans > INT_MAX || ans < INT_MIN) {
			return 0;
		}
		return ans;
    }
};