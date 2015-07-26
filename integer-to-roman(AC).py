class Solution:
    # @param {int} n The integer
    # @return {string} Roman representation
    def intToRoman(self, n):
        # Write your code here
        m = {}
        m[1] = 'I'
        m[5] = 'V'
        m[10] = 'X'
        m[50] = 'L'
        m[100] = 'C'
        m[500] = 'D'
        m[1000] = 'M'
        b = 1
        while b < 1000:
            for i in xrange(2, 4):
                m[i * b] = m[(i - 1) * b] + m[b]
            m[4 * b] = m[b] + m[5 * b]
            for i in xrange(6, 9):
                m[i * b] = m[(i - 1) * b] + m[b]
            m[9 * b] = m[b] + m[10 * b]
            b *= 10
        for i in xrange(2, 3):
            m[i * b] = m[(i - 1) * b] + m[b]
        ans = ''
        while b > 0:
            if n / b % 10 == 0:
                b /= 10
                continue
            ans += m[n / b % 10 * b]
            b /= 10
        return ans