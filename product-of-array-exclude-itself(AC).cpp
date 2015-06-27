typedef long long int LL;

class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<LL> productExcludeItself(vector<int> &nums) {
        vector<LL> sum;
        int n = nums.size();
        if (n == 0) {
            return sum;
        }
        sum.resize(n);
        
        int i;
        LL p = 1;
        for (i = 0; i <= n - 1; ++i) {
            sum[i] = p;
            p *= nums[i];
        }
        p = 1;
        for (i = n - 1; i >= 0; --i) {
            sum[i] *= p;
            p *= nums[i];
        }
        return sum;
    }
};