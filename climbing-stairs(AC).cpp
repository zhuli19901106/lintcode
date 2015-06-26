class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
        if (n < 2) {
            return 1;
        }
        int a1, a2, a3;
        a1 = a2 = 1;
        int i;
        for (i = 2; i <= n; ++i) {
            a3 = a1 + a2;
            a1 = a2;
            a2 = a3;
        }
        return a3;
    }
};