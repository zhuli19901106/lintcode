#include <algorithm>
using namespace std;

typedef long long int LL;

class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        return combination(m + n - 2, min(m, n) - 1);
    }
private:
	LL combination(int n, int k) {
		LL ans = 1;
		LL q = 1;
		int i;
		for (i = 1; i <= k; ++i) {
			ans *= n + 1 - i;
			q *= i;
			if (ans % q == 0) {
				ans /= q;
				q = 1;
			}
		}
		if (q > 1) {
			ans /= q;
			q = 1;
		}
		return ans;
	}
};