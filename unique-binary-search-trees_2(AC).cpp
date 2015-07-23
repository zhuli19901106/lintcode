typedef long long int LL;
class Solution {
public:
    /**
     * @paramn n: An integer
     * @return: An integer
     */
    int numTrees(int n) {
        return C(2 * n, n) / (n + 1);
    }
private:
    LL C(int n, int k) {
        LL sum = 1;
        int i;
        LL q = 1;
        for (i = 1; i <= k; ++i) {
            sum *= n + 1 - i;
            q *= i;
            if (sum % q == 0) {
                sum /= q;
                q = 1;
            }
        }
        return sum;
    }
};