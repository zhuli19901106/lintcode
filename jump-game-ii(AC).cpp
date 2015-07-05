class Solution {
public:
    /**
     * @param A: A list of lists of integers
     * @return: An integer
     */
    int jump(vector<int> A) {
        int n = A.size();
        if (n == 0) {
            return 0;
        }
        int i;
        int r = 0;
        int ans = 0;
        for (i = 0; i < n; ++i) {
            if (i + A[i] <= r) {
                continue;
            }
            r = i + A[i];
            ++ans;
            if (r >= n - 1) {
                break;
            }
        }
        return ans;
    }
};