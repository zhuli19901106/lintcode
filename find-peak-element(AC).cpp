// The O(n) solution.
class Solution {
public:
    /**
     * @param A: An integers array.
     * @return: return any of peek positions.
     */
    int findPeak(vector<int> A) {
        for (i = 1; i < n - 1; ++i) {
            if (A[i] > A[i - 1] && A[i] > A[i + 1]) {
                return i;
            }
        }
        return -1;
    }
};