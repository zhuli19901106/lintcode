typedef long long int LL;

class Solution {
public:
    Solution() {
        int i, j;
        LL b10;
        
        sum[0] = 0;
        sum[1] = 1;
        b10 = 1;
        for (i = 2; i < M; ++i) {
            b10 *= 10;
            sum[i] = 10 * sum[i - 1] + b10;
        }
        
        LL ss;

        sum0[0] = 0;
        sum0[1] = 0;
        b10 = 1;
        for (i = 2; i < M; ++i) {
            b10 *= 10;
            ss = 0;
            for (j = 1; j < i; ++j) {
                ss += sum0[j];
            }
            sum0[i] = 9 * (leadingZero(b10 - 1, i - 1) + ss);
        }
    }
    /*
     * param k : As description.
     * param n : As description.
     * return: How many k's between 0 and n.
     */
    int digitCounts(int k, int n) {
        if (k == 0) {
            return countZero(n) + 1;
        }
        return countDigit(n, k);
    }
private:
    static const int M = 19;
    LL sum[M];
    LL sum0[M];
    
    LL countDigit(LL x, int d) {
        LL b10;
        int idx;

        if (x < d) {
            return 0;
        } else if (x < 10) {
            return 1;
        }

        b10 = 1;
        idx = 0;
        while (b10 * 10 <= x) {
            b10 *= 10;
            ++idx;
        }
        if (x / b10 > d) {
            return (x / b10) * sum[idx] + b10 + countDigit(x % b10, d);
        } else if (x / b10 == d) {
            return (x / b10) * sum[idx] + (x % b10 + 1) + countDigit(x % b10, d);
        } else {
            return (x / b10) * sum[idx] + countDigit(x % b10, d);
        }
    }
    
    LL leadingZero(LL x, int idx) {
        LL b10 = 1;
        LL sum = idx;
        int bi = 1;
        while (b10 * 10 <= x) {
            sum += 9 * b10 * (idx - bi);
            b10 *= 10;
            ++bi;
        }
        sum += (x - b10 + 1) * (idx - bi);
        return sum;
    }
    
    LL countZero(LL x) {
        LL b10;
        int idx;
        
        if (x < 10) {
            return 0;
        }

        b10 = 1;
        idx = 0;
        while (b10 * 10 <= x) {
            b10 *= 10;
            ++idx;
        }

        LL ans = 0;
        LL ss = 0;
        int i;

        for (i = 1; i <= idx; ++i) {
            ans += sum0[i];
            ss += sum0[i];
        }
        ans += (x / b10 - 1) * (ss + leadingZero(b10 - 1, idx));
        ans += leadingZero(x % b10, idx) + countZero(x % b10);

        return ans;
    }
};