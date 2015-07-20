# This solution is credited to EroicaCMCS in 1point3acres
class Solution:
    # @param k & n  two integer
    # @return ans a integer
    def digitCounts(self, k, n):
        ans, b = 0, 1
        while b <= n:
            q, r = n / b, n % b
            ans += (q + 9 - k) / 10 * b
            if q % 10 == k:
                ans += r + 1
            b *= 10
        return ans
        