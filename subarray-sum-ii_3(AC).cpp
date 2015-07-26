// O(n) solution
class Solution {
public:
    /**
     * @param A an integer array
     * @param start an integer
     * @param end an integer
     * @return the number of possible answer
     */
    int subarraySumII(vector<int> &A, int start, int end) {
        int n = A.size();
        if (n == 0) {
            return 0;
        }
        int i, j, k;
        j = k = 0;
        vector<int> S(n + 1, 0);
        for (i = 0; i < n; ++i) {
            S[i + 1] = S[i] + A[i];
        }
        
        int ans = 0;
        j = k = 1;
        for (i = 0; i < n; ++i) {
            while (j <= n && S[j] - S[i] < start) {
                ++j;
            }
            while (k <= n && S[k] - S[i] <= end) {
                ++k;
            }
            ans += k - j;
        }
        return ans;
    }
};