class Solution {
public:
    /**    
     * @param A: a vector of integers
     * @return: an integer
     */
    int firstMissingPositive(vector<int> A) {
        int n = A.size();
        if (n == 0) {
            return 1;
        }
        
        int i;
        for (i = 0; i < n; ++i) {
            if (A[i] <= 0 || A[i] > n) {
                A[i] = n + 1;
            }
        }
        for (i = 0; i < n; ++i) {
            if (abs(A[i]) > n) {
                continue;
            } else if (A[abs(A[i]) - 1] > 0) {
                A[abs(A[i]) - 1] *= -1;
            }
        }
        for (i = 0; i < n; ++i) {
            if (A[i] > 0) {
                return i + 1;
            }
        }
        return n + 1;
    }
private:
    int abs(int x) {
        return x >= 0 ? x : -x;
    }
};