class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
        if (n == 0) {
            return 1 % b;
        }
        if (n == 1) {
            return a % b;
        }
        int s = fastPower(a, b, n >> 1);
        if (n & 1) {
            return 1LL * s * s % b * a % b;
        } else {
            return 1LL * s * s % b;
        }
    }
};